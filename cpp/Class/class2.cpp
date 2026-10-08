#include <iostream>
using namespace std;
// 1. 再探构造函数
// 之前我们实现构造函数时，初始化成员变量主要使⽤函数体内赋值，构造函数初始化还有⼀种⽅
// 式，就是初始化列表，初始化列表的使⽤⽅式是以⼀个冒号开始，接着是⼀个以逗号分隔的数据成
// 员列表，每个"成员变量"后⾯跟⼀个放在括号中的初始值或表达式。

// 2.每个成员变量在初始化列表中只能出现⼀次，语法理解上初始化列表可以认为是每个成员变量定义
// 初始化的地⽅。

// 3.引⽤成员变量，const成员变量，没有默认构造的类类型变量，必须放在初始化列表位置进⾏初始
// 化，否则会编译报错。

// 4.C++11⽀持在成员变量声明的位置给缺省值，这个缺省值主要是给没有显⽰在初始化列表初始化的
// 成员使⽤的。

// 5.尽量使⽤初始化列表初始化，因为那些你不在初始化列表初始化的成员也会⾛初始化列表，如果这
// 个成员在声明位置给了缺省值，初始化列表会⽤这个缺省值初始化。如果你没有给缺省值，对于没
// 有显⽰在初始化列表初始化的内置类型成员是否初始化取决于编译器，C++并没有规定。对于没有
// 显⽰在初始化列表初始化的⾃定义类型成员会调⽤这个成员类型的默认构造函数，如果没有默认构
// 造会编译错误

// 6.初始化列表中按照成员变量在类中声明顺序进⾏初始化，跟成员在初始化列表出现的的先后顺序⽆
// 关。建议声明顺序和初始化列表顺序保持⼀致。

// 初始化列表总结：
// ⽆论是否显⽰写初始化列表，每个构造函数都有初始化列表；
// ⽆论是否在初始化列表显⽰初始化成员变量，每个成员变量都要⾛初始化列表初始化；
// class Time
// {
// public:
//     Time(int hour)
//         :_hour(hour)
//     {
//         cout <<"Time()" << endl;
//     }  //函数体 构造函数时被调用
// private:
//     int _hour;
// }

// class Date
// {
// public:
//     Date(int&x,int year = 1,int month = 1,int day = 1)
//         :_year(year)
//         ,_month(month)
//         ,_day(day)
//         ,_t(12)
//         ,_ref(x)
//         ,_n(1)
//         {

//         }
//     void Print() const{
//         cout << _year << "-" << _month << "-" << _day << endl;
//     }
// private:
//     int _year;
//     int _month;
//     int _day;
//     Time_t;
//     int& _ref;
//     const int_n;  //const
// };
// int main()
// {
//     int i = 0;
//     Date d1(i);
//     d1.Print();
//     return 0;
// }


// class Time
// {
// public:
//     Time(int hour)
//         :_hour(hour)
//     {
//         cout <<"Time()" << endl;
//     }
// private:
//     int_hour;
// };
// class Date
// {
// public:
//     Date()
//         :_month(2)
//     {
//         cout << "Date()" << endl;
//     }
//     void Print() const
//     {
//         cout << _year << "-" << _month << "-" <<_day << endl;
//     }
// private:
//     int _year = 1;
//     int _month = 1;
//     int _day;
//     Time _t = 1;  //先进行 构造函数 再拷贝构造
//     const int_n = 1;
//     int *_ptr = (int*)malloc(12);
// };
// int main()
// {
//     Date d1;
//     d1.Print()
//     return 0;
// }


// class A
// {
// public:
//     A(int a)
//         :_a1(a)
//         ,_a2(_a1)
//         {}
//     void Print(){
//         cout <<_a1 << " " << _a2 << endl;
//     }
// private:
//     int _a2 = 2;
//     int _a1 = 2;

// };
// int main()
// {
//     A aa(1);
//     aa.print();
// }

//类型转换
// C++⽀持内置类型隐式类型转换为类类型对象，需要有相关内置类型为参数的构造函数。
// 构造函数前⾯加explicit就不再⽀持隐式类型转换。
// 类类型的对象之间也可以隐式转换，需要相应的构造函数⽀持。
// class A
// {
// public:
// // 构造函数explicit就不再⽀持隐式类型转换
// // explicit A(int a1)
//     A(int a1)
//     :_a1(a1)
//     {}
// //explicit A(int a1, int a2)
//     A(int a1, int a2)
//     :_a1(a1)
//     , _a2(a2)
//     {}
//     void Print()
//     {
//         cout << _a1 << " " << _a2 << endl;
//     }
//     int Get() const
//     {
//         return _a1 + _a2;
//     }
// private:
//     int _a1 = 1;
//     int _a2 = 2;
// };
// class B
// {
// public:
//     B(const A& a)
//         :_b(a.Get())
//     {}
// private:
//     int _b = 0;
// };
// int main()
// {
// 1构造⼀个A的临时对象，再⽤这个临时对象拷⻉构造aa3
// 编译器遇到连续构造+拷⻉构造->优化为直接构造
//     A aa1 = 1;
//     aa1.Print();
//     const A& aa2 = 1;
//     // C++11之后才⽀持多参数转化
//     A aa3 = { 2,2 };
//     // aa3隐式类型转换为b对象
//     // 原理跟上⾯类似
//     B b = aa3;
//     const B& rb = aa3;
//     return 0;
// }

//static成员
// ⽤static修饰的成员变量，称之为静态成员变量，静态成员变量⼀定要在类外进⾏初始化。
// 静态成员变量为所有类对象所共享，不属于某个具体的对象，不存在对象中，存放在静态区。
// ⽤static修饰的成员函数，称之为静态成员函数，静态成员函数没有this指针。
// 静态成员函数中可以访问其他的静态成员，但是不能访问⾮静态的，因为没有this指针。
// ⾮静态的成员函数，可以访问任意的静态成员变量和静态成员函数。
// 突破类域就可以访问静态成员，可以通过类名::静态成员 或者 对象.静态成员 来访问静态成员变量
// 和静态成员函数。
// 静态成员也是类的成员，受public、protected、private 访问限定符的限制。
// 静态成员变量不能在声明位置给缺省值初始化，因为缺省值是个构造函数初始化列表的，静态成员
// 变量不属于某个对象，不⾛构造函数初始化列表
// class A
// {
// public:
//     A()  //构造函数
//     {
//         ++_scount;
//     }
//     A(const A& t)  //拷贝构造
//     {
//         ++_scount;
//     }
//     ~A()
//     {
//         --_scount;
//     }
//     static int GetACount()
//     {
//         return _scount;
//     }
// private:
//     static int _scount;  //类里面声明
// };
// int A::_scount = 0;  //类外面初始化
// 因为_scount 是共有的 不是每一个对象私有的 并不是实例化一个新的对象就要让_scount为0
// int main()
// {
//     cout << A::GetACount() << endl;
//     A a1 , a2;
//     A a3(a1);
//     cout << A::GetACount() << endl;
//     cout << a1.GetACount() << endl;
//     return 0;
// }

// class A
// {
// public:
//     A()
//     {
//         ++_scount;
//     }
//     A(const A& t)
//     {
//         ++_scount;
//     }
//     ~A()
//     {
//         --_scount;
//     }
//     static int GetACount()
//     {
//         return _scount;
//     }
// private:
//     static int _scount;
    
// };
// int A::_scount = 0; //类外面初始化


// 1+2+3+4+.......+n
// class Sum
// {
// public:
//     Sum()
//     {
//         _result += _num;
//         ++_num;
//     }
//     static int GetResult()
//     {
//         return _result;
//     }
// private:
//     static int _result;
//     static int _num;
// };

// int Sum::_result = 0;
// int Sum::_num = 1;
// class Solution
// {
// public:
//     int Sum_Solution(int n)
//     {
//         Sum arr[n];
//         return Sum::GetResult();
//     } 
// }; 


//友元
// class B;  //前置声明 否则A的友元函数声明 编译器不认识
// class A
// {
//     friend void func(const A& aa, const B& bb);
// private:
//     int _a1 = 1;
//     int _a2 = 2;
// };
// class B
// {
//     friend void func(const A& aa, const B& bb);
// private:
//     int _b1 = 3;
//     int _b2 = 4;
// };

// void func(const A& aa , const B& bb)
// {
//     cout << aa._a1 << endl;
//     cout << bb._b1 << endl;
// }
// int main()
// {
//     A aa;
//     B bb;  //默认构造函数
//     func(aa,bb);
//     return 0;
// }

// class A
// {
//     friend class B;
// private:
//     int _a1 = 1;
//     int _a2 = 2;
// };
// class B
// {
// public:
//     void func1(const A& aa)
//     {
//         cout << aa._a1 << endl;
//         cout << _b1 << endl;
//     }
//     void func2 (const A& aa)
//     {
//         cout << aa._a2 << endl;
//         cout << _b2 << endl;
//     }
// private:
//     int _b1 = 3;
//     int _b2 = 4;
// };
// int main()
// {
//     A aa;
//     B bb;
//     bb.func1(aa);
//     bb.func2(aa);
//     return 0;
// }



//内部类
// 如果⼀个类定义在另⼀个类的内部，这个内部类就叫做内部类。内部类是⼀个独⽴的类，跟定义在
// 全局相⽐，他只是受外部类类域限制和访问限定符限制，所以外部类定义的对象中不包含内部类。
//内部类默认是外部类的友元类。
// 内部类本质也是⼀种封装，当A类跟B类紧密关联，A类实现出来主要就是给B类使⽤，那么可以考
// 虑把A类设计为B的内部类，如果放到private/protected位置，那么A类就是B类的专属内部类，其
// 他地⽅都⽤不了。
// class A
// {
// private:
//     static int _k;
//     int _h = 1;
// public:
//     class B
//     {
//     public:
//         void foo(const A& a)
//         {
//             cout << _k << endl;
//             cout << _h << endl;
//         }
//         int _b1;
//     };

// };
// int A:: _k = 1;
// int main()
// {
//     cout << sizeof(A) << endl;
//     A::B b;
//     A aa;
//     b.foo(aa);
//     return 0;
// }
// class Solution
// {
//     class Sum
//     {
//     public:
//         Sum()
//         {
//             _result += _num;
//             _num++;
//         }
//     };
//     static int _num;
//     static int _result;
// public:
//     int Sum_Solution(int n)
//     {
//         Sum arr[n];
//         return _result;
//     }
// };
// int Solution :: _num = 1;
// int Solution :: _result = 0;


//匿名对象
// int main()
// {
//     A aa1;
//     A aa1(); //不能这么写 编译器分不出这是函数声明 还是 对象定义
//     A();
//     A(1);
//     A aa2(2);
//     Solution().Sum_Solution(10); //这里就很好用
//     return 0;
// }


//对象拷贝时的编译优化
//现代编译器会为了尽可能提⾼程序的效率，在不影响正确性的情况下会尽可能减少⼀些传参和传返
//回值的过程中可以省略的拷⻉。
//如何优化C++标准并没有严格规定，各个编译器会根据情况⾃⾏处理。当前主流的相对新⼀点的编
// 译器对于连续⼀个表达式步骤中的连续拷⻉会进⾏合并优化，有些更新更"激进"的编译器还会进⾏
// 跨⾏跨表达式的合并优化
// class A
// {
// public:
//     A(int a = 0)
//     :_a1(a)
//     {
//         cout << "A(int a)" << endl;
//     }
//     A(const A& aa)
//     :_a1(aa._a1)
//     {
//         cout << "A(const A& aa)" << endl;
//     }
//     A& operator=(const A& aa)
//     {
//         cout << "A& operator=(const A& aa)" << endl;
//         if (this != &aa)
//         {
//             _a1 = aa._a1;
//         }
//         return *this;
//     }
//     ~A()
//     {
//         cout << "~A()" << endl;
//     }
// private:
//     int _a1 = 1;
// };

// void f1(A aa)
//  {}
// A f2()
// {
//     A aa;
//     return aa;
// }

//  int main()
//  {
//  // 传值传参
//  // 构造+拷⻉构造
//     A aa1;
//     f1(aa1);
//     cout << endl;

//  // 隐式类型，连续构造+拷⻉构造->优化为直接构造
//      f1(1);

//  // ⼀个表达式中，连续构造+拷⻉构造->优化为⼀个构造
//     f1(A(2));
//     cout << endl;

//     cout << "***********************************************" << endl;

//  // 传值返回
//  // 不优化的情况下传值返回，编译器会⽣成⼀个拷⻉返回对象的临时对象作为函数调⽤表达
// //式的返回值

//  // ⽆优化 （vs2019 debug）
//  // ⼀些编译器会优化得更厉害，将构造的局部对象和拷⻉构造的临时对象优化为直接构造
// //（vs2022 debug）
//     f2();
//     cout << endl;

//  // 返回时⼀个表达式中，连续拷⻉构造+拷⻉构造->优化⼀个拷⻉构造 （vs2019 debug）
//  // ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，将构造的局部对象aa和拷⻉的临时对象
// //和接收返回值对象aa2优化为⼀个直接构造。（vs2022 debug）
//     A aa2 = f2();
//     cout << endl;

//  // ⼀个表达式中，开始构造，中间拷⻉构造+赋值重载->⽆法优化（vs2019 debug）
//  // ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，将构造的局部对象aa和拷⻉临时对象合
// //并为⼀个直接构造（vs2022 debug）
//     aa1 = f2();
//     cout << endl;

//     return 0;
//  }