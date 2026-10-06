#include "List.h"
//1.创建一个新结点
LNode * BuyListNode(int data)
{
    //不能直接创建一个LNode的结构体，这是局部变量，出了作用域就会被销毁
    LNode* newNode = (LNode *)malloc(sizeof(LNode));
    if(newNode == NULL)
    {
        printf("Can Not BuyListNode\n ");
        exit(-1);
    }
    //申请成功后，对结点中的数据域和指针域进⾏初始化
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//2.初始化链表
LNode* ListInit()//直接返回一个地址
{
    LNode* node = BuyListNode(-1);//哨兵位存-1
    return node;
}
//3.打印链表
void ListPrint(LNode* L)
{
    assert(L);
    printf("头结点->");
    LNode*cur = L->next;
    while(cur)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");

}
//4.获取链表中有效元素个数
int ListSize(LNode*L)
{
    assert(L);
    int size = 0;
    LNode*cur = L->next;
    while(cur)
    {
        size++;
        cur = cur->next;
    }
    return size;
}
//5.获取链表中第⼀个数据等于x结点的地址，若不存在返回NULL指针
LNode* ListLocateElem(LNode*L,LDataType x)
{
    assert(L);
    LNode*cur = L->next;
    while(cur)
    {
        if(cur->data == x)
        {
            return cur;
        }
        else
        {
            cur= cur->next;
        }
    }
    return NULL;
}
//6.返回链表中下标为i的结点
LNode* ListGetElem(LNode*L,int i)
{
    assert(L);
    assert(i>=0);
    LNode*iNode = L->next;
    int j = 0;
    while(iNode!=NULL && j < i)
    {
        iNode = iNode->next;
        j++;
    }
    return iNode;

}
//7.在链表的第i个下标位置插⼊元素x
void ListInsert(LNode*L,int i,LDataType x)
{
    assert(L);
    //先找到第i-1个
    LNode*i_1Node = L; //L->next;
    int j = -1;  //如果从0开始会插入到下标0和1中间
    while(j<i-1 && i_1Node!= NULL)
    {
        i_1Node = i_1Node->next;
        j++;
    }
    assert(i_1Node != NULL);
    //目前i_1Node指向了i-1的位置，接下来要让他指向要插入的那个元素的地址
    LNode *newNode = BuyListNode(x);
    newNode->next = i_1Node->next;
    i_1Node->next = newNode;
    
}
// 8删除链表中下标为i的结点，并⽤x带出结点的值
LDataType ListDelete(LNode*L,int i)
{
    assert(L);
    assert(i>=0);
    LNode*i_1Node = L;
    int j = -1;
    while(j<i-1 && i_1Node != NULL)
    {
        i_1Node= i_1Node->next;
        j++;
    }
    assert(i_1Node != NULL);
    LNode* iNode = i_1Node->next;
    assert(iNode != NULL);
    
    LDataType x  =iNode->data;
    i_1Node->next = i_1Node->next->next;
    free(iNode);
    iNode = NULL;
    return x;

}
//9.检测链表是否为空，空返回true，否则返回false
bool ListEmpty(LNode*L)
{
    assert(L);
    return L->next == NULL;
}
//10.尾插
void ListPushBack(LNode*L,LDataType x)
{
    assert(L);
    LNode*tail = L;
    while(tail->next)
    {
        tail = tail->next;
    }
    LNode*newNode = BuyListNode(x);
    tail->next = newNode;
}
//11.头插
void ListPushFront(LNode*L,LDataType x)
{
    assert(L);
    LNode*newNode = BuyListNode(x);
    newNode->next = L->next;
    L->next = newNode;
}
//12.尾删
LDataType ListPopBack(LNode*L)
{
    assert(L);
    assert(L->next);
    LNode*prev = L;
    LNode*cur = L->next;
    while(cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    LDataType x = cur->data;
    prev->next = NULL;
    free(cur);
    return x;
}
//13.头删
LDataType ListPopFront(LNode*L)
{
    assert(L);
    assert(L->next);
    LNode*first = L->next;
    LDataType x = first->data;
    L->next = first->next;
    free(first);
    return x;
}
//14.销毁链表
void ListDestroy(LNode*L)
{
    assert(L);
    LNode*cur = L->next;
    while(cur)
    {
        LNode*next = cur->next;
        free(cur);
        cur = next;
    }
    free(L);
}