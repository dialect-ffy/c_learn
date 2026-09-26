#include <stdio.h>
#include <assert.h>
//rear 指向的是队尾的下一个位置
typedef struct 
{
   int * a;
   int front;
   int rear;
   int N; //空间大小 队列长度尾N - 1；
} MyCircularQueue;
//1.初始化
MyCircularQueue* myCircularQueueCreate(int k);//K是队列长度
//2.销毁
void myCircularQueueFree(MyCircularQueue* obj);
//3.判空   这里我们使用牺牲一个空间的方法来区分判满和判空
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//4.判满
bool myCircularQueueIsFull(MyCircularQueue* obj);
//5.入队
bool myCircularEnQueue(MyCircularQueue * obj,int value);
//6.出队
bool myCircularQueueDeQueue(MyCircularQueue* obj);
//7.获取队首数据
int myCircularQueueFront(MyCircularQueue* obj);



