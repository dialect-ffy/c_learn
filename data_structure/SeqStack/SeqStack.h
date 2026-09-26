//前置知识 stack实际上就是只能在一端进行操作的线性表
//n 个 不同的数进栈出栈的顺序组合数
//Cn = 1 / (n+1) * Cn^2n;
//动态栈的定义
#pragma once
#include  <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include <stdbool.h>
typedef int STDataType;
typedef struct 
{
  STDataType *arr;  //指向栈数组空间的指针
  int top;  //栈顶位置
  int capacity;//容量
}Stack;
//1.栈的初始化
void StackInit(Stack*s);
//2.栈的销毁
void StackDestroy(Stack*s);
//3.x元素入栈
void StackPush(Stack*s,STDataType x);
//4.判断是否为空
bool StackEmpty(Stack*s);
//5.将栈顶元素出栈 并返回
STDataType StackPop(Stack*s);
//6.获取栈顶元素并返回
STDataType StackTop(Stack*s);
//7.获取元素中的有效元素个数
int StackSize(Stack*s);