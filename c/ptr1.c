#include <stdio.h>
//数组名就是数组首元素的地址
//有两种特殊情况
//sizeof(数组名)  表示整个数组     &数组名 取出整个数组的地址  
// int main()
// {
//     int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//     printf("&arr[0] = %p\n", &arr[0]);
//     printf("&arr[0]+1 = %p\n", &arr[0]+1);
//     printf("arr = %p\n", arr);
//     printf("arr+1 = %p\n", arr+1);
//     printf("&arr = %p\n", &arr);
//     printf("&arr+1 = %p\n", &arr+1);
//     return 0;
// }

//使用指针访问数组
// int main()
// {
//     int arr[10] = {0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int *p = arr;
//     int i = 0;
//     for(i=0;i<sz;i++)
//     {
//         scanf("%d",p+i);
//     }
//     for(i=0;i<sz;i++)
//     {
//         printf("%d ",*(p+i)); //*(p+i) == p[i]
//     }
//     return 0;
// }
// 这个代码搞明⽩后，我们再试⼀下，如果我们再分析⼀下，数组名arr是数组⾸元素的地址，可以赋值
// 给p，其实数组名arr和p在这⾥是等价的。那我们可以使⽤arr[i]可以访问数组的元素，那p[i]是否也可
// 以访问数组呢   sure

//一维数组传参的本质  --传的是首元素的地址 因此不可再单独定义先函数传过去求数组大小
// void test(int arr[])//参数写成数组形式，本质上还是指针 1
// {
//     printf("%d\n", sizeof(arr));
// }
// // void test(int* arr)//参数写成指针形式
// // {
// //     printf("%d\n", sizeof(arr));//计算⼀个指针变量的⼤⼩
// // }
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     test(arr);
//     return 0;
// }


//冒泡排序 核心思想  ：两两相邻的元素进行比较
// void bubble_sort(int arr[],int sz)
// {
//     int i = 0;
//     for(i=0;i<sz-1;i++)
//     {  //十个元素，最多九轮，每一轮会把目前最大的元素移到结尾
//         int flag = 1;
//         int j= 0;
//         for(j=0;j<sz-1-i;j++)  //对于第j个数(包括第0个数)，只需与它之后的两两相比
//         {
//             if (arr[j] > arr[j+1])
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = tmp;
//                 flag = 0;
//             }
//         }
//         if (flag == 1)
//         {
//             break;
//         }

//     }
    
// }
// //如果中途排列好了，直接break,优化一小下
// int main()
// {
//     int arr[10] = {3,2,4,5,1,7,8,6,9,10};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr,sz);
//     int i = 0;
//     for(i=0;i<sz;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }

//二级指针
//指针变量也是变量 是变量就有地址 
// int main()
// {
//     int a= 0;
//     int *pa = &a;
//     int **ppa = &pa;
//     return 0;
// }
//int b = 20;
//*ppa = &b;  // 等价于 pa = &b
// **ppa = 30;

//指针数组
//int *arr[5]      类型 int * [5]

//用指针数组模拟二维数组   但不是二维数组 因为每一行不是连续的
// int main()
// {
//     int arr1[] = {1,2,3,4,5};
//     int arr2[] = {2,3,4,5,6};
//     int arr3[] = {3,4,5,6,7};
//     int *ptr[3] = {arr1,arr2,arr3};
//     for(int i = 0;i<3;i++)
//     {
//         int j = 0;
//         for(j=0;j<5;j++)
//         {
//             printf("%d ",ptr[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }







//以下为4的内容
// 字符指针变量 char*
// int main()
// {
//     char ch = 'w';
//     char * ptr = &ch;
//     *pc = 'w';
//     return 0;

// }
// int main()
// {
//     const char* pstr = "hello\0 bit";
//     printf("%s\n",pstr);  //打印到\0
//     return 0;
// }
// int main()
// {
//     char str1[] = "hello bit.";
//     char str2[] = "hello bit.";
//     char *str3 = "hello bit.";
//     char *str4 = "hello bit.";
//     if(str1 ==str2)
//     printf("str1 and str2 are same\n");
//     else
//     printf("str1 and str2 are not same\n");
//     if(str3 ==str4)
//     printf("str3 and str4 are same\n");
//     else
//     printf("str3 and str4 are not same\n");
//     return 0;
// }
//这⾥str3和str4指向的是⼀个同⼀个常量字符串。C/C++会把常量字符串存储到单独的⼀个内存区域，
//当⼏个指针指向同⼀个字符串的时候，他们实际会指向同⼀块内存。但是⽤相同的常量字符串去初始
//化不同的数组的时候就会开辟出不同的内存块。所以str1和str2不同，str3和str4相同。

//数组指针变量
//int * p1[10];  //指针数组
//int (*p2)[10];  //数组指针 类型 int (*) [5] 
// 解释：p先和*结合，说明p是⼀个指针变量，然后指针指向的是⼀个⼤⼩为10个整型的数组。所以p是
// ⼀个指针，指向⼀个数组，叫 数组指针。
// 这⾥要注意：[]的优先级要⾼于*号的，所以必须加上（）来保证p先和*结合。
// int arr[10]  = {0};
// &arr; //得到的是数组的地址
// int(*p)[10] = &arr;  //类型均为int(*)[10]



//二维数组传参的本质
//二维数组的每个元素是一维数组 传的是首元素的地址 即一维数组的地址
// void test(int a[3][5], int r, int c)
// {         //int(*p)[5]  数组指针
//     int i = 0;
//     int j = 0;
//     for(i=0; i<r; i++)
//     {
//     for(j=0; j<c; j++)
//     {
//     printf("%d ", a[i][j]);
//     }
//     printf("\n");
//     }
// }
// int main()
// {
//     int arr[3][5] = {{1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7}};
//     test(arr, 3, 5);
//     return 0;
// }

//函数指针变量
//用来存放函数的地址
// void test()
// {
//     printf("hehe\n");
//     }
// int main()
// {
//     printf("test: %p\n", test);
//     printf("&test: %p\n", &test);  //2 个相同 说明函数名就是函数的地址
//     return 0;

// }
// void test()
// {
//     printf("hehe");
// }
// void (*pf1) () = &test;
// void (*pf2) () = test;
// int Add(int x,int y)
// {
//     return x + y;
// }
// int (*pf3) (int x,int y) = Add;
// int Add(int x,int y)
// {
//     return x + y;
// }
// int main()
// {
//     int (*pf3)(int x,int y )  = Add;
//     printf("%d ",(*pf3)(2,3));
//     printf("%d ",pf3(2,3));
//     return 0;
// }


//下面看2段有趣的代码
// (*(void (*)())0)();
// void (*)()  函数指针 将0转化为这个类型，然后解引用
// 这个函数没有参数 也没有返回值




// void (*signal(int , void(*)(int)))(int);   没看明白 ！！！！！！！！！！！！！！！！



//tyoedef 关键字
// typedef unsigned int uint;
// typedef int * ptr_t;
// typedef int(* parr_t)[5];
// typedef void(* pf_t)(int);
// //简化代码2
// typedf void (*pfun_t)(int)
// pfun_t signal(int,pfun_t);
//如果内部只有一个名字 是函数指针 内部有其他的东西 可以考虑是函数声明 包起来的是返回类型

// //函数指针数组
// int * arr[10];  指针数组
// //把函数的地址存到一个数组中就叫做函数指针数组
// int (*parr1[3])();
// 类比指针数组  int(*)() parr[3]
// 但是c语言不允许这样写
// int(*parr[10])();

//转移表
//利用到函数指针变量  结合来看
//int (*p)(int x,int y);  类型为 int (*) (int x,int y);
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
//     return a*b;
// }
// int div(int a, int b)
// {
//     return a / b;
// }
// void menu()
// {
//     printf("*************************\n");
//     printf(" 1:add 2:sub \n");
//     printf(" 3:mul 4:div \n");
//     printf(" 0:exit \n");
//     printf("*************************\n");
//     printf( "请选择：" );
// }
// int main()
// {
//     int x= 0;
//     int y = 0;
//     int input  =1;
//     int ret =0;
//     int(*p[5])(int x,int y) = {0,add,sub,mul,div};
//     do{
//         menu();
//         scanf("%d",&input);
//         if ((input <= 4 && input >= 1))
//     {
//         printf( "输⼊操作数：" );
//         scanf( "%d %d", &x, &y);
//         ret = (*p[input])(x, y);
//         printf( "ret = %d\n", ret);
//     }
//     else if(input == 0)
//     {
//         printf("退出计算器\n");
//     }
//     else
//     {
//         printf( "输⼊有误\n" );
//     }
//     }while (input);
//     return 0;
// }


    

