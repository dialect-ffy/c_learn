#include "Sqlist.h"
//1.初始化
void SqlistInit(Sqlist * ps)
{
    assert(ps);
    ps->arr = (SqDataType *)malloc(sizeof(SqDataType) * 4);
    if(ps->arr == NULL)
    {
        printf("InitSqList: 内申请空间失败!!!\n");
        return;
    }
    ps->size = 0;
    ps->capacity = 4;
}
//2.销毁
void SqlistDestroy(Sqlist * ps)
{
    assert(ps);  //即防止传入空指针，又判断
    if(ps->arr)
    {
        free(ps->arr);
        ps->size = 0;
        ps->capacity = 0;
        ps->arr = NULL;
    }
}
//3.返回第i个下标位置的值
SqDataType GetElem(Sqlist*ps,int i)
{
    assert(ps);
    assert(i >=0 && i < ps->size);
    return ps->arr[i];
    
}
//4.返回第一个等于x的数据元素的下标，若不存在返回-1
int LocateElem(Sqlist* ps,SqDataType x)
{
    assert(ps);
    for(int i=0;i<ps->size;i++)
    {
        if (ps->arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

//5.在第i个位置插入x
void SqlistInsert(Sqlist*ps,int i,SqDataType x)
{
    assert(ps);
    //考虑空间满了进行扩容
    if (ps->size == ps->capacity)
    {
        int newCapacity = ps->capacity * 2;
        SqDataType * tmp = (SqDataType *)realloc(ps->arr,sizeof(SqDataType) * newCapacity);
        if(tmp == NULL)
        {
            printf("SqListInsert: 内存申请空间失败!!!\n");
            return;
        }
        ps->arr = tmp;
        ps->capacity = newCapacity;
    }
    int j = ps->size - 1;
    while(j >= i)
    {
        ps->arr[j+1] = ps->arr[j];
        --j;
    }
    ps->arr[i] = x;
    ps->size ++;
}
//6.删除顺序表中的第i个元素，并返回删除的值
SqDataType SqlistDelete(Sqlist*ps,int i)
{
    assert(ps);
    assert(i>=0 && i<ps->size);
    SqDataType del = ps->arr[i];
    //向前平移
    for (int j = i;j<ps->size-1;j++)
    {
        ps->arr[j] = ps->arr[j+1];
    }
    ps->size --;
    return del;  //对于最后一个元素是伪删除吧
}
//7.打印顺序表中的元素
void SqlistPrint(Sqlist *ps)
{
    assert(ps);
    for(int i = 0;i<ps->size;i++)
    {
        printf("%d ",ps->arr[i]);
    }
    printf("\n");
}
//8.检测顺序表是否为空，空返回true，否则返回false
bool EmptySqlist(Sqlist*ps)
{
    assert(ps);
    return ps->size == 0;
}
//9.获取顺序表中有效元素个数
SqDataType SqlistSize(Sqlist*ps)
{
    assert(ps);
    return ps->size;
}
//10.尾插
void SqlistPushBack(Sqlist*ps,SqDataType x)
{
    assert(ps);
    SqlistInsert(ps,ps->size,x);

}
//11.头插
void SqlistPushFront(Sqlist*ps,SqDataType x)
{
    assert(ps);
    SqlistInsert(ps,0,x);
}
//12 尾删
void SqlistPopBack(Sqlist*ps)
{
    assert(ps);
    SqlistDelete(ps,ps->size - 1);
}
//13 头删
void SqlistPopFront(Sqlist*ps)
{
    assert(ps);
    SqlistDelete(ps,0);
}

