#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//队列 限定在一端插入 一端删除  插入的一端叫做队尾叫做入队   删除的一端叫做队头叫做出队
//我们接下来实现队列的链式存储  然后带一个头结点 将头结点置为队头 为空时位结点rear也指向队头
typedef int QDataType ;
typedef struct LinkNode
{
   QDataType data;
   struct LinkNode* next;
}QNode;
typedef struct
{
   QNode * front;
   QNode * rear;
   int size;
}LinkQueue;  //队列需要队头 队尾 以及大小
//1.初始化队列
void QueueInit(LinkQueue*q);
//2.销毁队列
void QueueDestroy(LinkQueue*q);
//3.检测队列是否为空 空返回真
bool QueueEmpty(LinkQueue * q);
//4.获取队列中有效元素个数
int QueueSize(LinkQueue * q);
//5.获取队头元素
QDataType QueueFront(LinkQueue * q);
//6.将x入列  //尾插  对于链式队列来说肯定要有 新结点才能插入
void EnQueue(LinkQueue * q , QDataType x);
//7.出队
QDataType DeQueue(LinkQueue * q);

