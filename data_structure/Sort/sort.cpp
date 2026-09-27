#include "sort.h"
//1.插入排序  升序
//先看单个是如何移动的
// void InsertSort(int *a,int n)
// {
//     int end;
//     int tmp = [end + 1];
//     while(end>=0)
//     {
//         if(tmp < a[end + 1]) //向后移动
//         {
//             a[end+1] = a[end]
//             end--;
//         }
//         else{
//             break;
//         }
//     }
//     a[end + 1] = tmp;
// }
//接下来是完全体 一个一个插入进行排序
void InsertSort(int*a,int n)
{
    for(int i = 0;i<n-1;i++)//不能越界
    {
        int end = i;
        int tmp = a[end+1]
        while(end >=0)
        {
            if(tmp < a[end])
            {
                a[end+1] = a[end];
                end--;
            }
            else{
                break;
            }
        }
        a[end + 1] = tmp;
    }
}
//2.折半排序  利用二分查找找到应该插入的位置 但是最后还是要一个一个往后移动 只是确定位置快了一些
//3.希尔排序
//Tips： 即先进行间隔为d 的预排序 再进行插入排序 效果更好一点
void ShellSort(int *a ,int n)
{
    int d = n;
    while(d>1)  //多次进行预排序
    {
        d = d / 3 + 1;
        for(i=0;i<n-d;i++) //几组同时进行 //for(i=0;i<n-d;i+=d)  一组一组进行
        {
            int end = i;
            int tmp = a[end + d];
            while(end >=0)
            {
                if(tmp < a[end])
                {
                    a[end+d] = a[end];
                    end-=d;
                }
                else{
                    break;
                }
            }
            a[end + d] = tmp;
        }
    }
}
