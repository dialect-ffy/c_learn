// #pragma once
// #define _CRT_SECURE_NO_WARNINGS 1
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <assert.h>
// typedef int LDataType;
// //单链表 存放数据 + 下一个结点的地址
// typedef  struct ListNode {
//     LDataType data;
//     ListNode* next;
// }LNode,*LinkList;
// //LinkList 等价于 LNode*
// //单链表分带哨兵位和不带哨兵位的，带哨兵位的更加方便一点
// //同时哨兵位的data这一栏可以存放数据的个数，而next就是第一个有效节点的地址
// #define _CRT_SECURE_NO_WARNINGS 1
// //1.创建一个新结点
// LNode * BuyListNode(int data);
// //2.初始化链表
// LNode* ListInit();  //直接返回一个地址
// //3.打印链表
// void ListPrint(LNode* L);
// //4.获取链表中有效元素个数
// int ListSize(LNode*L);
// //5.获取链表中第⼀个数据等于x结点的地址，若不存在返回NULL指针
// LNode* ListLocateElem(LNode*L,LDataType x);
// //6.返回链表中下标为i的结点
// LNode* ListGetElem(LNode*L,int i);
// //7.在链表的第i个下标位置插⼊元素x
// void ListInsert(LNode*L,int i,LDataType x);
// // 8删除链表中下标为i的结点，并⽤x带出结点的值
// LDataType ListDelete(LNode*L,int i);
// //9.//检测链表是否为空
// bool ListEmpty(LNode*L);
// //10.头插
// void ListPushFront(LNode*L,LDataType x);
// //11.尾插
// void ListPushBack(LNode* L,LDataType x);
// //12.头删
// LDataType ListPopFront(LNode*L);
// //13.尾删
// LDataType ListPopBack(LNode*L);
// //14.销毁链表
// void ListDestroy(LNode*L);
            