#include <stdio.h>
#include <math.h>
#include <string.h>
//double sqrt (double x);
// int main()
// {
//     double d = 16.0;
//     double r = sqrt(d);
//     printf("%f",r);
//     return 0;
// }
//ret_type fun_name(形式参数)  自定义函数
//   {
//   }
// int Add(int x,int y)
// {
//     return x + y;
// }
// int main()
// {
//     int a;
//     int b;
//     scanf("%d %d",&a,&b);
//     int z = Add(a,b);
//     printf("%d\n",z);
//     return 0;
// }
// void set_arr(int arr[],int sz)
// {
//     int i;
//     for(i=0;i<sz;i++)
//     {
//         arr[i] = -1;
//     }
    
// }
// void print_arr(int arr[],int sz)
// {
//     int i;
//     for(i=0;i<sz;i++)
//     {
//         printf("%d ",arr[i]);
//     }
// }
// int main()
// {
    
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     set_arr(arr,sz);
//     print_arr(arr,sz);
//     return 0;
// }
// 计算某年某月有多少天
//判断是否是leap year
// int is_leap(int y)
// {
//     if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int get_days(int y,int m)
// {
//     int arr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//     if (is_leap(y))
//     {
//         arr[2] += 1;
//     }
//     return arr[m];
// }

// int main()
// {
//     int y = 0;
//     int m = 0;
//     scanf("%d%*c%d",&y,&m);
//     int d = get_days(y,m);
//     printf("%d\n",d);
//     return 0;
// }
//链式访问
// int main()
// {
//     printf("%zd\n",strlen("abcdef"));
//     return 0;
// }
//int printf ( const char * format, ... );返回值为打印在屏幕上的字符个数
// int main()
// {
//     printf("%d", printf("%d", printf("%d", 43)));
//     return 0;
// }
//43先打印 返回2   2 打印 返回1  1打印 返回1 结束 4321

//函数的声明和定义
//通过声明我们可以把一个较大的代码拆分 自定义函数 主函数 头文件 方便管理
//int is_leap_year(int y);//函数声明

//static 和extern
//static 静态 局部变量 全局变量 函数 均可修饰
//extern 用来声明外部符号
// #include <stdio.h>
// void test()
// {
//     static int i = 0;  //未来⼀个变量出了函数后，我们还想保留值，等下次进⼊函数继续使⽤，就可以使⽤
// // 1 1 1 1 1   // 1 2 3 4 5  修饰局部 局部保留
//     i++;
//     printf("%d ", i);
// }
// int main()
// {
//     int i = 0;
//     for(i=0; i<5; i++)
//     {   
//         test();
//     }
//     return 0;
// }
// //static 如果修饰全局变量 或者自定义函数 且与主函数在不同的源文件中，就不可以用extern来进行声明
// //本质原因是全局变量默认是具有外部链接属性的，在外部的⽂件中想使⽤，只要适当的声明就可以使
// //⽤；但是全局变量被 static 修饰之后，外部链接属性就变成了内部链接属性，只能在⾃⼰所在的源
// //⽂件内部使⽤了，其他源⽂件，即使声明了，也是⽆法正常使⽤的。
