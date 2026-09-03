#include <stdio.h>
// 递归即为拆分 大问题化小问题
// 1.要有限制条件 2.每次递归后接近限制条件.
//求n的阶乘(factorial)
// int Fact(int n)
// {
//     if (n==0)
//     {
//         return 1;
//     }
//     else
//     {
//         return n*Fact(n-1);
//     }
// }
// int main()
// {
//     int n = 0;
//     scanf("%d",&n);
//     int z = Fact(n);
//     printf("%d\n",z);
//     return 0;
// }
// int main()
// {
//     int n = 0;
//     scanf("%d",&n);
//     int i = 0;
//     int sum= 1; 
//     for(i = 1;i<=n;i++)
//     {
//         sum *= i;
//     }
//     printf("%d",sum);
// }

//顺序打印一个整数的每一位
// void print(int n)
// {
//     if(n>9)
//     {
//         print(n/10);
//     }
//     printf("%d ",n%10);
// }
// int main()
// {
//     int n = 0;
//     scanf("%d",&n);
//     print(n);
//     return 0;
// }


//求斐波那契
// int Fab(int n )
// {
//     if (n <=2)
//     {
//         return 1;
//     }
//     else
//     {
//         return Fab(n-1)+Fab(n-2);
//     }
// }
// int main()
// {
//     int n = 0;
//     scanf("%d",&n);
//     int ret = Fab(n);
//     printf("%d\n",ret);
//     return 0;
// }  //递归法 冗余计算 容易栈溢出 overflow

// int Fab(int n)
// {
//     int a  =1;
//     int b = 1;
//     int c = 1;
//     while(n>2)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//         n--;
//     }
//     return c;
// }


//青蛙跳台阶问题 汉诺塔问题 类似 留到09 05 进行看