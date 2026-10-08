#include <iostream>
using namespace std;
//1.泛型编程
void Swap(int& left, int& right)
{
    int temp = left;
    left = right;
    right = temp;
}
void Swap(double& left, double& right)
{
    double temp = left;
    left = right;
    right = temp;
}
void Swap(char& left, char& right)
{
    char temp = left;
    left = right;
    right = temp;
}
//函数重载可以实现 但是代码复用率低 可维护性差

//2.函数模板
template <typename T>
void Swap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}
// 注意：typename是用来定义模板参数关键字，也可以使用class(切记：不能使用struct代替
// class)
//3.实例化
template <typename T>
T Add(const T& left, const T& right)
{
    return left + right;
}
int main()
{
    int a1 = 10 , a2 = 20;
    double d1 = 10.0 , d2 = 20.0;
    Add(a1,a2);
    Add(d1,d2);
    Add(a,(int)d);
    return 0;
}

//显示实例化
int main()
{
    int a = 10;
    double d = 20.0
    Add<int>(a,b);
    return 0;
}
// 1. 一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这
// 个非模板函数
// 专门处理int的加法函数
int Add(int left, int right)
{
    return left + right;
}
// 通用加法函数
template<class T>
T Add(T left, T right)
{
    return left + right;
}
void Test()
{
    Add(1, 2); // 与非模板函数匹配，编译器不需要特化
    Add<int>(1, 2); // 调用编译器特化的Add版本
}
//2. 对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而
//不会从该模板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
// 专门处理int的加法函数
int Add(int left, int right)
{
return left + right;
}
// 通用加法函数
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
    return left + right;
}
void Test()
{
    Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
    Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的
//Add函数
}

//类模板
template<class T1, class T2, ..., class Tn>
class 类模板名
{
// 类内成员定义
};
// 类模版
template<typename T>
class Stack
{
public:
    Stack(size_t capacity = 4)
    {
        _array = new T[capacity];
        _capacity = capacity;
        _size = 0;
    }
    void Push(const T& data);
private:
    T* _array;
    size_t _capacity;
    size_t _size;
};
// 模版不建议声明和定义分离到两个文件.h 和.cpp会出现链接错误，具体原因后面会讲
template<class T>
void Stack<T>::Push(const T& data)
{
    // 扩容
    _array[_size] = data;
    ++_size;
}
int main()
{
    Stack<int> st1; // int
    Stack<double> st2; // double
    return 0;
}

//类模板实例化
// 类模板实例化与函数模板实例化不同，类模板实例化需要在类模板名字后跟<>，然后将实例化的
// 类型放在<>中即可，类模板名字不是真正的类，而实例化的结果才是真正的类。
// Stack是类名，Stack<int>才是类型
// Stack<int> st1; // int
// Stack<double> st2; // double