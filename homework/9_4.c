#include <stdio.h>
// int main()
// {
//     int arr[100] = {0};
//     int i = 0;
//     int sz = 0;
//     printf("please input the shuliang");
//     scanf("%d",&sz);
//     printf("please input nums");
//     for (i=0;i<sz;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     for (i=0;i<sz;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
//     int result = 0;
//     for(i=0;i<sz;i++)
//     {
//         result = result ^ arr[i];
//     }
//     printf("%d",result);
    
//     return 0;


// }

//数 9 的个数
// int main()
// {
//     int i = 0;
//     int count = 0;

//     for(i=0;i<=100;i++)
//     {
//         if(i / 10 == 9 && i % 10 != 9)
//         {
//             count++;
//         }
//         else if(i /10 != 9 && i % 10 == 9)
//         {
//             count++;
//         }
//         else if(i == 99)
//         {
//             count += 2;
//         }
//     }
//     printf("%d",count);
//     return 0;
// }

//分数求和
// int main()
// {
//     int i = 0;
//     double result = 0.0;
//     int c = 1;
//     for(i=1;i<=100;i++)
//     {
//         result +=   c*(1.0/i);
//         c = -c;
//     }
//     printf("%f",result);
//     return 0;
// }

//求10个整数中的最大值
// int main()
// {
//     int arr[10] = {0};
//     int i = 0;
//     printf("please input-->\n");
//     for(i=0;i<10;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     for(i = 0;i<10;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
//     int result = 0;
//     for(i=0;i<10;i++)
//     {
//         if(result < arr[i])
//         {
//             result = arr[i];
//         }
//     }
//     printf("%d",result);
//     return 0;
// }

//打印3的倍数的数
// int main()
// {
//     int i = 0;
//     for(i = 0;i<=100;i++)
//     {
//         if (i % 3 == 0)
//         {
//             printf("%d ",i);
//         }
//     }
//     return 0;
// }


//交换数组
//将数组A中的内容和数组B中的内容进行交换（数组一样大）
// int main()
// {
//     int i = 0;
//     int arr1[] = {1,2,3,4,5,6};
//     int arr2[] = {6,5,4,3,2,1};
//     for(i=0;i<6;i++)
//     {
//         printf("%d ",arr1[i]);
//     }
//     printf("\n");
//     for(i=0;i<6;i++)
//     {
//         printf("%d ",arr2[i]);
//     }
//     printf("\n");

//     for(i=0;i<6;i++)
//     {
//         int tmp = arr1[i];
//         arr1[i] = arr2[i];
//         arr2[i] = tmp;
//     }
//     for(i=0;i<6;i++)
//     {
//         printf("%d ",arr1[i]);
//     }
//     printf("\n");
//     for(i=0;i<6;i++)
//     {
//         printf("%d ",arr2[i]);
//     }
//     printf("\n");
//     return 0;

// }


// //输入10个整数，求平均值
// int main()
// {
//     int arr[10] = {0};
//     int i = 0;
//     int sum = 0;
//     printf("please input-->\n");
//     for(i=0;i<10;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     for(i=0;i<10;i++)
//     {
//         sum += arr[i];
//     }
//     printf("%f",sum / 10.0);
//     return 0;
    

// }