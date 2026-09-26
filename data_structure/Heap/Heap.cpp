#include "Heap.h"
//1.交换
void Swap(int * x,int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
//2.向上调整建堆
void AdjustUp(HeapDataType *a,int child)
{
    assert(a);
    int parent = (child -1) / 2;
    while(child > 0)
    {
        if(a[child] < a[parent])
        {
            Swap(&a[child],&a[parent]);
            child = parent;
            parent = (child-1) / 2;
        }
        else{
            break;
        }
    }

}
//3.插入
void HeapPush(Heap* hp,HeapDataType x)
{
    assert(hp);
    if(hp->size == hp->capacity)
    {   
        int newcapacity = hp->capacity == 0 ? 4 : hp->capacity*2;
        HeapDataType *tmp = (HeapDataType *)realloc(hp->a,sizeof(HeapDataType) * newcapacity);
        if(NULL == tmp)
        {
            printf("realloc lose");
            exit(-1);
        }
        hp->a = tmp;
        hp->capacity = newcapacity;
    }
    hp->a[hp->size] = x;
    hp->size++;
    //再进行向上调整
    AdjustUp(hp->a,hp->size - 1);
}
//5.删除后进行向下调整建堆
void AdjustDown(HeapDataType * a,int n,int parent)
{
    assert(a);
    int child = parent * 2 + 1;
   
    while(child < n)
    {   
       
        if(child + 1 < n && a[child+1] < a[child] )
        child++;
        if(a[child] < a[parent])
        {
            Swap(&a[child] ,&a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else{
            break;
        }
    }


}
//4.删除
void HeapPop(Heap*hp)
{
    assert(hp);
    assert(hp->size != 0);
    Swap(&hp->a[0] , &hp->a[hp->size - 1]);
    hp->size--;
    AdjustDown(hp->a,hp->size,0);
}
//6.建堆
// 方法1  一个for 循环 遍历  一直用向上调整 相当于把新加入的都放到child上一直比较
// 方法2    一个for循环 从第一个非叶结点开始 向上遍历 一直用向下调整排序即可
void Heapsort(int * a ,int n)
{
    //建堆
    for(int i = (n-1-1) / 2;i >=0 ; i--)
    {
        AdjustDown(a,n,i);//向下调整排序 parent
    }
    //接下来进行排序
    int j = 0;
    //升序排列建大根堆 每次都把最大的放到了最后面 
    while(j<n)
    {
        Swap(&a[0] , &a[n-j]);
        AdjustDown(a,n-j,0);
        j++;
    }
}
//根据数组建堆
void HeapInitArray(Heap * hp,HeapDataType * a,int n)
{
    assert(hp);
    int i = 0;
    hp->a = (HeapDataType *)malloc(sizeof(HeapDataType) * n);//申请空间
    //拷贝
    memcpy(hp->a,a,sizeof(HeapDataType) * n);  //不会影响原数组
    hp->size = n;
    hp->capacity = n;

    for(i=(n-1-1) / 2;i >=0;i--)
    {
        AdjustDown(hp->a,n,i);  //
    }

}
//7.初始化
void HeapInit(Heap*hp)
{
    assert(hp);
    hp->a = NULL;
    hp->size = 0;
    hp->capacity = 0;
    //直接清空 用的时候再申请空间就行
}
//9.堆的销毁
void HeapDestroy(Heap * hp)
{
    assert(hp);
    if(hp->a)
    {
        free(hp->a);
        hp->a = NULL;
        hp->size = 0;
        hp->capacity = 0;
    }
}
//10.获取堆顶数据
HeapDataType HeapTop(Heap* hp)
{
    assert(hp);
    assert(hp->size != 0);
    return hp->a[0];
}
//11. 判空 
int HeapEmpty(Heap*hp)
{
    assert(hp);
    if(hp->size ==0)
        return -1;
    return 1;
}
//12.获取堆的数据的个数
int HeapSize(Heap * hp)
{
    assert(hp);
    return hp->size;
}
