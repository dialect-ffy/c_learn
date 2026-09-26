#include "LinkStack.h"
//1.初始化
void LinkStackInit(LinkStack*s)
{
    assert(s);
    s->topHead = NULL;
    s->size = 0;
}
//2.销毁链式栈
void LinkStackDestroy(LinkStack*s)
{
    assert(s);
    LSNode * cur = s->topHead;
    while(cur)
    {
        LSNode* next = cur->next;
        free(cur);
        cur = next;
    }
    s->topHead = NULL;
    s->size = 0;
}
//3.x入栈  结合着图去理解
void LinkStackPush(LinkStack * s,STDataType x)
{
    assert(s);
    //申请新结点
    LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
    if(NULL==newNode)
    {
        printf("lose");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = s->topHead;
    s->topHead = newNode;  //头插  这样newHead 一直指向 的时后面插入的 出栈时直接进行头删即可
    s->size++;
}
//6.检验是否为空
bool LinkStackEmpty(LinkStack*s)
{
    assert(s);
    return s->topHead == NULL;
}
//4.出栈
STDataType LinkStackPop(LinkStack*s)
{
    assert(s);
    assert(!LinkStackEmpty(s));//已知不为空
    STDataType top = s->topHead->data;
    LSNode*deleNode = s->topHead;
    s->topHead = deleNode->next;
    free(deleNode);
    s->size--;
    return top;
}
//5.获取栈中元素个数
int ListSize(LinkStack * s)
{
    assert(s);
    return s->size;
}



