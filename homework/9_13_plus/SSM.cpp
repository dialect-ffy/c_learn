// #include "SSM.h"
// //1.初始化链表  哨兵位 头结点
// Student * InitList()
// {
//     Student *head = (Student *)malloc(sizeof(Student));
//     if(head == NULL)
//     {
//         printf("lose");
//         exit(-1);
//     }
//     head->next = NULL;
//     return head;
// }
// //2.插入学生 选择尾插法 这样就是一个一个地输入
// void addStudent(Student * head)
// {
//     Student *p = head;  //运动p 不能动头结点
//     while(p->next != NULL)
//     {
//         p = p->next;  //找到最后一个结点 P
//     }
//     //创建新结点
//     Student * newNode = (Student * )malloc(sizeof(Student));
//     if(newNode == NULL)
//     {
//         printf("lose");
//         exit(-1);
//     }
//     printf("please input num: ");
//     scanf("%d", &newNode->num);
//     printf("please input name: ");
//     scanf("%s", newNode->name); // 数组名本身就是地址，不用加 &
//     printf("please input score: ");
//     scanf("%f %f %f", &newNode->score[0], &newNode->score[1], &newNode->score[2]);
//     newNode->aver = (newNode->score[0] + newNode->score[1] + newNode->score[2]) / 3.0f;
//     newNode->next = NULL;
//     p -> next = newNode;  //让最后一个结点P 指向新节点 实现尾插
//     printf("success");
// }
// //3.寻找最高成绩学生
// Student * findMaxScore(Student * head)
// {
//     if(head->next == NULL)
//     {
//         return NULL;
//     }
//     Student *maxStu = head->next;
//     Student *p = head->next->next;
//     while(p!= NULL)
//     {
//         if(p->aver > maxStu->aver)
//         {
//             maxStu = p;
//         }
//         p = p->next;
//     }
//     return maxStu;
// }
// //4.打印最高成绩学生
// void PrintMax(Student * maxStu)
// {
//     printf("num:%d\n name:%s\n score: %f %f %f\n aver: %f\n",maxStu->num,maxStu->name,maxStu->score[0],
//     maxStu->score[1],maxStu->score[2],maxStu->aver);
// }
// //5.逐个显示所有学生信息（跳过头结点，按链表顺序依次打印）
// void PrintAll(Student * head)
// {
//     if(head == NULL || head->next == NULL)
//     {
//         printf("empty list\n");
//         return;
//     }
//     Student *p = head->next;  //跳过头结点（哨兵位）
//     int i = 0;
//     while(p != NULL)
//     {
//         printf("[%d] num:%d name:%s score: %f %f %f aver: %f\n",
//                ++i, p->num, p->name, p->score[0], p->score[1], p->score[2], p->aver);
//         p = p->next;
//     }
// }