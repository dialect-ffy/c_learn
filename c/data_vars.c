#include <stdio.h>
#include <stdbool.h>

//int main()
// {
// int a = 10;
// printf("%zd\n", sizeof(a));
// printf("%zd\n", sizeof a);//a是变量的名字，可以省略掉sizeof后边的()
// printf("%zd\n", sizeof(int));
// printf("%zd\n", sizeof(3 + 3.5));
// return 0;
// }

// int main()
// {
//     printf("%zd\n",sizeof(int));
//     printf("%zd\n",sizeof(char));
//     printf("%zd\n",sizeof(float));
//     printf("%zd\n",sizeof(double));
//     printf("%zd\n",sizeof(long));
//     printf("%zd\n",sizeof(long long));
//     printf("%zd\n",sizeof(short));
//     printf("%zd\n",sizeof(bool));
//     return 0;
// }    
// int main()
// {
//     int a = 10;
//     short b = 2;
//     printf("%zd\n",sizeof(a = b + 1));  //赋值表达式整体的类型等于左边的类型 ---a  sizeof 不会执行
//     printf("%d",a);
//     return 0;
// }
// #define SHRT_MIN (-32768) //有符号16位整型的最⼩值
// #define SHRT_MAX 32767 //有符号16位整型的最⼤值
// #define USHRT_MAX 0xffff //⽆符号16位整型的最⼤值
// #define INT_MIN (-2147483647 - 1) //有符号整型的最⼩值
// #define INT_MAX 2147483647 //有符号整型的最⼤值
// int main()
// {
//     int a =  10 / 4;
//     float b =  10 / 4;
//     int c = 10 / 4.0; // 10 / 4.0 是浮点数除法，结果是浮点数
//     float d = 10 / 4.0; // 10 / 4.0 是浮点数除法，结果是浮点数
//     printf("%d\n", a);
//     printf("%f\n", b);      // 2.000000 / 是整数除法 只会留下整数部分     
//     printf("%d\n", c);
//     printf("%f\n", d);
//     return 0;
// }
// int main()
// {
//     int a = 5;
//     printf("%d\n",(a / 20) * 100); 
//     printf("%f\n",(a / 20.0) * 100); 
//     return 0;
// }
// int main()
// {
//     int x = 6 % 4 ;  // % 求余（模） 仅可用于整数运算
//     printf("%d\n", x);
//     printf("%d\n",-11 % 5); // 符号与第一个数相同
//     printf("%d\n",11 % -5);
//     printf("%d\n",11 % 5);
//     printf("%d\n",-11 % -5);
//     return 0;
// }
// int main()
// {
//    int a = 1;
//    int b = 2;
//    int c = 3;
//    a += 1;
//    b -= 2;
// //    c *= 2;
//    c /= 2;
//    a = b = c + 1;  // 连续赋值 从右向左依次赋值
//    printf("%d\n",c);
//    printf("%d\n",b);
//    printf("%d\n",a);
//    return 0;
//
// }
// int main()
// {
//     int a = 10;
//     int b;
//     b = ++a;  //前置++ 先+1 后使用  a 也会变哦
//     printf("a=%d b=%d\n",a , b);
//     return 0;
// }
// int main()
// {
//     int a = 10;
//     int b;
//     b = a++;
//     printf("a = %d b = %d\n",a,b);
//     return 0;
// }
//int a = (int)3.14; 强制类型转换 3.14是double类型，强制转换为int类型，结果是3
// #include <stdio.h>
// int main()
// {
// printf("%s will come tonight\n", "zhangsan");
// return 0;
// }   
// #include <stdio.h>
// int main()
// {
// printf("%s says it is %d o'clock\n", "lisi", 21);
// return 0;
// }

// int main()
// {
// printf("%5d\n", 123); // 输出为 " 123"  默认右对齐，宽度为5
// printf("%-5d\n", 123); // 输出为 "123  "
// printf("%12f\n", 3.14); // 输出为 "      3.140000"  默认右对齐，宽度为12
// printf("%+d\n", 123); // 输出为 "+123"
// return 0;
// }
// int main()
// {
// printf("Number is %6.2f\n", 0.5);
// return 0;
// }
// int main()
// {
// printf("%*.*f\n", 6, 2, 0.5);
// return 0;
// }
//// 等同于printf("%6.2f\n", 0.5);
// int main()
// {
// printf("%.5s\n", "hello world"); // %.5s表示输出字符串的前5个字符，结果为"hello"
// return 0;
// }
// int main()
// {
//     int a = 0;
//     printf("请输入成绩：");
//     scanf("%d",&a);
//     printf("成绩是：%d\n",a);
//     return 0;
// }
//scanf("%d%d%f%f",&a,&b,&c,&d); // 读取两个整数和两个浮点数 
//scanf 会读到第一个不符合格式的字符就停止读取，后续的输入会留在输入缓冲区中，等待下一次读取。
// int main()
// {
//     int x;
//     float y;
//     scanf("%d%f", &x, &y);
//     printf("x = %d, y = %f\n", x, y);
//     return 0;
// }
// int r = scanf("%d %d %f", &a, &b, &f); // scanf返回成功读取的输入项的数量，如果输入不符合格式，返回值可能小于预期的数量，甚至为0。
// int main()
// {
//     char name[11];

//     scanf("%10s", name);
//     return 0;
// } // 读取一个字符串，最多读取10个字符，并将其存储在name数组中。
// int main()
// {
//     int year;
//     int month;
//     int day;
//     scanf("%d%*c%d%*c%d", &year, &month, &day); // %*c表示读取一个字符但不存储它，通常用于跳过分隔符
//     printf("year = %d, month = %d, day = %d\n", year, month, day);
// }
