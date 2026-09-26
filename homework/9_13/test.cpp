// // test.cpp —— 针对 SSM.cpp（数组/顺序存储学生信息管理）的单元测试
// // 纯 assert 风格，自写 main，无需 GoogleTest / CMake。
// // 编译运行： g++ -g SSM.cpp test.cpp -o build\Debug\outDebug.exe && .\build\Debug\outDebug.exe
// #include "SSM.h"

// #include <math.h>
// #include <io.h>      // _dup / _dup2 / _fileno / _close
// #include <string.h>

// static int g_pass = 0;
// static int g_fail = 0;

// #define CHECK(cond)                                                   \
//     do {                                                              \
//         if (cond) {                                                   \
//             g_pass++;                                                 \
//         } else {                                                      \
//             g_fail++;                                                 \
//             printf("  FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond);  \
//         }                                                             \
//     } while (0)

// static int nearlyEqual(float a, float b) { return fabsf(a - b) < 1e-4f; }

// // ---------- 测试辅助：直接构造学生，避免依赖交互输入 ----------
// static struct Student makeStu(int num, const char* name, float s0, float s1, float s2)
// {
//     struct Student s;
//     s.num = num;
//     strcpy(s.name, name);
//     s.score[0] = s0;
//     s.score[1] = s1;
//     s.score[2] = s2;
//     s.aver = (s0 + s1 + s2) / 3.0f;
//     return s;
// }

// static void readFile(const char* path, char* buf, int cap)
// {
//     buf[0] = '\0';
//     FILE* f = fopen(path, "r");
//     if (f == NULL) {
//         return;
//     }
//     size_t n = fread(buf, 1, (size_t)(cap - 1), f);
//     buf[n] = '\0';
//     fclose(f);
// }

// // ============================ 测试用例 ============================

// // InPutStu：重定向 stdin 自动喂数据，验证字段、平均分与写入顺序。
// static void test_input(void)
// {
//     printf("[test_input]\n");
//     const char* inPath = "_ssm_in.txt";
//     FILE* f = fopen(inPath, "w");
//     if (f == NULL) {
//         CHECK(0 && "create input file failed");
//         return;
//     }
//     fprintf(f, "1 Alice 90 80 70\n");
//     fprintf(f, "2 Bob 60 70 80\n");
//     fprintf(f, "3 Cara 100 100 100\n");
//     fclose(f);

//     int savedIn = _dup(_fileno(stdin));
//     freopen(inPath, "r", stdin);

//     struct Student stu[N];
//     InPutStu(stu, N);

//     _dup2(savedIn, _fileno(stdin));
//     _close(savedIn);

//     CHECK(stu[0].num == 1);
//     CHECK(strcmp(stu[0].name, "Alice") == 0);
//     CHECK(nearlyEqual(stu[0].aver, 80.0f));

//     CHECK(stu[1].num == 2);
//     CHECK(strcmp(stu[1].name, "Bob") == 0);
//     CHECK(nearlyEqual(stu[1].aver, 70.0f));

//     CHECK(stu[2].num == 3);
//     CHECK(strcmp(stu[2].name, "Cara") == 0);
//     CHECK(nearlyEqual(stu[2].aver, 100.0f));

//     remove(inPath);
// }

// // MaxScore：最高平均分在中间时返回该学生。
// static void test_maxscore_middle(void)
// {
//     printf("[test_maxscore_middle]\n");
//     struct Student stu[3];
//     stu[0] = makeStu(1, "A", 60, 60, 60); // 60
//     stu[1] = makeStu(2, "B", 90, 90, 90); // 90
//     stu[2] = makeStu(3, "C", 70, 70, 70); // 70
//     struct Student m = MaxScore(stu, 3);
//     CHECK(m.num == 2);
//     CHECK(strcmp(m.name, "B") == 0);
// }

// // MaxScore：最高平均分在末尾时也能找到。
// static void test_maxscore_tail(void)
// {
//     printf("[test_maxscore_tail]\n");
//     struct Student stu[3];
//     stu[0] = makeStu(1, "A", 50, 50, 50); // 50
//     stu[1] = makeStu(2, "B", 60, 60, 60); // 60
//     stu[2] = makeStu(3, "C", 95, 96, 97); // 96
//     struct Student m = MaxScore(stu, 3);
//     CHECK(m.num == 3);
//     CHECK(nearlyEqual(m.aver, 96.0f));
// }

// // MaxScore：平均分并列时返回第一个（严格大于才更新）。
// static void test_maxscore_tie(void)
// {
//     printf("[test_maxscore_tie]\n");
//     struct Student stu[2];
//     stu[0] = makeStu(1, "A", 80, 80, 80); // 80
//     stu[1] = makeStu(2, "B", 80, 80, 80); // 80
//     struct Student m = MaxScore(stu, 2);
//     CHECK(m.num == 1);
// }

// // MaxScore：只有一个学生时返回该学生。
// static void test_maxscore_single(void)
// {
//     printf("[test_maxscore_single]\n");
//     struct Student stu[1];
//     stu[0] = makeStu(7, "Only", 60, 70, 80); // 70
//     struct Student m = MaxScore(stu, 1);
//     CHECK(m.num == 7);
//     CHECK(nearlyEqual(m.aver, 70.0f));
// }

// // PrtStu：捕获 stdout，验证打印内容包含学号、姓名与平均分。
// static void test_prtstu(void)
// {
//     printf("[test_prtstu]\n");
//     struct Student m = makeStu(2, "Bob", 60, 70, 80); // 70

//     const char* outPath = "_ssm_out.txt";
//     fflush(stdout);
//     int savedOut = _dup(_fileno(stdout));
//     freopen(outPath, "w", stdout);
//     PrtStu(m);
//     fflush(stdout);
//     _dup2(savedOut, _fileno(stdout));
//     _close(savedOut);

//     char buf[1024];
//     readFile(outPath, buf, sizeof(buf));
//     printf("  captured:\n%s", buf);

//     CHECK(strstr(buf, "num:2") != NULL);
//     CHECK(strstr(buf, "Bob") != NULL);
//     CHECK(strstr(buf, "70.00") != NULL);

//     remove(outPath);
// }

// // PrintAll：捕获 stdout，验证按数组顺序逐个打印全部学生。
// static void test_printall(void)
// {
//     printf("[test_printall]\n");
//     struct Student stu[3];
//     stu[0] = makeStu(1, "Alice", 90, 80, 70);   // 80
//     stu[1] = makeStu(2, "Bob", 60, 70, 80);     // 70
//     stu[2] = makeStu(3, "Cara", 100, 100, 100); // 100

//     const char* outPath = "_ssm_all.txt";
//     fflush(stdout);
//     int savedOut = _dup(_fileno(stdout));
//     freopen(outPath, "w", stdout);
//     PrintAll(stu, 3);
//     fflush(stdout);
//     _dup2(savedOut, _fileno(stdout));
//     _close(savedOut);

//     char buf[4096];
//     readFile(outPath, buf, sizeof(buf));
//     printf("  captured:\n%s", buf);

//     CHECK(strstr(buf, "[1] num:1") != NULL);
//     CHECK(strstr(buf, "Alice") != NULL);
//     CHECK(strstr(buf, "[2] num:2") != NULL);
//     CHECK(strstr(buf, "Bob") != NULL);
//     CHECK(strstr(buf, "[3] num:3") != NULL);
//     CHECK(strstr(buf, "Cara") != NULL);
//     CHECK(strstr(buf, "aver: 80.000000") != NULL);
//     CHECK(strstr(buf, "aver: 100.000000") != NULL);

//     // 顺序：Alice 在 Bob 前，Bob 在 Cara 前
//     const char* afterAlice = strstr(buf, "Alice");
//     const char* afterBob = afterAlice ? strstr(afterAlice, "Bob") : NULL;
//     CHECK(afterBob != NULL);
//     CHECK(afterBob && strstr(afterBob, "Cara") != NULL);

//     remove(outPath);
// }

// // PrintAll：只打印前 n 个学生（n 小于数组容量）。
// static void test_printall_partial(void)
// {
//     printf("[test_printall_partial]\n");
//     struct Student stu[3];
//     stu[0] = makeStu(1, "Alice", 90, 80, 70);
//     stu[1] = makeStu(2, "Bob", 60, 70, 80);
//     stu[2] = makeStu(3, "Cara", 100, 100, 100);

//     const char* outPath = "_ssm_all_n2.txt";
//     fflush(stdout);
//     int savedOut = _dup(_fileno(stdout));
//     freopen(outPath, "w", stdout);
//     PrintAll(stu, 2);
//     fflush(stdout);
//     _dup2(savedOut, _fileno(stdout));
//     _close(savedOut);

//     char buf[4096];
//     readFile(outPath, buf, sizeof(buf));
//     printf("  captured:\n%s", buf);

//     CHECK(strstr(buf, "Alice") != NULL);
//     CHECK(strstr(buf, "Bob") != NULL);
//     CHECK(strstr(buf, "Cara") == NULL); // 第 3 个不应被打印

//     remove(outPath);
// }

// // PrintAll：n<=0 时应给出提示而不是越界。
// static void test_printall_empty(void)
// {
//     printf("[test_printall_empty]\n");
//     struct Student stu[1];
//     stu[0] = makeStu(1, "Alice", 90, 80, 70);

//     const char* outPath = "_ssm_all_empty.txt";
//     fflush(stdout);
//     int savedOut = _dup(_fileno(stdout));
//     freopen(outPath, "w", stdout);
//     PrintAll(stu, 0);
//     fflush(stdout);
//     _dup2(savedOut, _fileno(stdout));
//     _close(savedOut);

//     char buf[512];
//     readFile(outPath, buf, sizeof(buf));
//     printf("  captured: %s", buf);

//     CHECK(strstr(buf, "empty") != NULL);
//     CHECK(strstr(buf, "Alice") == NULL);

//     remove(outPath);
// }

// int main(void)
// {
//     test_input();
//     test_maxscore_middle();
//     test_maxscore_tail();
//     test_maxscore_tie();
//     test_maxscore_single();
//     test_prtstu();
//     test_printall();
//     test_printall_partial();
//     test_printall_empty();

//     printf("\n==== %d passed, %d failed ====\n", g_pass, g_fail);
//     return g_fail == 0 ? 0 : 1;
// }

// /* ------------------- 原交互式运行示例（留作参考） -------------------
// #include "SSM.h"
// int main()
// {
//     int n;
//     printf("please input the num of students ->");
//     scanf("%d", &n);
//     struct Student stu[N];  // 申请连续的一块空间
//     InPutStu(stu, n);
//     PrintAll(stu, n);
//     PrtStu(MaxScore(stu, n));
//     return 0;
// }
// --------------------------------------------------------------------- */
