#include "sort.h"
//1.插入排序  升序
//先看单个是如何移动的
// void InsertSort(int *a,int n)
// {
//     int end;
//     int tmp = [end + 1];
//     while(end>=0)
//     {
//         if(tmp < a[end + 1]) //向后移动
//         {
//             a[end+1] = a[end]
//             end--;
//         }
//         else{
//             break;
//         }
//     }
//     a[end + 1] = tmp;
// }
//接下来是完全体 一个一个插入进行排序
void InsertSort(int*a,int n)
{
    for(int i = 0;i<n-1;i++)//不能越界
    {
        int end = i;
        int tmp = a[end+1]
        while(end >=0)
        {
            if(tmp < a[end])
            {
                a[end+1] = a[end];
                end--;
            }
            else{
                break;
            }
        }
        a[end + 1] = tmp;
    }
}
//2.折半排序  利用二分查找找到应该插入的位置 但是最后还是要一个一个往后移动 只是确定位置快了一些
//3.希尔排序
//Tips： 即先进行间隔为d 的预排序 再进行插入排序 效果更好一点
void ShellSort(int *a ,int n)
{
    int d = n;
    while(d>1)  //多次进行预排序
    {
        d = d / 3 + 1;
        for(i=0;i<n-d;i++) //几组同时进行 //for(i=0;i<n-d;i+=d)  一组一组进行
        {
            int end = i;
            int tmp = a[end + d];
            while(end >=0)
            {
                if(tmp < a[end])
                {
                    a[end+d] = a[end];
                    end-=d;
                }
                else{
                    break;
                }
            }
            a[end + d] = tmp;
        }
    }
}
//
void Swap(int *x , int * y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
//3.选择排序
void SelectSort(int *a ,int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int min= i;
        for(int j = i+1;j<n;j++)
        {
            if(a[j] < a[min])
                min = j;//最小值的位置
        }
        //接下来把最小值放到前面
        if(min != i)
        Swap(&a[min],&a[i]);
    }
}
//4.堆排序
//(1) 向下调整建堆
void AdjustDown(int *a , int n,int parent)
{
    int child = parent * 2 + 1;
    while(child < n)
    {
        if(child + 1 < n && a[child + 1] < a[child])
        child++;
        if(a[child] < a[parent])
        {
            Swap(&a[child],&a[parent]);
            parent = child;
            child = parent * 2  + 1;
        }
        else{
            break;
        }
    }
}
void Heapsort(int * a,int n)//给定一个数组 以及数量 先建堆 再排序
{
    for(i = (n -1 -1) / 2;i >= 0 ;i -- )
    {
        AdjustDown(a,n,i);
    }
    //现在进行排序 每次取出最小的与最后一个换位置 这样就排的降序     
    int j = 1 ;
    while(j < n)
    {
        Swap(&a[0],&a[n-j]);
        AddjustDown(a,n-j,0);
        j++;
    }

}
//5.BubbleSort 比较相邻的树
void Bubblesort(int *a , int n)
{
    for(int i = 0;i<n;i++){
        int flag = 0;
        for(int j = 1;j<n-i;j++){
            if(a[j-1] > a[j]){
                Swap(&a[j-1],&a[j]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
   
}
//6.qsort
void QuickSort(int *a , int left,int right)
{
    if(left >= right)
        return ;  //区间只有1 个或没有 不用排
    int pivotkeyi = PartitionDigHole(a,left ,right); //找到那个值
    //递归左右区间
    QuickSort(a,left,pivotkeyi - 1);
    QuickSort(a,pivotkeyi + 1,right);
}
//挖坑法 用最左边的值叫做枢纽基准值 然后取出存到pivotkeyi 右边找比他小的放到左边 
//然后左边找到比它大的放到右边 最后left right 会相遇 相遇的那个点就是基准值要放的位置
int PartitionDigHole(int*a,int left,int right)
{
    int pivotkeyi = a[left];
    while(left < right)
    {
        while(left < right && a[right] >= pivokeyi){
            right--;
        }
        a[left] = a[right];
        while(left < right && a[left] <= pivoketi){
            left++;
        }
        a[right] = a[left];
    }
    a[left] = pivokeyi;
    return left;
}   
int PartitionLomuto(int*a,int left,int right)
//即定义cur prev 然后找比基准值小的 与++prev 所在的位置互换 直到cur 到最后 最后再换一次 返回即可
{
    int pivokeyi = right;
    int cur = left;
    int prev = left - 1;
    while(cur < pivokeyi)
    {
        if(a[cur] < a[pivokeyi] && ++prev != cur)
            Swap(&a[cur] ,&a[prev]);
        cur++;
    }
   
    Swap(&a[++prev],&a[right]);
    return prev;
}
int PartitionHoare(int*a,int left ,int right)
{
    int pivokey = a[left]; //选择第一个元素为pivokey
    int low = left-1;
    int high = right+1;
    while(true){
        do{
            low++;
        }while(a[low] < pivokey);//从左到右找第一个 大于的
        do{
            high--;
        }while(a[high] > piovokey); //从右向左找第一个小于的
        if(low >= high)
            return high;
        Swap(&a[low],&a[high]);
    }
}
void QuickSortHoare(int* a, int left, int right) {
    if (left >= right)
    return;
    int pivoti = PartitionHoare(a, left, right);
    // 序列被分割为[left,pivoti]和[pivoti+1,right]，[left,pivoti]的值⼩于等于
    //pivotkey，
    // [pivoti+1,right]⼤于等于pivotkey，Hoare法单趟分割并没有确定pivotkey作为主
    元分割区间
    // 所以递归时，⼀定要注意左区间包含分割点pivoti，这点跟挖坑法和Lomuto法是不⼀样
    的，⼀定要注意
    // [left, pivoti] [pivoti+1, right]
    QuickSortHoare(a, left, pivoti);
    QuickSortHoare(a, pivoti + 1, right);
}
//7.归并排序
//Think: 如果将一个数组分成两个子数组 ，如果两个子数组有序了 那么将两个数组归并一下 ，整体就有序了
//因此我们可以采取分治思想来解决这个问题
void _MergeSort(int *a,int*tmp,int begin,int end)
{
    if(begin >= end)
    return; //说明只有一个 不需要排了 本身有序
    int mid = begin + (end - begin) / 2;
    _MergeSort(a,tmp,begin,mid);
    _MergeSort(a,tmp,mid+1,end);
    //接下来开始进行合并
    int begin1 = begin,end1 = mid;
    int begin2 = mid+1,end2 = end;
    int i = begin;
    while(begin1<=end1 && begin2 <= end2)
    {
        if(a[begin1] < a[begin2]){
            tmp[i++] = a[begin1++];
        }
        else{
            tmp[i++] = a[begin2++];
        }
    }
    while(begin1 <= end1)
        tmp[i++] = a[begin1++];
    while(begin2 <= end2)
        tmp[i++] = a[begin2++];
    //拷贝回a 原数组
    // while(begin <= end)
    // {
    //     a[begin] = tmp[begin];
    //     begin++;
    // }
    memcpy(a+begin,tmp+begin,(end-begin+1) * sizeof(int));

}
void MergeSort(int *a,int n)
{
    int * tmp = (int *)malloc(sizeof(int) * n);
    if(NULL == tmp)
    {
        perror("mallco fail");
        return;
    }
    _MergeSort(a,tmp,0,n-1);
    free(tmp);
    tmp = NULL;
}
//时间复杂度 n*logn

//每一层都相当于是N个元素进行归并
//8.计数排序
//通过统计每个元素出现的个数来进行排序
//首先找到最大值 最小值 确定count开辟的大小
//然后遍历统计元素个数
//每个count++前面的 count里面存的是大于等于这个数的效果
//从后往前遍历 放到对应的位置上 （稳定性）
void CountSort(int *a,int n)
{
    int min = a[0] , max = a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    int range = max - min + 1;
    //接下来开辟count 空间 我就不考虑开辟失败了
    int * count = (int *)malloc(sizeof(int) * range);
    //统计元素个数
    for(int i = 0;i<n;i++)
    {
        count[a[i] - min]++;
    }
    //将count 中存的数转变成小于等于他的数 都++ 前一个
    //相当于获得他的位序
    for(int i = 1;i<range;i++)
    {
        count[i] += count[i-1];
    }
    //开辟tmp空间 准备放入 不考虑失败
    int * tmp = (int*)malloc(sizeof(int) * n);
    //从后往前遍历 排序
    for(int i = n-1;i>=0;i--)
    {
        tmp[count[a[i]-min] - 1] = a[i];
        count[a[i]-min]--;
    }
//    int j = 0;
//    for(i=0;i<n;i++)
//    {
//         while(count[i]--)
//         {
//             a[j++] = i + min;
//         }
//    }
    //拷贝
    memcpy(a,tmp,sizeof(int) * n);
    free(count);
    free(tmp);



}
//空间复杂度O(n+range)