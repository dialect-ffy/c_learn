#include <stdio.h>
#include <string.h>
#include <windows.h>
// int arr1[10]
//arr1 数组的类型是int [10]
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     int i = 0;
//     for(i=0;i<10;i++)
//     {
//         printf("%d ",arr[i]);
        
        
//     }
//     return 0;
// }
// int main()
// {
//     int arr[10];
//     int i = 0;
//     for(i=0;i<10;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     for(i=0;i<10;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     int i = 0;
//     for(i = 0;i < 10;i++)
//     {
//         printf("&arr[%d] = %p\n",i,&arr[i]);

//     }
//     return 0;
// }
// sizeof 不仅可以计算类型或者变量大小，也可以计算数组大小
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     printf("%d",sizeof(arr));
//     return 0;
// }
//计算数组元素个数
// int main()
// {
//     int arr[10] = {0};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     printf("数组元素个数为:%d\n",sz);
//     return 0;
// }

//二维数组的创建
//int arr1[3][5] = {0}; // 不完全初始化 一个一个连续放
//int arr4[3][5] = {(1,2),(2,3),(3,4)};  按照行初始化
//int arr[][6] = {1,2,3,4,5,6,7,8,9,10}; 可省略行不可省略列，编译器会自动计算行数 
// int main()
// {
//     int arr[3][5] = {1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7};
//     printf("%d\n", arr[2][4]);
//     return 0;
// }
//二维数组的输入和输出
// int main()
// {
//     int arr1[3][5] = {1,2,3,4,5,2,3,4,5,6,3,4,5,6,7};
//     int i,j;
//     for(i=0;i<3;i++)
//     {
//         for(j=0;j<5;j++)
//         {
//             scanf("%d",&arr1[i][j]);
//         }
//     }
//     for(i = 0;i<3;i++)
//     {
//         for(j=0;j<5;j++)
//         {
//             printf("%d ",arr1[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
// 变长数组
// int main()
// {
//     int n = 0;
//     scanf("%d", &n);//根据输⼊数值确定数组的⼤⼩
//     int arr[n];
//     int i = 0;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }


//习题 多个字符从两端移动，向中间汇聚
// int main()
// {
//     char arr1[] = "welcome to bit...";
//     char arr2[] = "################";
//     size_t left = 0;
//     size_t right = strlen(arr1) - 1; // 不可以sizeof(arr1)-1,因为sizeof计算的是数组的总大小，会包含字符串末尾自动加的/0，strlen计算的是字符串的长度
//     printf("%s\n", arr2);
//     while (left <= right)
//     {   
//         Sleep(1000);
//         arr2[left] = arr1[left];
//         arr2[right] = arr1[right];
//         left++;
//         right--;
//         printf("%s\n", arr2);
//     }
//     return 0;
// }
// int main()
// {
//     char arr1[] = "welcome to bit...";
//     char arr2[] = "#################";
//     int left = 0;
//     int right = (int)strlen(arr1)-1;
//     printf("%s\n", arr2);
//     while(left<=right)
//     {
//         Sleep(1000);
//         arr2[left] = arr1[left];
//         arr2[right] = arr1[right];
//         left++;
//         right--;
//         printf("%s\n", arr2);
//     }
//     return 0;
// }


// 二分查找
// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int mid = 0;
//     int left = 0;
//     int key = 6;
//     int right = sizeof(arr) / sizeof(arr[0]) - 1;
//     int find = 0;
//     while(left <= right)
//     {
//         mid = (left + right) / 2;
//         if(arr[mid] > key)
//         {
//             right = mid - 1;
//         } 
//         else if (arr[mid] < key)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             find = 1;
//             break;
//         }
//     }
//     if (find == 1)
//     {
//         printf("find it,the index is %d",mid);
//     }
//     else
//     {
//         printf("can not find it");
//     }
//     return 0;

// }

//交换2个变量
// int main()
// {
//     int a = 2;
//     int b = 4;
//     printf("%d %d\n",a,b);
//     a = a ^ b;
//     b = a ^ b;
//     a = a ^ b;
//      printf("%d %d\n",a,b);

//     return 0;
// }