#include "LinkQueue.h"
//1.初始化队列
void QueueInit(LinkQueue*q)//由于带头结点 初始化就是让队首 队尾都指向头结点 然后q->size = 0即可
{
    assert(q);
    q->front = q->rear = (QNode*)malloc(sizeof(QNode));
    if(NULL == q->front)
    {
        printf("lose\n");
        exit(-1);
    }
    q->front->next = NULL;
    q->size = 0;
}
//2.销毁队列
void QueueDestroy(LinkQueue*q)
{
    assert(q);
    QNode * cur = q->front->next;
    while(cur)
    {
        QNode * next = cur->next;
        free(cur);
        cur = next;
    }
    q->size = 0;
    free(q->front);
    q->front = q->rear = NULL; // q->rear结点肯释放了 但是没有置空 要手动置空
    
}
//3.检测队列是否为空 空返回真
bool QueueEmpty(LinkQueue * q)
{
    assert(q);
    return q->size == 0;
}
//4.获取队列中有效元素个数
int QueueSize(LinkQueue * q)
{
    assert(q);
    return q->size;
}
//5.获取队头元素
QDataType QueueFront(LinkQueue * q)
{
    assert(q);
    return q->front->next->data;
}
//6.将x入列  //尾插  对于链式队列来说肯定要有 新结点才能插入
void EnQueue(LinkQueue * q , QDataType x)
{
    assert(q);
    QNode * newNode  = (QNode * )malloc(sizeof(QNode));
    if(NULL == newNode )
    {
        printf("lose\n");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;
    q->rear->next = newNode;
    q->rear = newNode;
    q->size++;
}
//7.出队
QDataType DeQueue(LinkQueue * q)
{
    assert(q);
    assert(!QueueEmpty(q));
    QDataType x = q->front->next->data;
    QNode * DeNode = q->front->next;
    q->front->next = DeNode->next;
    if(DeNode == q->rear)
    q->rear = q->front;
    free(DeNode);
    q->size--;
    return x;
}
