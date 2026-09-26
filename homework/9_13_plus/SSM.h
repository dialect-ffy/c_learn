//运用链式存储来实现学生信息管理系统
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// //首先定义链表结点的结构体
// typedef struct Student
// {
//     int num;
//     char name[20];
//     float score[3];
//     float aver;
//     struct Student* next;
// } Student;
// //函数声明
// //1.初始化链表
// Student *InitList();
// //2.插入学生 选择尾插法 这样就是一个一个地输入
// void addStudent(Student * head);
// //寻找最高成绩学生
// Student * findMaxScore(Student * head);
// //4.打印最高成绩学生
// void PrintMax(Student * maxStu);
// //5.逐个显示所有学生信息
// void PrintAll(Student * head);