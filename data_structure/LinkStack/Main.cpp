#include "LinkStack.h"
int main()
{
    LinkStack s;
    LinkStackInit(&s);
    LinkStackPush(&s , 1);
    LinkStackPush(&s , 2);
    LinkStackPush(&s , 3);
    printf("出栈：栈顶元素为:%d\n", LinkStackPop(&s));
    printf("出栈：栈顶元素为:%d\n", LinkStackPop(&s));
    printf("出栈：栈顶元素为:%d\n", LinkStackPop(&s));
    return 0;


}