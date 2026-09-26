// int main() {
//     int a = 0;
//     // 引⽤：b和c是a的别名
//     int& b = a;
//     int& c = a;
//     // 也可以给别名b取别名，d相当于还是a的别名
//     int& d = b;
//     ++d;
//     // 这⾥取地址我们看到是⼀样的
//     printf("%p\n", &a);
//     printf("%p\n", &b);
//     printf("%p\n", &c);
//     printf("%p\n", &d);
//     return 0;
// }  //引用 

//顺序表
// typedef int SqDataType;
// #define Sq_MAX_SIZE 10
// typedef struct 
// {
//     SqDataType arr[Sq_MAX_SIZE];  //存储数据的静态数组
//     int size;   // 存储数据的数量
//     /* data */
// }Sqlist;
// typedef int SqDataType
// typedef struct 
// {
//     SqDataType * arr[];  //存储数据的动态指针
//     int size;   //数据个数
//     int capacity;  //可容纳的数据个数
        
// }Sqlsit;
