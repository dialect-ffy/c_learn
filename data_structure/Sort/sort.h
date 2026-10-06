#include <stdio.h>
#include <stdlib.h>
//1.插入排序  升序
void InsertSort(int*a,int n);
//2.折半排序  利用二分查找找到应该插入的位置 但是最后还是要一个一个往后移动 只是确定位置快了一些
//3.希尔排序
//Tips： 即先进行间隔为d 的预排序 再进行插入排序 效果更好一点
void ShellSort(int *a ,int n);
void Swap(int *x , int * y);
void AdjustDown(int *a , int n,int parent);
void Heapsort(int * a,int n);
void MergeSort(int * a,int n);
void CountSort(int * a,int n);