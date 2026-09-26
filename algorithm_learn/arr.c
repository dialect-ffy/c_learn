#include <stdio.h>
//1.二分查找
//条件:  有序  无重复元素 
//看把target 定义在哪一个区间里面 定义左闭右闭，一直都是左闭右闭
// 一般两种 左闭右闭 [left,right] 左闭右开[left,right)
//number 1:
// int search_target(int arr[],int target)
// {
//     int left = 0;
//     int right = sizeof(arr) / sizeof(arr[0]) - 1;
//     while(left <= right)  //左闭右闭 
//     {
//         int middle = left + (right - left) / 2;  //防止溢出
//         if(arr[middle] > target)
//         {
//             right = middle - 1;  
//         }
//         else if (arr[middle] < target)
//         {
//             left = middle + 1;  //会有一种情况，right - 1 之后刚好是目标值，由于整数除法，arr[middle] 依然小于目标值，这时候left+1 刚好也是目标值的下标 那么题干中的<=就有意义了
//         }
//         else
//         {
//             return middle;  //返回下标
//         }
//     }
//     return -1;
// }

//number 2:
// int search_target(int arr[],int target)
// {
//     int left = 0;
//     int right = sizeof(arr) / sizeof(arr[0]);
//     while(left < right)  //因为left == right 是无效空间左闭右开 时刻牢记区间
//     {
//         int middle = left + (right - left) / 2;
//         if(arr[middle] > target)
//         {
//             right = middle;
//         }
//         else if(arr[middle] < target)
//         {
//             left = middle + 1;
//         }
//         else
//         {
//             return middle;
//         }
        
        
//     }
//     return -1;//未找到

// }

//2.搜索插入位置

