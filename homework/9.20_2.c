// #include <stdio.h>
// #include <stdlib.h>
// //约瑟夫环问题 与链表的删除 ListPop 极其相似 只需要实现这个功能即可
// //知道所有人出列 显然需要是一个环形链表
// //输入格式为一行正整数 第一个数字n为总人数  从1 到 n 此时搞一个链表 第二个数字为出列间隔人数
// //报m开始删除
// //输入格式为10 3
// //输出为 3 6 9 2 7 1 8 5 10 4（注意4之后不可以有空格）
// //对了 一般删除有prev cur 两个结点 方便删除后的连接
// typedef struct Node
// {
//     int val; //编号
//     struct Node* next;
// }Node;
// int main()
// {
//     int n,m;
//     if(scanf("%d %d",&n,&m) != 2) return 0;
//     if(n<=0 || m < 0) return 0;
//     //1.构造单向循环链表
//     Node* head = (Node*)malloc(sizeof(Node));
//     head->val = 1;
//     head->next = NULL;
//     Node*tail = head;
//     for(int i = 2;i<=n;i++)
//     {
//         Node* newNode = (Node*)malloc(sizeof(Node));
//         newNode->val = i;
//         tail->next = newNode;
//         tail = newNode;
//     }
//     tail->next = head;//形成单向循环链表
//     //接下来开始
//     Node* prev = tail;
//     Node* cur = head;
//     int count = 1;
//     while(n>0)
//     {
//         if(count == m)
//         {
//             if(n==1)
//                 printf("%d",cur->val);
//             else
//             {
//                 printf("%d ",cur->val);
//             }
//             prev->next = cur->next;
//             Node* tmp = cur;
//             cur = cur->next;
//             free(tmp);
//             n--;
//             count = 1;
//         }
//         else{
//             prev = cur;
//             cur = cur->next;
//             count++;
//         }
//     }
//     printf("\n");
//     return 0;
// }