// #include <stdio.h>
// #include <stdlib.h>
// //Think : 首先我们要等到两个链表来存入我们所需要的数据
// //非降序 data1 <= data2 只需要把新数据不断尾插即可
// //其次我们需要p1 p2 两个结点来遍历这两个链表 比较大小 不断尾插到新链表之中
// //如果有一个为链表为0 tail直接指向另一个不为0的链表
// typedef struct Node{
//     int val;
//     struct Node* next;
// }Node;
// int main()
// {
//     Node*h1 = NULL,*t1 = NULL,*h2 = NULL,*t2 = NULL;
//     int x;
//     while(scanf("%d",&x) == 1 && x!= -1)
//     {
//         Node* newNode = (Node*)malloc(sizeof(Node));
//         newNode->val = x;
//         newNode->next = NULL;
//         if(h1 == NULL)
//         {
//             h1 = t1 = newNode;
//         }
//         else{
//             t1->next = newNode;
//             t1 = newNode;//更新尾结点
//         }

//     }
//     while(scanf("%d",&x) == 1 && x!= -1)
//     {
//         Node* newNode = (Node*)malloc(sizeof(Node));
//         newNode->val = x;
//         newNode->next = NULL;
//         if(h2 == NULL)
//         {
//             h2 = t2 = newNode;
//         }
//         else{
//             t2->next = newNode;
//             t2 = newNode;//更新尾结点
//         }

//     }
//     //接下来正式开始进行排序
//     Node dummy;
//     Node* tail = &dummy;
//     tail->next = NULL;
//     Node*p1 = h1;
//     Node*p2 = h2;
//     while(p1 && p2)
//     {
//         if(p1->val < p2->val)
//         {
//             tail->next = p1;
//             tail = p1;
//             p1 = p1->next;
//         }
//         else{
//             tail->next = p2;
//             tail = p2;
//             p2 = p2->next;
//         }
//     }
//     if(p1)
//     tail->next = p1;
//     if(p2)
//     tail->next = p2;
//     if(dummy.next == NULL)
//     {
//         printf("NULL");
//     }
//     else{
//         Node* cur = dummy.next;
//         while(cur)
//         {
//             printf("%d->",cur->val);
//             cur = cur->next;
//         }
//     }
//     return 0;
// }
