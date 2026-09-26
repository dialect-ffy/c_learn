#include "Heap.h"
void TestHeap1()
{
    int a[] = {4,2,8,1,5,6,9,7,3,2};
    Heap* h;
    HeapInit(h);
    int n = sizeof(a) / sizeof(a[0]);
    for(int i = 0;i<n;i++)
    {
        HeapPush(h,a[i]);  //添加的过程中一直在排序
    }
    for(int i = 0 ;i<n;i++)
    {
        printf("%d ",h->a[i]);
    }
}
int main()
{
    TestHeap1();
    return 0;
}