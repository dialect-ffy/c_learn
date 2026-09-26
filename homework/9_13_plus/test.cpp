// // test.cpp —— 针对 SSM.cpp（链式存储学生信息管理）的单元测试
// // 纯 assert 风格，自写 main，无需 GoogleTest / CMake。
// // 编译运行： g++ -g test.cpp -o build\Debug\outDebug.exe && .\build\Debug\outDebug.exe
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

// // ---------- 测试辅助：直接构造结点，避免依赖交互输入 ----------
// static Student* makeNode(int num, const char* name, float s0, float s1, float s2)
// {
//     Student* n = (Student*)malloc(sizeof(Student));
//     if (n == NULL) {
//         printf("makeNode malloc failed\n");
//         exit(-1);
//     }
//     n->num = num;
//     strcpy(n->name, name);
//     n->score[0] = s0;
//     n->score[1] = s1;
//     n->score[2] = s2;
//     n->aver = (s0 + s1 + s2) / 3.0f;
//     n->next = NULL;
//     return n;
// }

// static void appendNode(Student* head, Student* n)
// {
//     Student* p = head;
//     while (p->next != NULL) {
//         p = p->next;
//     }
//     p->next = n;
// }

// static void freeList(Student* head)
// {
//     while (head != NULL) {
//         Student* next = head->next;
//         free(head);
//         head = next;
//     }
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

// // InitList：应返回非空的哨兵位头结点，且 next 为 NULL。
// static void test_init(void)
// {
//     printf("[test_init]\n");
//     Student* head = InitList();
//     CHECK(head != NULL);
//     CHECK(head->next == NULL);
//     freeList(head);
// }

// // findMaxScore：空表应返回 NULL。
// static void test_findmax_empty(void)
// {
//     printf("[test_findmax_empty]\n");
//     Student* head = InitList();
//     CHECK(findMaxScore(head) == NULL);
//     freeList(head);
// }

// // findMaxScore：只有一个结点时返回该结点。
// static void test_findmax_single(void)
// {
//     printf("[test_findmax_single]\n");
//     Student* head = InitList();
//     Student* only = makeNode(1, "Only", 60, 70, 80); // aver = 70
//     appendNode(head, only);
//     CHECK(findMaxScore(head) == only);
//     freeList(head);
// }

// // findMaxScore：多结点时返回平均分最高的结点（最高分在中间）。
// static void test_findmax_multiple(void)
// {
//     printf("[test_findmax_multiple]\n");
//     Student* head = InitList();
//     Student* a = makeNode(1, "A", 60, 60, 60); // 60
//     Student* b = makeNode(2, "B", 90, 90, 90); // 90
//     Student* c = makeNode(3, "C", 70, 70, 70); // 70
//     appendNode(head, a);
//     appendNode(head, b);
//     appendNode(head, c);
//     CHECK(findMaxScore(head) == b);
//     freeList(head);
// }

// // findMaxScore：最高平均分在表尾时也能找到。
// static void test_findmax_tail(void)
// {
//     printf("[test_findmax_tail]\n");
//     Student* head = InitList();
//     Student* a = makeNode(1, "A", 50, 50, 50); // 50
//     Student* b = makeNode(2, "B", 60, 60, 60); // 60
//     Student* c = makeNode(3, "C", 95, 96, 97); // 96
//     appendNode(head, a);
//     appendNode(head, b);
//     appendNode(head, c);
//     CHECK(findMaxScore(head) == c);
//     freeList(head);
// }

// // findMaxScore：平均分并列时，返回第一个（严格大于才更新）。
// static void test_findmax_tie(void)
// {
//     printf("[test_findmax_tie]\n");
//     Student* head = InitList();
//     Student* a = makeNode(1, "A", 80, 80, 80); // 80
//     Student* b = makeNode(2, "B", 80, 80, 80); // 80
//     appendNode(head, a);
//     appendNode(head, b);
//     CHECK(findMaxScore(head) == a);
//     freeList(head);
// }

// // addStudent：重定向 stdin 自动喂数据，验证尾插顺序、字段与平均分。
// static void test_addstudent(void)
// {
//     printf("[test_addstudent]\n");
//     const char* inPath = "_ssm_in.txt";
//     FILE* f = fopen(inPath, "w");
//     if (f == NULL) {
//         CHECK(0 && "create input file failed");
//         return;
//     }
//     fprintf(f, "1 Alice 90 80 70\n");
//     fprintf(f, "2 Bob 60 70 80\n");
//     fclose(f);

//     int savedIn = _dup(_fileno(stdin));
//     freopen(inPath, "r", stdin);

//     Student* head = InitList();
//     addStudent(head);
//     addStudent(head);

//     _dup2(savedIn, _fileno(stdin));
//     _close(savedIn);

//     Student* n1 = head->next;
//     CHECK(n1 != NULL);
//     CHECK(n1->num == 1);
//     CHECK(strcmp(n1->name, "Alice") == 0);
//     CHECK(nearlyEqual(n1->score[0], 90.0f));
//     CHECK(nearlyEqual(n1->score[1], 80.0f));
//     CHECK(nearlyEqual(n1->score[2], 70.0f));
//     CHECK(nearlyEqual(n1->aver, 80.0f));

//     Student* n2 = n1->next;
//     CHECK(n2 != NULL);
//     CHECK(n2->num == 2);
//     CHECK(strcmp(n2->name, "Bob") == 0);
//     CHECK(nearlyEqual(n2->aver, 70.0f));
//     CHECK(n2->next == NULL); // 尾插：最后结点的 next 为 NULL

//     freeList(head);
//     remove(inPath);
// }

// // PrintMax：捕获 stdout，验证打印内容包含学号、姓名与平均分。
// static void test_printmax(void)
// {
//     printf("[test_printmax]\n");
//     Student* head = InitList();
//     appendNode(head, makeNode(1, "Alice", 90, 80, 70)); // 80
//     appendNode(head, makeNode(2, "Bob", 60, 70, 80));   // 70
//     Student* maxStu = findMaxScore(head);
//     CHECK(maxStu != NULL);

//     const char* outPath = "_ssm_out.txt";
//     fflush(stdout);
//     int savedOut = _dup(_fileno(stdout));
//     freopen(outPath, "w", stdout);
//     PrintMax(maxStu);
//     fflush(stdout);
//     _dup2(savedOut, _fileno(stdout));
//     _close(savedOut);

//     char buf[1024];
//     readFile(outPath, buf, sizeof(buf));
//     printf("  captured:\n%s", buf);

//     CHECK(strstr(buf, "num:1") != NULL);
//     CHECK(strstr(buf, "Alice") != NULL);
//     CHECK(strstr(buf, "aver: 80.000000") != NULL);

//     freeList(head);
//     remove(outPath);
// }

// // PrintAll：捕获 stdout，验证按链表顺序逐个打印全部学生。
// static void test_printall(void)
// {
//     printf("[test_printall]\n");
//     Student* head = InitList();
//     appendNode(head, makeNode(1, "Alice", 90, 80, 70));   // 80
//     appendNode(head, makeNode(2, "Bob", 60, 70, 80));     // 70
//     appendNode(head, makeNode(3, "Cara", 100, 100, 100)); // 100

//     const char* outPath = "_ssm_all.txt";
//     fflush(stdout);
//     int savedOut = _dup(_fileno(stdout));
//     freopen(outPath, "w", stdout);
//     PrintAll(head);
//     fflush(stdout);
//     _dup2(savedOut, _fileno(stdout));
//     _close(savedOut);

//     char buf[4096];
//     readFile(outPath, buf, sizeof(buf));
//     printf("  captured:\n%s", buf);

//     // 三个学生的信息都应出现
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

//     // 不应包含哨兵位（num=-1）
//     CHECK(strstr(buf, "num:-1") == NULL);

//     freeList(head);
//     remove(outPath);
// }

// // PrintAll：空表应给出提示而不是崩溃。
// static void test_printall_empty(void)
// {
//     printf("[test_printall_empty]\n");
//     Student* head = InitList();

//     const char* outPath = "_ssm_all_empty.txt";
//     fflush(stdout);
//     int savedOut = _dup(_fileno(stdout));
//     freopen(outPath, "w", stdout);
//     PrintAll(head);
//     fflush(stdout);
//     _dup2(savedOut, _fileno(stdout));
//     _close(savedOut);

//     char buf[512];
//     readFile(outPath, buf, sizeof(buf));
//     printf("  captured: %s", buf);

//     CHECK(strstr(buf, "empty") != NULL);

//     freeList(head);
//     remove(outPath);
// }

// int main(void)
// {
//     test_init();
//     test_findmax_empty();
//     test_findmax_single();
//     test_findmax_multiple();
//     test_findmax_tail();
//     test_findmax_tie();
//     test_addstudent();
//     test_printmax();
//     test_printall();
//     test_printall_empty();

//     printf("\n==== %d passed, %d failed ====\n", g_pass, g_fail);
//     return g_fail == 0 ? 0 : 1;
// }
