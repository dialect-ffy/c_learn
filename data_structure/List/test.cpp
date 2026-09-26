// #include "List.h"

// int main()
// {
//     LNode* L = ListInit();
//     ListPushBack(L, 1);
//     ListPushBack(L, 2);
//     ListPushBack(L, 3);
//     ListPushFront(L, 0);
//     ListPrint(L);
//     printf("size = %d\n", ListSize(L));
//     printf("empty = %d\n", ListEmpty(L));

//     ListPopBack(L);
//     ListPopFront(L);
//     ListPrint(L);

//     ListInsert(L, 0, 100);
//     ListPrint(L);
//     printf("delete = %d\n", ListDelete(L, 0));
//     ListPrint(L);

//     LNode* p = ListLocateElem(L, 2);
//     printf("locate 2 = %p, data = %d\n", (void*)p, p ? p->data : -1);

//     ListDestroy(L);
//     L = NULL;
//     return 0;
// }
