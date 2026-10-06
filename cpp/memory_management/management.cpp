#include <iostream>
using namespace std;

// int globalVar = 1;  //静态 全局变量
// static int staticGlobalVar = 1; //静态区
// void Test()
// {
//  static int staticVar = 1; //静态区
//  int localVar = 1;  //栈区
//  int num1[10] = { 1, 2, 3, 4 };  //栈区 局部数组
//  char char2[] = "abcd";  //栈区 用字符串初始化 但还是在战区
//  const char* pChar3 = "abcd"; //ptr3 是一个指针 在战区 指向的字符串在常量区
//  int* ptr1 = (int*)malloc(sizeof(int) * 4);  //指向的对象 堆区
//  int* ptr2 = (int*)calloc(4, sizeof(int));  //同上
//  int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4); // 同上
//  free(ptr1);
//  free(ptr3);
// }
// 1. 选择题：
//    选项: A.栈  B.堆  C.数据段(静态区)  D.代码段(常量区)
//    globalVar在哪里？____   
//    staticGlobalVar在哪里？____
//    staticVar在哪里？____   
//    localVar在哪里？____
//    num1 在哪里？____
//    
//    char2在哪里？____   
//    *char2在哪里？___
//    pChar3在哪里？____      
//    *pChar3在哪里？____
//    ptr1在哪里？____        
//    *ptr1在哪里？____


//内存管理方式
//1. new / delete 操作内置类型
// void Test
// {
//     int * ptr4 = new int;
//     int * ptr5 = new int(10);  //动态申请一个int 类型的空间 并初始化 为10
//     //动态申请10个int 类型的 空间
//     int * ptr6 = new int[10];
//     delete ptr4;
//     delete ptr5;
//     delete [] ptr6;
// //注意：申请和释放单个元素的空间，使用new和delete操作符，申请和释放连续的空间，使用
// //new[]和delete[]，注意：匹配起来使用。
// }
//2. new / delete 操作自定义类型
class A
{
public:
    A(int a = 0)
        :_a(a)
    {
        cout << "A():" << this << endl;
    }
    ~A()
    {
        cout << "~A():" << this << endl;
    }
private:
    int _a;

};
int main()
{
    // new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
    //还会调用构造函数和析构函数
    A* p1 = (A*)malloc(sizeof(A));
    A* p2 = new A(1);
    free(p1);
    delete p2;
    // 内置类型是几乎是一样的
    int* p3 = (int*)malloc(sizeof(int)); // C
    int* p4 = new int;
    free(p3);
    delete p4;
    cout << "..................." << endl;
    A* p5 = (A*)malloc(sizeof(A)*10);
    A* p6 = new A[10];
    free(p5);
    delete[] p6;
    return 0;
}