#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
// Heap.h
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int HeapDataType;
typedef struct {
    HeapDataType * a;
    int size;
    int capacity;
}Heap;
//1.交换
void Swap(int * x,int *y);
//2.向上调整算法
void AdjustUp(HeapDataType *a,int child);
//3.插入
void HeapPush(Heap* hp,HeapDataType x);
//堆的删除时删除根的数据 那样才有意义 也就是堆顶 将堆顶与最后一个元素对调 size--即完成 然后运用向下调整排序即可
//4.删除
void HeapPop(Heap*hp);
//5.删除后进行向下调整排序
void AdjustDown(HeapDataType * a,int n,int parent);
//6.排序
void Heapsort(int * a,int n);
//7.初始化
void HeapInit(Heap*hp);
//8.利用给定的数组初始化建堆--> 包含在了 Heapsort里面
void HeapInitArray(Heap * hp,HeapDataType * a,int n);
//9.堆的销毁
void HeapDestroy(Heap * hp);
//10.获取堆顶数据
HeapDataType HeapTop(Heap* hp);
//11. 判空 
int HeapEmpty(Heap*hp);
//12.获取堆的数据的个数
int HeapSize(Heap * hp);


