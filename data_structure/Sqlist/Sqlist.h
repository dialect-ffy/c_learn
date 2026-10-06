#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int SqDataType;
typedef struct 
{
    SqDataType * arr;
    int size;
    int capacity;
    /* data */
}Sqlist;
//接下来是对顺序表的各种操作

//1.初始化顺序表
void SqlistInit(Sqlist * ps);
//2.销毁顺序表
void SqlistDestroy(Sqlist * ps);
//3.返回顺序表中的第i个下标位置的元素的值
SqDataType GetElem(Sqlist*p,int i);
//4.返回第一个等于x的数据元素的下标，若不存在返回-1
int LocateElem(Sqlist* ps,SqDataType x);
//5.在顺序表中的第i个位置插入元素x
void SqlistInsert(Sqlist*ps,int i,SqDataType x);
//6.删除顺序表中的第i个元素，并返回删除的值
SqDataType SqlistDelete(Sqlist*ps,int i);
//7.打印顺序表中的元素
void SqlistPrint(Sqlist *ps);
//8.检测顺序表是否为空，空返回true，否则返回false
bool EmptySqlist(Sqlist*ps);
//9.获取顺序表中有效元素个数
SqDataType SqlistSize(Sqlist*ps);
//10.尾插
void SqlistPushBack(Sqlist*ps,SqDataType x);
//11.头插
void SqlistPushFront(Sqlist*ps,SqDataType x);
//12 尾删
void SqlistPopBack(Sqlist*ps);
//13 头删
void SqlistPopFront(Sqlist*ps);


