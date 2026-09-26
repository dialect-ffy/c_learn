// #include "SSM.h"
// //1.输入
// void InPutStu(struct Student stu[], int n) //相当于传的是指针，即首元素的地址
// {
//     int i;
//     printf("please input num name score -->");
//     for(i = 0; i < n; i++)
//     {
//         scanf("%d %s %f %f %f", &stu[i].num, stu[i].name,
//         &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
//         stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0f;
//     }
// }
// //2.寻找最高分，并返回这个学生（结构体属于值类型，可以整体赋值，可以当作函数返回值。）
// struct Student MaxScore(struct Student stu[], int n)
// {
//     int i = 0, m = 0;
//     for(i = 0; i < n; i++)
//     {
//         if(stu[i].aver > stu[m].aver)
//         {
//             m = i;
//         }
//     }
//     return stu[m];
// }
// //3.打印成绩最高学生信息
// void PrtStu(struct Student stu)
// {
//     printf("\nthe winner is: \n");
//     printf("num:%d\n name: %s\n score: %5.1f,%5.1f,%5.1f\n aver: %6.2f\n",
//         stu.num, stu.name, stu.score[0], stu.score[1], stu.score[2], stu.aver);
// }
// //4.逐个显示所有学生信息
// void PrintAll(struct Student stu[], int n)
// {
//     int i;
//     if(n <= 0)
//     {
//         printf("empty list\n");
//         return;
//     }
//     for(i = 0; i < n; i++)
//     {
//         printf("[%d] num:%d name:%s score: %f %f %f aver: %f\n",
//             i + 1, stu[i].num, stu[i].name,
//             stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].aver);
//     }
// }
