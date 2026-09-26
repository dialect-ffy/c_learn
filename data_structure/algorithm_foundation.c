#include <stdio.h>
//数据结构三要素：逻辑结构 物理结构（存储） 数据运算和实现
//逻辑结构  线性结构   树形结构 图形结构 再同一个集合
//物理结构 顺序存储 链式存储 索引存储 散列存储
//数据运算和实现 对数据元素可以施加的操作 以及这些操作在相应的存储结构上的实现
//数据项 --> 数据元素 --> 数据对象
// int Summation(int N)
//  { // 消耗时间 执⾏次数
//     int ret = 0; // C1 1
//     int i = 1; // C2 1
//     while (i <= N) { // C3 N+1
//     ret += i; // C4 N
//     i++; // C5 N
//     }
//     return ret; // C6 1
// }
//    //O(n)


// void BubbleSort(int* a, int n) {
//     assert(a);
//     for (size_t end = n; end > 0; --end)  //最多排n-1次
//     {
//         for (size_t i = 1; i < end; ++i)   //每次将最大的放到末尾
//         {
//             if (a[i-1] > a[i]) 
//             {
//             Swap(&a[i-1], &a[i]);
//             }
//         }
//     }
// }  //O(n^2)

//接下来是矩阵乘法  量级为O(n^3)
// void MatrixMultiply(int A[][N],int B[][N],int C[][N])
// {  //要先将C初始化
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     for(i=0;i<N;i++)
//     {
//         for(j=0;j<N;j++)
//         {
//             C[i][j] = 0;
//             //由于要放入C[i][j]这个地方，因此要在2层循环下进行赋值
//             for(k=0;k<N;k++)
//             {
//                 C[i][j] += A[i][k] * B[k][j];  //对无数多项进行累加
//             }
//         }
//     }
// }  //三层循环遍历 每层循环N次  时间复杂度为O(n^3)


// void Count(int n) {
// for (int i = 1; i < n; i *= 2) 
// {
//     printf("%d\n", i);
// }
// }
// int main()
//  {
//     Count(100);
//     return 0;
// }   // 2^t > n   t = logn


// void Print100(int* a, int n) 
// {
//     for (int i = 0; i < n && i < 100; i++) 
//     {
//         printf("%d ", a[i]);
//     }
//     printf("\n");
// }  //仅常数 O（1）



// void PrintMN(int m, int n)
// {
//     for (int i = 0; i < m; ++i)
//     {
//         printf("hello\n");
//     }
//     for (int i = 0; i < n; ++i)
//     {
//         printf("hello\n");
//     }
// }  // o(M+N)


//递归算法
//通俗点说递归算法的时间复杂度等于M次递归的执⾏次数累加和。
// long long Fac(size_t N){
//     if(0 == N)
//     return 1;
//     return Fac(N-1)*N;
// }  //每次递归 执行一次if   O（n）



//空间复杂度  为了使用算法多开辟的空间
// int Summation(int N) {

//     int ret = 0;  //1
//     int i = 1;  //1
//     while (i <= N) 
//     {
//         ret += i;
//         i++;
//     }
//     return ret;
// }  //O（1）


//轮转数组
//给定⼀个整数数组 nums ，将数组中的元素向右轮转 k 个位置，其中 k 是⾮负数
//方法一 每次轮转一个 重复K次 此方法O（n^2)
// void rotate(int *nums,int numsSize;int k)
// {
//     k %= numsSize;
//     while(k--)
//     {
//         int tmp = nums[numsSize - 1];//最后一个存起来
//         //把前N-1个向后平移
//         int i = 0;
//         for(i = numsSize - 1;i > 0 ;i--)
//         {
//             nums[i] = nums[i-1];
//         }
//         nums[0] = tmp;
//     }
// }

//方法二 一次轮转多个 单独开辟一个空间存后K个
// void rorate(int *nums,int numsSize;int k)
// {
//     k %= numsSize;
//     if(k==0)
//     {
//         return ;
//     }
//     int tmp[k];
//     //先把后个存入变长数组
//     int i = 0;
//     for(i=0;i<k;i++)
//     {
//         tmp[i] = nums[n-k+i];
//     }
//     //把前N-K个向后平移
//     for(i= numsSize - 1;i > k-1;i--)
//     {
//         nums[i] = nums[i-k];
//     }
//     //拷贝回来
//     for(i=0;i<k;i++)
//     {
//         nums[i] = tmp[i];
//     }
// }  时间ON  空间 ON
//方法三 逆置
// void reverse(int *nums,int left,int right)
// {
//     while(left < right)
//     {
//         int tmp= nums[left];
//         nums[left] = nums[right];
//         nums[right] = tmp;
//         left ++;
//         right -- ;

//     }
// }
// void rotate(int*nums,int numsSize,int k)
// {
//     k%= numsSize;
//     reverse(nums,0,numsSize - 1);
//     revrese(nums,0,k-1);
//     reverse(nums,k,numsSize -1);
// }

//递归算法的空间复杂度 看递归深度 M次递归，累加每次递归的空间消耗