#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// int main()
// {
//     int num = 0;
//     scanf("%d",&num);
//     if(num % 2 == 0)
//     {
//         printf("even\n");
//     }
//     else
//     {
//         printf("odd\n");
//     }
//     return 0;
// }
// int main()
// {
//     printf("please input your age");
//     int age;
//     scanf("%d",&age);
//     if(age >= 18)
//     {
//         printf("you are a adult");

//     }
//     else
//     {
//         printf("you are a minor");
//     }
//     return 0;
// }
// int main()
// {
//     int num = 0;
//     scanf("%d",&num);
//     if (num == 0)
//     {
//         printf("zero");
//     }
//     else if (num > 0)
//     {
//         printf("positive\n");
//     }
//     else
//     {
//         printf("negative\n");
//     }
//     return 0;
// }
// int main()
// {
//     int num = 0;
//     scanf("%d",&num);
//     if (num > 0)
//     {
//         if (num % 2 == 0)
//         {
//             printf("even");
//         }
//         else
//         {
//             printf("odd");
//         }
//     }
//     else
//     {
//         printf("negative");
//     }
//     return 0;
// }
// int main()
// {
//     int age = 0;
//     scanf("%d",&age);
//     if (age < 18)
//     {
//         printf("shao nian\n");
//     }
//     else if ( age < 30)
//     {
//         printf("qing nian\n");
//     }
//     else if (age < 60)
//     {
//         printf("zhong nian\n");
//     }
//     else
//     {
//         printf("lao nian\n");
//     }
//     return 0;
// }
// int main()
// {
//     int age = 0;
//     scanf("%d",&age);
//     if (age >= 18 && age <= 60)
//     {
//         printf("adult\n");
//     }
//     return 0;
// }
//这是因为，我们先拿18和age中存放的10⽐较，表达式18<=10为假， 18<=age 的结果是0，再拿0和
//36⽐较，0<=36为真，所以打印了 ⻘年 ，所以即使当age是10的时候，也能打印 ⻘年 ，逻辑上是有
//问题，这个代码应该怎么写呢？
// 条件操作符 exp1 ? exp2 : exp3
// int main()
// {
//     int a = 5;
//     int b = 0;
//     b = a > 0 ? 1 : -1;
//     printf("b = %d\n",b);
//     return 0;
// }
// ! 逻辑取反 != 不等于
// && 逻辑与 || 逻辑或

//判断闰年
// int main()
// {
//     int year = 0;
//     scanf("%d",&year);
//     if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//     {
//         printf("rui nian\n");
//     }
//     else
//     {
//         printf("ping nian\n");
//     }
//     return 0;
// }  
// int main()
// {
//     int i = 0,a = 0,b = 2,c = 3,d = 4;
//     i = a++ && ++b && d++;
//     printf("i = %d a = %d b = %d c = %d d = %d\n",i,a,b,c,d);
//     return 0;
// }
// 逻辑运算符的短路特性 ,a 先使用，未执行++，0，右边不再进行
//switch 语句
//switch (expression)
//{
// case value1: statement
// case value2: statement
// ...
// default: statement
// }  注： 均需要整型
// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     switch(num % 3)
//     {
//         case 0:
//             printf("zhengchu");
//             break;
//         case 1:
//             printf("yushu 1");
//             break;
//         case 2:
//             printf("yushu 2");
//             break;
//         default:
//             printf("error");
//             break;
//     }
//     return 0;
// }

// while 循环
// int main()
// {
//     int i = 1;
//     while (i <= 10)
//     {
//         printf("%d\n",i);
//         i++;
//     }
//     return 0;
// }
// int main()
// {
//     int num = 0;
//     scanf("%d",&num);
//     while (num > 0)
//     {
//         printf("%d ",num % 10);
//         num /= 10;
//     }
//     return 0;
// }

// for 循环
// int main()
// {
//     int i = 0;
//     for (i = 1; i <= 10 ; i++)
//     {
//         printf("%d\n",i);
//     }
//     return 0;
// }
// int main()
// {
//     int i;
//     int sum = 0;
//     for (i = 3;i<=100;i+=3)
//     {
//        sum += i;

//     }
//     printf("sum = %d\n",sum);
//     return 0;
// }
// int main()
// {
//     int num = 0;
//     int count = 0;
//     scanf("%d",&num);
//     do{
//         count++;
//         num /= 10;
//     }while(num >0);
//     printf("count = %d\n",count);
//     return 0;  
// }
// int main()
// {
// int i = 1;
// while(i <= 10)
// {
// if(i == 5)
// continue;
// //当i等于5后，就执⾏continue，直接跳过continue的代码，去循环的判断的地⽅
// //因为这⾥跳过了i = i+1，所以i⼀直为5，程序陷⼊和死循环
// printf("%d ", i);
// i = i + 1;
// }
// return 0;
// }
// int main()
// {
//     int i;
//     int j;
    
//     for( i = 100;i<=200;i++)
//     {
//         int flag = 1;
//         for (j = 2; j <(int)(i*0.5) + 1;j++)
//         {
//             if (i % j == 0)
//             {
//                 flag = 0;
//                 break;
//             }
//         }
//         if (flag == 1)
//         {
//             printf("%d ", i);
//         }
        
//     }
//     return 0;
// }
// int main()
// {
//     printf("hehe\n");
//     goto next;
//     printf("haha\n");
//     next:
//     printf("跳过了haha的打印\n");
//     return 0;
// }



// 以下 为  猜数字小游戏的一个拆解
//rand 函数 在stdlib.h 中
//printf("%d\n",rand()); // 生成一个随机数
//srand 函数 在stdlib.h 中 相当于种子 s(eed)rand 
//time 函数 在time.h 中 生成一个时间戳 可以作为种子,要转成unsigned int 类型
//srand((unsigned int)time(NULL));
// 设置随机数范围
// rand() % (max - min + 1) + min; // 生成 [min, max] 范围内的随机数
//取余的范围是0 ~ n-1
void menu()
{
    printf("******************\n");
    printf("**** 1.play ****\n");
    printf("**** 0.exit ****\n");
    printf("******************\n");
}
void game()
{
    int ret = rand() % 100 + 1;// 生成 [1, 100] 范围内的随机数
    int guess = 0;
    int count = 5;
    
    while(count)
    {
        printf("you have %d chances, please input your guess:>", count);
        scanf("%d",&guess);
        if (guess > ret)
        {
            printf("too big\n");
            
        }
        else if (guess < ret)
        {
            printf("too small\n");
            
        }
        else
        {
            printf("you win\n");
            break;
        }
        count--;
    }
        if (count == 0)
        {
            printf("you lose, the number is %d\n", ret);
        }

}
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));//种子
    do{
    menu();
    printf("please input your choice:>");
    scanf("%d",&input);
    switch(input)
    {
        case 1:
            game();
            break;
        case 0:
            printf("game over\n");
            break;
        default:
            printf("error\n");
            break;
            
    }

    }while(input);
    return 0;

}