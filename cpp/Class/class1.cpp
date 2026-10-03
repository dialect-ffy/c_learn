#include<iostream>
using namespace std;
// // 计算⼀下A/B/C实例化的对象是多⼤？
// class A
// {
// public:
//     void Print()
//     {
//     	cout << _ch << endl;
//     }
// private:
//     char _ch;
//     int _i;
// };
// class B
// {
// public:
//     void Print()
//     {
//     	//...
//     }
// };
// class C
// {};
// int main()
// {
//     A a;
//     B b;
//     C c;
//     cout << sizeof(a) << endl;
//     cout << sizeof(b) << endl;
//     cout << sizeof(c) << endl;
//     return 0;
// }
//默认成员函数
//构造函数 主要是完成初始化的工作
//特点 函数名与类名相同
// 无返回值 也不需要写void
//对象实例化时系统会自动调用对应的构造函数
//构造函数可以重载
//如果类中没有显示定义构造函数 C++编译器会自动生成一个无参的默认构造的函数 
//无参构造函数 全缺省构造函数 我们不写构造时编译器默认生成的构造函数都叫做默认构造的函数
//对内置类型成员变量的初始化没有要求 
//对于自定义类型成员变量，要求调用这个成员变量的默认构造函数初始化
// class Date
// {
// public:
//     //1.无参构造函数
//     Date()
//     {
//         _year = 1;
//         _month = 1;
//         _day = 1;
//     }
//     //2.带参构造函数
//     Date(int year,int month,int day)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     //3.全缺省构造函数
//     // Date(int year = 1,int month = 1,int day = 1)
//     // {
//     //     _year = year;
//     //     _month = month;
//     //     _day = day;
//     // }
//     void Print()
//     {
//         cout << _year << "/" << _month <<"/" <<_day <<endl;
//     }
// private:
//     int _year;
//     int _month;
//     int _day;

// };
// int main()
// {
//     Date d1; //实例化 自动执行构造函数
//     Date d2(2026,10,3); //调用带参的构造函数
//     //注意：如果通过⽆参构造函数创建对象时，对象后⾯不⽤跟括号
//     d1.Print();
//     d2.Print();
//     return 0;
// }



// typedef int STDataType ;
// class Stack
// {
// public:
//     Stack(int n = 4)
//     {
//         _a = (STDataType *)malloc(sizeof(STDataType) * n);
//         if(nullptr == _a)
//         {
//             perror("malloc申请空间失败");
//             return;
//         }
//         _capacity = n;
//         _top = 0;
//     }
//     //.....其他功能
// private:
//     STDataType * _a;
//     size_t _capacity;
//     size_t _top;
// };


// //两个Stack 实现队列
// class MyQueue
// {
// public:
//     //编译器默认生成的MyQueue的构造函数 调用了Stack 的构造 完成了两个成员的初始化
// private:
//     Stack pushst;
//     Stack popst;
// };
// //创建 MyQueue q; 时，编译器生成的默认构造函数会自动调用两次 Stack 的默认构造函数，分别初始化 pushst 和 popst。
// //因此，如果没有其他初始化工作，就不用自己写 MyQueue 的构造函数。
// int main()
// {
//     MyQueue mq;
//     return 0;
// }




//析构函数  释放资源
//特点 析构函数名是在类名前加上字符 ~。
//⽆参数⽆返回值。 (这⾥跟构造类似，也不需要加void)
//. ⼀个类只能有⼀个析构函数。若未显式定义，系统会⾃动⽣成默认的析构函数。
//. 对象⽣命周期结束时，系统会⾃动调⽤析构函数。
//跟构造函数类似，我们不写编译器⾃动⽣成的析构函数对内置类型成员不做处理，⾃定类型成员会调⽤他的析构函数。
//还需要注意的是我们显⽰写析构函数，对于⾃定义类型成员也会调⽤他的析构，
//也就是说⾃定义类型成员⽆论什么情况都会⾃动调⽤析构函数。
//对象正常析构时，不管你是否自己写了析构函数，它的类类型成员都会自动析构。
//如果类中没有申请资源时，析构函数可以不写，直接使⽤编译器⽣成的默认析构函数，如Date；如
//果默认⽣成的析构就可以⽤，也就不需要显⽰写析构，如MyQueue；但是有资源申请时，⼀定要
//⾃⼰写析构，否则会造成资源泄漏，如Stack。
//如果资源是通过裸指针用 new 或 malloc 申请的，编译器生成的析构函数不会自动释放它。
//⼀个局部域的多个对象，C++规定后定义的先析构。
// typedef int STDataType ;
// class Stack
// {
// public:
//     Stack(int n = 4)
//     {
//         _a = (STDataType *)malloc(sizeof(STDataType) * n);
//         if(nullptr == _a)
//         {
//             perror("malloc申请空间失败");
//             return;
//         }
//         _capacity = n;
//         _top = 0;
//     }
//     ~Stack()
//     {
//         cout << "~Stack()" << endl;
//         free(_a);
//         _a = nullptr;
//         _top = _capacity = 0;
//     }
// private:
//     STDataType * _a;
//     size_t _capacity;
//     size_t _top;
// };

// //两个Stack 实现队列
// class MyQueue
// {
// public:
//     //编译器默认生成的MyQueue的构造函数 调用了Stack 的构造 完成了两个成员的初始化
//     //编译器默认⽣成MyQueue的析构函数调⽤了Stack的析构，释放的Stack内部的资源
//     ~MyQueue(){} //显⽰写析构，也会⾃动调⽤Stack的析构
// private:
//     Stack pushst;
//     Stack popst;
    
// };

// int main()
// {
//     MyQueue mq;
//     return 0;
// }


//拷贝构造函数
//1.拷⻉构造函数是构造函数的⼀个重载

//2.拷⻉构造函数的第⼀个参数必须是类类型对象的引⽤，使⽤传值⽅式编译器直接报错，因为语法逻
//辑上会引发⽆穷递归调⽤。 拷⻉构造函数也可以多个参数，但是第⼀个参数必须是类类型对象的引
//⽤，后⾯的参数必须有缺省值。

//3.C++规定⾃定义类型对象进⾏拷⻉⾏为必须调⽤拷⻉构造，所以这⾥⾃定义类型传值传参和传值返
//回都会调⽤拷⻉构造完成。

//4.若未显式定义拷⻉构造，编译器会⽣成⾃动⽣成拷⻉构造函数。⾃动⽣成的拷⻉构造对内置类型成
//员变量会完成值拷⻉/浅拷⻉(⼀个字节⼀个字节的拷⻉)，对⾃定义类型成员变量会调⽤他的拷⻉构
//造。

//5.像Date这样的类成员变量全是内置类型且没有指向什么资源，编译器⾃动⽣成的拷⻉构造就可以完
// 成需要的拷⻉，所以不需要我们显⽰实现拷⻉构造。像Stack这样的类，虽然也都是内置类型，但
// 是_a指向了资源，编译器⾃动⽣成的拷⻉构造完成的值拷⻉/浅拷⻉不符合我们的需求，所以需要
// 我们⾃⼰实现深拷⻉(对指向的资源也进⾏拷⻉)。像MyQueue这样的类型内部主要是⾃定义类型
// Stack成员，编译器⾃动⽣成的拷⻉构造会调⽤Stack的拷⻉构造，也不需要我们显⽰实现
// MyQueue的拷⻉构造。这⾥还有⼀个⼩技巧，如果⼀个类显⽰实现了析构并释放资源，那么他就
// 需要显⽰写拷⻉构造，否则就不需要。

//6.传值返回会产⽣⼀个临时对象调⽤拷⻉构造，传值引⽤返回，返回的是返回对象的别名(引⽤)，没
// 有产⽣拷⻉。但是如果返回对象是⼀个当前函数局部域的局部对象，函数结束就销毁了，那么使⽤
// 引⽤返回是有问题的，这时的引⽤相当于⼀个野引⽤，类似⼀个野指针⼀样。传引⽤返回可以减少
// 拷⻉，但是⼀定要确保返回对象，在当前函数结束后还在，才能⽤引⽤返回。

//首先探究一下2.的问题 结合4
// Date (Date d)
// {
//     _year = d._year;
//     _month = d._month;
//     _day = d._dat;
// }
// int main()
// {
//     Date d1(2030,1,1);
//     Date d2(d1);
//     //每次要调用拷贝构造时 要先进行传值传参 而传值传参时一种拷贝，
//     //又形成一个新的拷贝构造
//     // Date d2(d1) -> 先传参 Date d(d1) ->再传参 Date d(d1); 无限套娃
//     d2.Print();
// }  //按值传参时 必须先创建参数对象 才能进入函数体
// //我们知道 形参是实参的拷贝 那么 对于拷贝构造 我们如果是传值传参 
// //需要先拷贝出来一个d1传进去 而想要拷贝d1 我们再次需要拷贝出来d1放进去
// //即拷贝d1 的前提是拷贝了d1 无限递归


// class Date
// {
// public:
//     Date(int year = 1,int month = 1,int day = 1)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     Date(const Date& d)  //用指针也可以
//     {
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }
//     Date (Date * d)
//     {
//         _year = d->_year;
//         _month = d->_month;
//         _day = d->_day;
//     }
//     void Print()
//     {
//         cout << _year << "/" << _month <<"/" <<_day <<endl;
//     }
// private:
//     int _year;
//     int _month;
//     int _day;

// };
// void Func1(Date d)
// {
//     cout << &d <<endl;
//     d.Print();
// }
// Date & Func2()
// {
//     Date tmp(2024,7,5);
//     tmp.Print();
//     return tmp;  //野引用
// }
// int main()
// {
//     Date d1(2024,7,5);
//     // C++规定⾃定义类型对象进⾏拷⻉⾏为必须调⽤拷⻉构造，所以这⾥传值传参要调⽤拷⻉
//     //构造
//     //所以这⾥的d1传值传参给d要调⽤拷⻉构造完成拷⻉，传引⽤传参可以减少这⾥的拷⻉
//     Func1(d1);
//     cout <<&d1 <<endl;  //不一样才对,一个拷贝 一个原来的
//     //这里可以完成拷贝 但不是拷贝构造 只是一个普通的构造
//     Date d2(&d1);
//     d1.Print();
//     d2.Print();
//     //这样写才是拷贝构造
//     Date d3(d1);
//     d2.Print();
//     Date ret = Func2();
//     ret.Print();
//     return 0;
// }





typedef int STDataType ;
class Stack
{
public:
    Stack(int n = 4)
    {
        _a = (STDataType *)malloc(sizeof(STDataType) * n);
        if(nullptr == _a)
        {
            perror("malloc申请空间失败");
            return;
        }
        _capacity = n;
        _top = 0;
    }
    Stack(const Stack& st)
    {
        //需要创造同样大小的空间
        _a = (STDataType *)malloc(sizeof(STDataType) * st._capacity);
        if(nullptr == _a)
        {
            perror("malloc 申请空间失败");
            return ;
        }
        memcpy(_a,st._a,sizeof(STDataType) * st._top);
        _top = st._top;
        _capacity = st._capacity;
    }
    void Push(STDataType x)
    {
        if(_top == _capacity)
        {
            int newcapacity = _capacity *2;
            STDataType* tmp = (STDataType*)realloc(_a, newcapacity *sizeof(STDataType));
            if(tmp == nullptr)
            {
                perror("realloc fail");
                 return;
            }
            _a = tmp;
            _capacity = newcapacity;
        }
        _a[_top++] = x;
    }
    ~Stack()
    {
        cout << "~Stack()" << endl;
        free(_a);
        _a = nullptr;
        _top = _capacity = 0;
    }
private:
    STDataType * _a;
    size_t _capacity;
    size_t _top;
};

//两个Stack 实现队列
class MyQueue
{
public:
   
   
private:
    Stack pushst;
    Stack popst;
    
};

int main()
{
    Stack st1;
    st1.Push(1);
    st1.Push(2);
    Stack st2 = st1;
    MyQueue mq1;
    // MyQueue⾃动⽣成的拷⻉构造，会⾃动调⽤Stack拷⻉构造完成pushst/popst
    // 的拷⻉，只要Stack拷⻉构造⾃⼰实现了深拷⻉，他就没问题
    MyQueue mq2 = mq1;
    return 0;
}
