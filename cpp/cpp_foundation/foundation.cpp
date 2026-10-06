// #include "foundation.h"
//using namespace std;
//1.命名空间 namespace 
//在C/C++中，变量、函数和后⾯要学到的类都是⼤量存在的，这些变量、函数和类的名称将都存在于全
//局作⽤域中，可能会导致很多冲突。
//namespace 就可以很好解决这个问题
// namespace dialect
// {
//     int rand = 10;
//     int Add(int left,int right)
//     {
//         return left + right;
//     }
//     struct Node{
//         struct Node* next;
//         int val;
//     };
//     namespace dialect_plus //命名空间可以嵌套w
//     {
//         int i = 1;
//     }
// }        

// int main()
// {
//     printf("%p\n",rand); //访问的是全局的rand指针变量
//     printf("%d\n",dialect::rand);
//     printf("%d\n",dialect::dialect_plus::i) ;//访问的是dialect 指定的命名空间
//     return 0;
// }
//多文件中可以定义同名namespace 他们会默认合成到一起
// namespace dialect
// {
//     void STInit(ST* ps)
//     {
//         assert(ps);
//         ps->a = (STDataType*)malloc(4 * sizeof(STDataType));
//         ps->top = 0;
//         ps->capacity = 4;
//     }
//     // 栈顶
//     void STPush(ST* ps, STDataType x)
//     {
        
//     // 满了， 扩容
//         if (ps->top == ps->capacity)
//         {
//             printf("扩容\n");
//             int newcapacity = ps->capacity == 0 ? 4 : ps->capacity
//             * 2;
//             STDataType* tmp = (STDataType*)realloc(ps->a,
//             newcapacity * sizeof(STDataType));

//             if (tmp == NULL)
//             {
//             perror("realloc fail");
//             return;
//             }
//             ps->a = tmp;
//             ps->capacity = newcapacity;
//         }
//         ps->a[ps->top] = x;
//         ps->top++;
//     }
//     //...
// }
//2.命名空间使用
#include<stdio.h>
namespace N
{
    int a = 0;
    int b = 1;
}
int main()
{
    // 编译报错：error C2065: “a”: 未声明的标识符
    printf("%d\n", a); //不会主动进入namespace
    return 0;
}
//除非指定 eg: using N::a 
//或者 printf("%d\n",N::a);这样
//using namespace N 使用空间中的全部成员
//3. C++ 输入输出
#include <iostream>
using namespace std;
//也可部分包含  using std::cout

int main()
{
    int a = 0;
    int b = 2;
    char c = 'x';
    count << a << "" << b << endl;
    std::cout << a << " " << b << " " << c << std::endl; //如果没有包含则前面加上std::
}
//4.缺省参数
// 全缺省
void Func1(int a = 10, int b = 20, int c = 30)
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl << endl;
    }
// 半缺省  只能从右往左  否则指代不明
void Func2(int a, int b = 10, int c = 20)
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl << endl;
}
int main()
{
    Func1();
    Func1(1);
    Func1(1,2);
    Func1(1,2,3);
    Func2(100);
    Func2(100, 200);  //void Func2(int a, int b=10, int c )这就是错的
    Func2(100, 200, 300);
    return 0;
}
//声明和定义  缺省参数只能写在声明里 定义只管实现
//5.函数重载
//(1).参数类型不同
int Add(int left, int right)
{
    cout << "int Add(int left, int right)" << endl;
    return left + right;
    }
double Add(double left, double right)
{
    cout << "double Add(double left, double right)" << endl;
    return left + right;
}
//(2) 参数个数不同
void f()
{
    cout << "f()" << endl;
}
void f(int a)
{
    cout << "f(int a)" << endl;
}
//(3) 参数类型顺序不同
void f(int a, char b)
{
    cout << "f(int a,char b)" << endl;
}
void f(char b, int a)
{
    cout << "f(char b, int a)" << endl;
}
// 返回值不同不能作为重载条件，因为调⽤时也⽆法区分
//void fxx()
//{}
//
//int fxx()
//{
// return 0;
//}
// 下⾯两个函数构成重载
// f()但是调⽤时，会报错，存在歧义，编译器不知道调⽤谁
void f1()
{
    cout << "f()" << endl;
}
void f1(int a = 10)
{
    cout << "f(int a)" << endl;
}
//可以放参数 可以不放 有歧义
//6.引用
int main()
{
    int a = 0;
    // 引⽤：b和c是a的别名
    int& b = a;
    int& c = a;
    // 也可以给别名b取别名，d相当于还是a的别名
    int& d = b;
    ++d;
    // 这⾥取地址我们看到是⼀样的
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    return 0;
}
//引用在定义时必须初始化
//引⽤在实践中主要是于引⽤传参和传引⽤返回中减少拷⻉提⾼效率和改变引⽤对象时同时改变被引
//⽤对象。
int& STTop(ST& rs)
{
    assert(rs.top > 0);
    return rs.a[rs.top];
}
// int STTop(ST& rs)
// {
//     assert(rs.top > 0);
//     return rs.a[rs.top];
// }返回 int 得到一个值的副本；返回 int& 得到原来那个元素的别名，可以通过它修改原元素。
int main()
{
    // 调⽤全局的
    ST st1;
    STInit(st1);
    STPush(st1, 1);
    STPush(st1, 2);
    STTop(st1) += 10; 
    cout << STTop(st1) << endl;
    return 0;
}

//const 引用
//这里是把右边的放到左边
int main()
{
    const int a = 10;
    // 编译报错：error C2440: “初始化”: ⽆法从“const int”转换为“int &”
    // 这⾥的引⽤是对a访问权限的放⼤
    //int& ra = a;
    // 这样才可以
    const int& ra = a;
    // 编译报错：error C3892: “ra”: 不能给常量赋值
    //ra++;
    // 这⾥的引⽤是对b访问权限的缩⼩
    int b = 20;
    const int& rb = b;
    // 编译报错：error C3892: “rb”: 不能给常量赋值
    //rb++;
    return 0;
}
// 是类似 int& rb = a*3; double d = 12.34; int& rd = d; 这样⼀些场
// 景下a*3的和结果保存在⼀个临时对象中， int& rd = d 也是类似，在类型转换中会产⽣临时对
// 象存储中间值，也就是时，rb和rd引⽤的都是临时对象，⽽C++规定临时对象具有常性，所以这⾥
// 就触发了权限放⼤，必须要⽤常引⽤才可以。
//int& 用来引用可修改的 int 对象；const int& 还可以绑定临时结果，但不能通过它修改对象。


int main()
{
    int a = 10;
    const int& ra = 30;
    // 编译报错: “初始化”: ⽆法从“int”转换为“int &”
    // int& rb = a * 3;临时结果 要用const 来修饰
    const int& rb = a*3;
    double d = 12.34;
    // 编译报错：“初始化”: ⽆法从“double”转换为“int &”
    // int& rd = d;
    const int& rd = d;
    return 0;
}
inline int Add(int x, int y)
{
    int ret = x + y;
    ret += 1;
    ret += 1;
    ret += 1;
    return ret;
}
int main()
{
    // 可以通过汇编观察程序是否展开
    // 有call Add语句就是没有展开，没有就是展开了
    int ret = Add(1, 2);
    cout << Add(1, 2) * 5 << endl;
    return 0;
}
#define ADD(a, b) ((a) + (b))  inline 就是用来代替 宏的
// inline不建议声明和定义分离到两个⽂件，分离会导致链接错误。因为inline被展开，就没有函数地
// 址，链接时会出现报错。
void f(int x)
{
    cout << "f(int x)" << endl;
}
void f(int* ptr)
{
    cout << "f(int* ptr)" << endl;
}
int main()
{
    f(0);
    // 本想通过f(NULL)调⽤指针版本的f(int*)函数，但是由于NULL被定义成0，调⽤了f(intx)，因此与程序的初衷相悖。
    f(NULL);
    f((int*)NULL);
    // 编译报错：error C2665: “f”: 2 个重载中没有⼀个可以转换所有参数类型
    // f((void*)NULL);
    f(nullptr);
    return 0;
}