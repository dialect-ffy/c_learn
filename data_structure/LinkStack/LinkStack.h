//接下来使用链表来完成这个栈
//对于链式栈来说 为了方便 要头插 即左边为栈顶
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <stdbool.h>
typedef int STDataType;
//首先我们要定义结点 存放数据和下一个结点的地址
typedef struct LinkStackNode
{
    struct LinkStackNode* next;
    STDataType data;
}LSNode;
//其次我们要定义链式栈  结点+ 大小
typedef struct   
{
    LSNode * topHead;
    int size;
}LinkStack;  //所以这个结构体其实本质上就是一个头结点 指向栈顶
//1.初始化
void LinkStackInit(LinkStack*s);
//2.销毁链式栈
void LinkStackDestroy(LinkStack*s);
//3.x入栈
void LinkStackPush(LinkStack * s,STDataType x);
//4.出栈
STDataType LinkStackPop(LinkStack*s);
//5.获取栈中元素个数
int ListSize(LinkStack * s);
