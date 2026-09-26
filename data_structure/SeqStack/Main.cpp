#include "SeqStack.h"
int main()
{
    Stack s;
    StackInit(&s);//初始化
    StackPush(&s,1);
    StackPush(&s,2);
    StackPush(&s,3);
    StackPush(&s,4);
    StackPush(&s,5);
    printf("pop->%d\n",StackPop(&s));
    printf("%d\n",StackPop(&s));
    printf("%d\n",StackPop(&s));
    printf("%d\n",StackPop(&s));
    printf("%d\n",StackPop(&s));
    return 0;
}