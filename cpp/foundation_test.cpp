// #include "foundation.h"

// // 全局定义了⼀份单独的Stack
// typedef struct Stack
// {
//     int a[10];
//     int top;
// }ST;
// void STInit(ST* ps){}
// void STPush(ST* ps, int x){}
// int main()
// {
//     // 调⽤全局的
//     ST st1;
//     STInit(&st1);
//     STPush(&st1, 1);
//     STPush(&st1, 2);
//     printf("%d\n", sizeof(st1));
//     // 调⽤bit namespace的
//     dialect::ST st2;
//     printf("%d\n", sizeof(st2));
//     dialect::STInit(&st2);
//     dialect::STPush(&st2, 1);
//     dialect::STPush(&st2, 2);
//     return 0;
// }