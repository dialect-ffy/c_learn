#include <stdio.h>
#include <stdlib.h>
// 回调函数
// 如果你把函数的指针（地址）作为参数传递给另⼀个函数，当这个指针被⽤来调⽤其所指向的函数
// 时，被调⽤的函数就是回调函数。
// int add(int a, int b)
// {
//     return a + b;
// }
// int sub(int a, int b)
// {
//     return a - b;
// }
// int mul(int a, int b)
// {
//     return a * b;

// }
// int div(int a, int b)
// {
//     return a / b;
// }

// void calc(int(*pf)(int, int))  //函数指针变量传过来
// {
//     int ret = 0;
//     int x, y;
//     printf("输⼊操作数：");
//     scanf("%d %d", &x, &y);
//     ret = pf(x, y);
//     printf("ret = %d\n", ret);
// }
// int main()
// {
//     int input = 1;
//     do
//     {
//         printf("*************************\n");
//         printf(" 1:add2:sub \n");
//         printf(" 3:mul4:div \n");
//         printf("*************************\n");
//         printf("请选择：");
//         scanf("%d", &input);
//         switch (input)

//             {
//             case 1:
//                 calc(add);
//                 break;
//             case 2:
//                 calc(sub);
//                 break;
//             case 3:
//                 calc(mul);
//                 break;
//             case 4:
//                 calc(div);
//                 break;
//             case 0:
//                 printf("退出程序\n");
//                 break;
//             default:
//                 printf("选择错误\n");
//                 break;
//             }
//     }while(input);

// return 0;
// }


//qsort
//使用qsort排序正型数据
// qsort 的实现需要一个比较函数 用于其中任意两个元素的比较方式
// int int_cmp(const void *p1,const void *p2)
// {
//     return *((int *)p1) -  *((int *)p2);
// }
// int main()
// {
//     int arr[] = {1,3,5,7,9,2,4,6,8,0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//     qsort(arr,sz,sizeof(arr[0]),int_cmp);
//     for(i = 0;i<sz;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }
//利用qsort 来排序结构体
// struct stu
// {
//     char name[20];
//     int age;
// };
// int cmp_stu_by_age(const void *p1,const void * p2)
// {
//     return ((struct stu *)p1) -> age - ((struct stu *)p2)-> age;
// }  //若改成按名字比大小 strcmp((((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
// // 专门用来比较两个字符串的大小
// void test2()
// {
//     struct stu s[] = {{"zhang san",20},{"li si",21},{"wang wu",22}};
//     qsort(s,sizeof(s)/sizeof(s[0]),sizeof(s[0]),cmp_stu_by_age);

// }

// int main()
// {
//     test2();
    
//     return 0;
// }

//qsort 的模拟实现
// int cmp (const void*p1,const void *p2)  //这就是cmp函数需要自己写的原因，要根据你比较的类型来写
// {
//     return (*(int *)p1 - *(int*)p2);
// }
// void Swap( void*p1,void*p2,int size)
// {
//     int i = 0;
//     for(i=0;i<size;i++)
//     {
//         char tmp = *((char *)p1 + i);
//         *((char *)p1 + i) = *((char *)p2 + i);
//         *((char *)p2 + i) = tmp;
//     }
// }

// void bubble_sort_pro (void *base,int count,int size,int(*cmp)(const void*p1,const void*p2))
// {
//     int i = 0;
//     for( i=0;i<count-1;i++)
//     {
//         int j = 0;
//         for(j=0;j<count - 1- i;j++)
//         {
//             if(cmp((char *)base + j*size,(char *)base + (j+1)*size) > 0)
//             {
//                 Swap((char *)base + j*size,(char*)base + (j+1)*size,size);
//             }
//         }
//     }
// }




// int main()
// {
//     int arr[] = {1,3,5,7,9,2,4,6,8,10};
//     int i = 0;
//     int count = sizeof(arr) / sizeof(arr[0]);
//     int size = sizeof(arr[0]);
//     bubble_sort_pro(arr, count, size, cmp);
//     for (i = 0; i < count; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;
// }


//以下为指针6的内容
// sizeof 和 strlen 的对比
// 我们学习了 sizeof ， sizeof 计算变量所占内存空间⼤⼩的，单位是字
// 节，如果操作数是类型的话，计算的是使⽤类型创建的变量所占内存空间的⼤⼩。
// sizeof 只关注占⽤内存空间的⼤⼩，不在乎内存中存放什么数据。



// strlen 是C语⾔库函数，功能是求字符串⻓度。函数原型如下：
// size_t strlen ( const char * str ); 
// 统计的是从 strlen 函数的参数 str 中这个地址开始向后， \0 之前字符串中字符的个数。
// strlen 函数会⼀直向后找 \0 字符，直到找到为⽌，所以可能存在越界查找。
// int main()
// {
//     int a[] = {1,2,3,4}; 
//     printf("%d\n",sizeof(a));  // 表示求整个数组大小 16
//     printf("%d\n",sizeof(a+0));// 表示首元素地址
//     printf("%d\n",sizeof(*a));  //arr[0]
//     printf("%d\n",sizeof(a+1)); // 表示第二个元素的地址 4/8
//     printf("%d\n",sizeof(a[1]));  //  
//     printf("%d\n",sizeof(&a));  //表示整个数组的地址
//     printf("%d\n",sizeof(*&a));  // 表示整个数组大小
//     printf("%d\n",sizeof(&a+1));  //地址
//     printf("%d\n",sizeof(&a[0]));  // 地址
//     printf("%d\n",sizeof(&a[0]+1));  //地址
//     return 0;
// }

// int main()
// {
//     char arr[] = {'a','b','c','d','e','f'};
//     printf("%d\n", sizeof(arr));  //6 整个数组大小
//     printf("%d\n", sizeof(arr+0));  //地址
//     printf("%d\n", sizeof(*arr));  //首元素大小 1
//     printf("%d\n", sizeof(arr[1]));  //1 同上
//     printf("%d\n", sizeof(&arr));  //地址
//     printf("%d\n", sizeof(&arr+1));   // 地址
//     printf("%d\n", sizeof(&arr[0]+1));  //地址
//     return 0;
// }
// //  strlen需要的是一个地址
// int main()
// {
//     char arr[] = {'a','b','c','d','e','f'};
//     printf("%d\n", strlen(arr));  //无\0 未知数
//     printf("%d\n", strlen(arr+0));  //未知数
//     printf("%d\n", strlen(*arr));  //  'a' 97  可能报错
//     printf("%d\n", strlen(arr[1]));  // 'b' 98 可能报错
//     printf("%d\n", strlen(&arr));  //未知数
//     printf("%d\n", strlen(&arr+1));  //上一个未知数-6 跳过了数组
//     printf("%d\n", strlen(&arr[0]+1));  //未知数
//     return 0;
// }

// int main()
// {
//     char arr[] = "abcdef";  // a b c d e f \0
//     printf("%d\n", sizeof(arr));  //7
//     printf("%d\n", sizeof(arr+0));  //地址
//     printf("%d\n", sizeof(*arr));   //1
//     printf("%d\n", sizeof(arr[1]));  //1
//     printf("%d\n", sizeof(&arr));  //地址
//     printf("%d\n", sizeof(&arr+1));  // 地址
//     printf("%d\n", sizeof(&arr[0]+1));  //地址
//     return 0;
// }

// int main()
// {
//     char arr[] = "abcdef";  
//     printf("%d\n", strlen(arr));  //6
//     printf("%d\n", strlen(arr+0));  //6
//     printf("%d\n", strlen(*arr)); //报错
//     printf("%d\n", strlen(arr[1]));  //报错
//     printf("%d\n", strlen(&arr));  //6
//     printf("%d\n", strlen(&arr+1));  //未知数
//     printf("%d\n", strlen(&arr[0]+1));  //5
//     return 0;
// }
// int main()
// {
//     char *p = "abcdef";
//     printf("%d\n", sizeof(p));  //地址
//     printf("%d\n", sizeof(p+1)); //地址
//     printf("%d\n", sizeof(*p));  //1
//     printf("%d\n", sizeof(p[0]));  //1
//     printf("%d\n", sizeof(&p));   //地址
//     printf("%d\n", sizeof(&p+1)); // 地址
//     printf("%d\n", sizeof(&p[0]+1));  //地址
//     return 0;
// }

// int main()
// {
//     char *p = "abcdef";
//     printf("%d\n", strlen(p));  //6
//     printf("%d\n", strlen(p+1));  //5
//     printf("%d\n", strlen(*p));  //'a'报错
//     printf("%d\n", strlen(p[0]));  //'a' 报错
//     printf("%d\n", strlen(&p));  //未知数
//     printf("%d\n", strlen(&p+1));  //未知数
//     printf("%d\n", strlen(&p[0]+1));  //5
//      return 0;
// }



// int main()
// {
//     int a[3][4] = {0};
//     printf("%d\n",sizeof(a));// 12  * 4 = 48
//     printf("%d\n",sizeof(a[0][0]));//  4
//     printf("%d\n",sizeof(a[0]));  // 4 * 4 = 16
//     printf("%d\n",sizeof(a[0]+1));  // 没有单独放在里面 即为a[0][0] 的地址 再+1 &a[0][1]
//     printf("%d\n",sizeof(*(a[0]+1)));  //4
//     printf("%d\n",sizeof(a+1));  //地址 &a[0] 第一行的地址
//     printf("%d\n",sizeof(*(a+1)));  //4 * 4 = 16
//     printf("%d\n",sizeof(&a[0]+1)); //第二行的地址
//     printf("%d\n",sizeof(*(&a[0]+1)));  //16
//     printf("%d\n",sizeof(*a));  //16
//     printf("%d\n",sizeof(a[3]));  //sizeof内部不会求值 只是推导  16
//     return 0;
// }

// int main()
// {
//     int a[5] = { 1, 2, 3, 4, 5 };
//     int *ptr = (int *)(&a + 1);
//     printf( "%d,%d", *(a + 1), *(ptr - 1));
//     return 0;
// }  // 2 5



//以下这道题要在x86的环境下运行
// struct Test
// {
//     int Num;
//     char *pcName;
//     short sDate;
//     char cha[2];
//     short sBa[4];
// }*p = (struct Test*)0x100000;
// int main()
// {
//     printf("%p\n", p + 0x1);  // 0x100014  00100014
//     printf("%p\n", (unsigned long)p + 0x1);  //0x100001  00100001
//     printf("%p\n", (unsigned int*)p + 0x1);  // 0x100004  00100004
//     return 0;
// }


// int main()
// {
//     int a[3][2] = { (0, 1), (2, 3), (4, 5) };  //圆括号哦 逗号表达式  //正常来说要用大括号
//     int *p;
//     p = a[0];
//     printf( "%d", p[0]);
//     return 0;
// }  //1 3
     // 5 0
     // 0 0


// int main()
// {
//     int a[5][5];
//     int(*p)[4];  //数组指针 指向一个数组
//     p = a;  //把a 的地址给了p

//     printf( "%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//     return 0;
// }  //         %p 是打印地址 ，内存中的值直接打印出来,不会把补码转换为原码即打印的是4的补码
//   //FFFFFFC  -4



// #include <stdio.h>
// int main()
// {
// int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
// int *ptr1 = (int *)(&aa + 1);  //跳过全部
// int *ptr2 = (int *)(*(aa + 1));   //首元素相当于数组 第二行
// printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));
// return 0;
// }   // 10 5

// #include <stdio.h>
// int main()
// {
//     char *a[] = {"work","at","alibaba"};
//     char**pa = a;  //pa 存放a首元素 的地址
//     pa++;  //pa 指向的是char * 类型 的 +1 到下一个char*
//     printf("%s\n", *pa);
//     return 0;
// }

//  char *     "work"
//  char *     "at"
//  char *     "alibaba"  存入首字母地址
 //char * *pa  指向char* 类型
//  int main()
// {
//     char *c[] = {"ENTER","NEW","POINT","FIRST"};
//     char**cp[] = {c+3,c+2,c+1,c};
//     char***cpp = cp;
//     printf("%s\n", **++cpp);  //POINT
//     printf("%s\n", *--*++cpp+3);  //ER
//     printf("%s\n", *cpp[-2]+3);  //RT
//     printf("%s\n", cpp[-1][-1]+1);  //EW
//     return 0;
// }

//画图