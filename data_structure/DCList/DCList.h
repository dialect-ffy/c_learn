// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// typedef int DCLDataType ;
// typedef struct DCListNode  //定义结构体类型   前驱 后继
// {
//     DCLDataType x;
//     struct DCListNode* prev;
//     struct DCListNode* next;
// }DCListNode;
// //1.链表初始化
// DCListNode* DCListInit();
// //2.销毁链表
// void DCListDestroy(DCListNode* L);
// //3.获取链表的坐标i的结点
// DCListNode* DCListGetElem(DCListNode* L,int i);
// //4.BuyDCListNode
// DCListNode * BuyDCListNode(DCLDataType x);
// //5.在pos位置插入如值为x的结点
// void DCListInsert(DCListNode* pos,DCLDataType x);
// //6.删除POS位置的元素
// void DCListDelete(DCListNode* pos);
// //7.头插
// void DCListPushFront(DCListNode*L,DCLDataType x);
// //8.尾插
// void DCListPushBack(DCListNode*L,DCLDataType x);
// //9头删
// void DCListPopFront(DCListNode*L);
// //10.尾删
// void DCListPopBack(DCListNode* L);
// //11.打印
// void DCListPrint(DCListNode*L);