// #include "DCList.h"
// //1.链表初始化
// DCListNode* DCListInit()
// {
//     DCListNode* L = ( DCListNode*)malloc(sizeof(DCListNode));
//     L->next = L;
//     L-> prev = L;
//     return L;
// }
// //2.销毁链表
// void DCListDestroy(DCListNode* L)
// {
//     DCListNode* cur = L->next;
//     while(cur != L)
//     {
//         DCListNode* next = cur->next;
//         free(cur);
//         cur = next;
//     }
//     free(L);
// }
// //3.获取链表的坐标i的结点
// DCListNode* DCListGetElem(DCListNode* L,int i)
// {
//     assert(i>=0);
//     DCListNode* cur = L->next;
//     int j = 0;
//     while(cur!= L && j< i)
//     {
//         cur = cur->next;
//         j++;
//     }
//     assert(j==i);
//     return cur;
// }
// //4.BuyDCListNode
// DCListNode * BuyDCListNode(DCLDataType x)
// {
//     DCListNode * newNode = (DCListNode *)malloc(sizeof(DCListNode));
//     newNode ->x = x;
//     newNode->next = NULL;
//     newNode->prev = NULL;
//     return newNode;
// }

// //5.在pos位置插入值为x的结点
// void DCListInsert(DCListNode* pos,DCLDataType x)
// {
//     assert(pos);
//     DCListNode * newNode = BuyDCListNode(x);
//     newNode->next = pos->next;
//     pos->next->prev = newNode;
//     pos ->next = newNode;
//     newNode -> prev = pos;
// }
// //6.删除POS位置的元素
// void DCListDelete(DCListNode* pos)
// {
//     assert(pos);
//     pos->prev->next = pos->next;
//     pos->next->prev = pos->prev;
//     free(pos);
// }
// //7.头插
// void DCListPushFront(DCListNode*L,DCLDataType x)
// {
//     DCListInsert(L,x);
// }
// //8.尾插
// void DCListPushBack(DCListNode*L,DCLDataType x)
// {
//     DCListInsert(L->prev,x);
// }
// //9头删
// void DCListPopFront(DCListNode*L)
// {
//     DCListDelete(L);
// }
// //10.尾删
// void DCListPopBack(DCListNode* L)
// {
//     DCListDelete(L->prev);
// }
// //11.打印
// void DCListPrint(DCListNode*L)
// {
//     printf("head->");
//     DCListNode * cur = L->next;
//     while(cur!=L)
//     {
//         printf("%d->",cur->x);
//         cur = cur->next;
//     }
//     printf("NULL\n");
// }