#include <stdio.h>
#include <assert.h>
// int main()
// {
//     int a = 10;
//     int *p = &a;
//     printf("%p\n",&a);
//     return 0;
// }
// int main()
// {
//     int a = 100;
//     int* pa = &a;
//     *pa = 0;  //解引用
//     return 0;
// }
// 32位平台下地址是32个bit位，指针变量⼤⼩是4个字节
// 64位平台下地址是64个bit位，指针变量⼤⼩是8个字节
// 注意指针变量的⼤⼩和类型是⽆关的，只要指针类型的变量，在相同的平台下，⼤⼩都是相同的。
// int main()
// {
//     int n = 0x11223344;
//     int r = 0x11223344;
//     int * pi = &n;
//     *pi = 0;
//     char * pr = (char *)&r;
//     *pr = 0;
//     printf("%d ",n);
//     printf("%d ",r);
//     return 0;
// // 指针的类型决定了，对指针解引⽤的时候有多⼤的权限（⼀次能操作⼏个字节）。
// // ⽐如： char* 的指针解引⽤就只能访问⼀个字节，⽽ int* 的指针的解引⽤就能访问四个字节

// }

// 指针加减整数
// int main()
// {
//     int n = 10;
//     char *pc = (char*)&n;
//     int *pi = &n;
//     printf("%p\n", &n);
//     printf("%p\n", pc);
//     printf("%p\n", pc+1);
//     printf("%p\n", pi);
//     printf("%p\n", pi+1);
//     return 0;
// }
//  char* 类型的指针变量+1跳过1个字节， int* 类型的指针变量+1跳过了4个字节。
// 这就是指针变量的类型差异带来的变化。指针+1，其实跳过1个指针指向的元素。指针可以+1，那也可
// 以-1。

// void* 指针    无具体类型指针 可接受任意类型地址 不可解引用以及+-
// int main()
// {
//     int a = 10;
//     void* pa = &a;  //正常
//     void* pc = &a;  // 正常
//     *pa = 10;  // 报错
//     *pc = 0;  //报错
//     return 0;
// }

//指针运算
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     int *p = &arr[0];
//     int i = 0;
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     for(i=0;i<sz;i++)
//     {
//         printf("%d ",*(p+i));    //指针加整数
//     }
//     return 0;
// }


//指针 - 指针  中间相隔的元素个数
// int my_strlen(char * s)
// {
//     char * p = s;
//     while(*p != '\0')
//     {
//         p++;
//     }
//     return p - s;

// }
// int main()
// {
//     printf("%d ",my_strlen("abc"));//传的是字符串首元素的地址
//     return 0;
// }


//指针的关系运算
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     int *p = &arr[0];
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     while(p < arr + sz)
//     {
//         printf("%d ",*p);
//         p++;
//     }
//     return 0;
// }








//以下为指针2
// const 修饰指针
// int main()
// {
//     int m = 0;
//     m = 20;
//     const int n = 0;
//     // n = 20;  //报错 const 在不可直接修改变量
//     //但是如果找到地址，修改地址的内容就可以
//     int *p = &n;
//     *p = 20;
//     printf("%d ",n);
//     return 0;
// }

//这时候就是const修饰指针上场的时候了
// 但是有int const* p 和int * const p 左修饰 右修饰 区别是什么
// void test1()
// {
//     int n = 10;
//     int m = 20;
//     int *p = &n;
//     *p = 20;  //ok?
//     p = &m;  //ok?
// }
// void test2()
// {
//     int n = 10;
//     int m = 20;
//     int const*p = &n;
//     *p = 20;  //ok?
//     p = &m;  //ok?
// }
// void test3()
// {
//     int n = 10;
//     int m = 20;
//     int *p = &n;
//     *p = 20;  //ok?
//     p = &m;  //ok?
// }
// int main()
// {
//     test1();
//     // test2();
//     // test3();
//     return 0;

// }
// int * const p  不可修改p
// int const * p  不可修改*p

//野指针   指向位置不可知

//1.未初始化 int *p;  没有明确指向
//2指针越界
// int main()
// {
//     int arr[10] = {0};
//     int *p = &arr[0];
//     int i = 0;
//     for(i = 0; i <= 11; i++)
//     {
//     //当指针指向的范围超出数组arr的范围时，p就是野指针
//     *(p++) = i;
//     }
//     return 0;
// }
//3.指针指向的空间释放
// int *test()
// {
//     int n = 100;
//     return &n;
// }
// int main()
// {
//     int *p = test();  函数结束 空间释放 成为野指针
//     printf("%d\n",*p);
//     return 0;
// }

//如果不知道指针指向哪里  可以int * ptr = NULL;


//assert 断言
//assert(p != NULL);  如果确实不等于 继续进行 否则 报错
//同时 如果已经确定无问题 定义一个宏即可
//#define NDEBUG


//指针的使用和传址调用
//size_t strlen ( const char * str );
// int my_strlen(const char *str)
// {
//     int count = 0;
//     assert(str);
//     while(*str)
//     {
//         str++;
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     int len = my_strlen("abcdef");
//     printf("%d\n",len);
//     return 0;
// }

//传值调用和传址调用

//写一个函数交换两个整形变量的值
// void Swap1(int x,int y)
// {
//     int tmp = x;
//     x = y;
//     y = tmp;

// }
// int main()
// {
//     int a = 0;
//     int b = 0;
//     scanf("%d %d",&a,&b);
//     printf("交换前a = %d b = %d\n",a,b);
//     Swap1(a,b);
//     printf("交换后a = %d b = %d\n",a,b);
//     return 0;
// }  //这是传值调用 看地址可以知道 a与x b与y 地址不同 Swap1 只是把x,y给交换了 a，b没换
// void Swap2(int *px,int *py)
// {
//     int tmp = 0;
//     tmp =*px;
//     *px = *py;
//     *py = tmp;
// }
// int main()
// {
//     int a;
//     int b;
//     scanf("%d %d",&a,&b);
//     printf("交换前a = %d b = %d\n",a,b);
//     Swap2(&a,&b);
//     printf("交换后a = %d b = %d\n",a,b);
//     return 0;
// }

//传址调用



