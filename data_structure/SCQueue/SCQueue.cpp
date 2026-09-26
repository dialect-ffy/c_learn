#include "SCQueue.h"
//1.初始化
MyCircularQueue* myCircularQueueCreate(int k);//K是队列长度 myCircularQueueCreate(int k);//K是队列长度
{
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj -> a = (int *)malloc(sizeof(int) * (k+1));
    obj->front = obj->rear = 0;
    obj->N = k+1;
} //初始化肯定要开辟空间  然后初始化 front rear 最后还有写上大小
//2.销毁  //即为释放空间
void myCircularQueueFree(MyCircularQueue* obj)
{
    assert(obj);
    free(obj->a);
    free(obj);
}
//3.判空   这里我们使用牺牲一个空间的方法来区分判满和判空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    assert(obj);
    return (obj->front == obj->rear);
}
//4. 判满 
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    assert(obj);
    return (obj->rear + 1)%obj->N == obj->front;
}
//5.入队
bool myCircularEnQueue(MyCircularQueue * obj,int value)
{
    assert(obj);
    assert(!myCircularQueueIsFull(obj));
    obj->a[obj->rear] = value;
    obj->rear++;
    obj->rear %= obj->N;
    return true;
}
//6.出队
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if(myCircularQueueIsEmpty(obj))
        return false;
    obj->front++;
    obj->front %= obj->N;
    return true;
}
//7.获取队首数据
int myCircularQueueFront(MyCircularQueue* obj)
{
    if(myCircularQueueIsEmpty(obj))
    return -1;
    else
    return obj->a[obj->front];

}
//8.获取队尾数据
int myCircularQueueRear(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj))
    return -1;
    else
    return obj->a[(obj->rear - 1 + obj->N) % obj->N];
}


