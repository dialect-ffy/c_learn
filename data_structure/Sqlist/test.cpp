// #include "Sqlist.h"
// void TestSqlist1() {
//     Sqlist l;                          // 原 L → l
//     SqlistInit(&l);
//     SqlistInsert(&l, 0, 9);
//     SqlistInsert(&l, 1, 10);
//     SqlistInsert(&l, 2, 20);
//     SqlistInsert(&l, 3, 30);
//     SqlistInsert(&l, 4, 40);
//     SqlistInsert(&l, 5, 50);           // 扩容
//     SqlistPrint(&l);
//     // 头插
//     SqlistInsert(&l, 0, 0);
//     SqlistPrint(&l);
//     // 尾插
//     SqlistInsert(&l, SqlistSize(&l), 60);   // SqListSize → SqlistSize
//     SqlistPrint(&l);
//     // 中间插入
//     SqlistInsert(&l, 2, 2);
//     SqlistPrint(&l);
// }

// void TestSqlist2() {
//     Sqlist l;
//     SqlistInit(&l);
//     SqlistInsert(&l, 0, 9);
//     SqlistInsert(&l, 1, 10);
//     SqlistInsert(&l, 2, 20);
//     SqlistInsert(&l, 3, 30);
//     SqlistInsert(&l, 4, 40);
//     SqlistInsert(&l, 5, 50);           // 扩容
//     SqlistPrint(&l);
//     // 删除顺序表第1个位置上的元素
//     printf("顺序表中有效元素个数为：%d \n", SqlistSize(&l));
//     // 删除第一个数据
//     printf("删除的元素是:%d \n", SqlistDelete(&l, 0));
//     // 删除末尾的数据
//     printf("删除的元素是:%d \n", SqlistDelete(&l, SqlistSize(&l) - 1));
//     // 删除中间的数据
//     printf("删除的元素是:%d \n", SqlistDelete(&l, 2));
//     SqlistPrint(&l);
//     printf("顺序表中第%d个元素是：%d\n", 1, GetElem(&l, 1));   // GetElem 和 LocateElem 没改（因为不包含 L）
//     printf("40 的下标是%d\n", LocateElem(&l, 40));
//     SqlistDestroy(&l);
// }

// int main() {
//     TestSqlist1();
//     // TestSqlist2();
//     return 0;
// }