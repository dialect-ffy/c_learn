#include "SeqStack.h"
//1.栈的初始化
void StackInit(Stack*s)
{
    assert(s);
    s->arr = (STDataType *)malloc(sizeof(STDataType )*4);
    if(NULL == s->arr)
    {
        printf("lose");
        exit(-1);
    }
    s->top = 0;
    s->capacity = 4;
}
//2.栈的销毁
void StackDestroy(Stack*s)
{
    if(s->arr)
    {
        free(s->arr);
        s->arr = NULL;
        s->capacity=0;
        s->top = 0;
    }
}
//3.x元素入栈
void StackPush(Stack*s,STDataType x)
{
    assert(s);
    //考虑扩容
    if(s->top == s->capacity)
    {
       STDataType* tmp =(STDataType *)realloc(s->arr,sizeof(STDataType) * s->capacity*2);
       if(tmp == NULL)
       {
            printf("lose");
            exit(-1);
       }
       s->arr = tmp;
       s->capacity*=2;
    }
    s->arr[s->top] = x;
    s->top++;
}
//4.判断是否为空
bool StackEmpty(Stack*s)
{
    assert(s);
    return s->top==0;
}
//5.将栈顶元素出栈 并返回
STDataType StackPop(Stack*s)
{
    assert(s);
    assert(!StackEmpty(s));
    STDataType x = s->arr[s->top-1];
    s->top--;
    return x;
}
//6.获取栈顶元素并返回
STDataType StackTop(Stack*s)
{
    assert(s);
    assert(!StackEmpty(s));
    return s->arr[s->top-1];

}
//7.获取元素中的有效元素个数
int StackSize(Stack*s)
{
    assert(s);
    return s->top;
}
