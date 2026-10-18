#include<iostream>
using namespace std;
//#include"Stack.h"
//
//// 声明->语法检查，函数名参数返回值是否对得上
////template<class T>
////T Add(const T& left, const T& right);
////
////int Func(int x);
//
//int main() {
//	// error LNK2019:无法解析的外部符号 "int __cdecl Add<int>(int const &,int const &)" (??$Add@H@@YAHAEBH0@Z
//	cout << Add(1, 2) << endl;      // call Add(?)
//	cout << Add(1.0, 2.0) << endl;  // call Add(?)
//
//	cout << Func(1) << endl;        // call Func(?)
//
//	//cout << Add('a', 'b') << endl;  // call Add(?)
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////

//继承
// class Person
// {
// public:
// 	// 进入校园/图书馆/实验室刷二维码等身份认证
// 	void identity()
// 	{
// 		cout << "void identity()" << _name << endl;
// 	}

// 	void func()
// 	{
// 		cout << _age << endl;
// 	}

// protected:
// 	string _name = "张三"; // 姓名
// 	string _address; // 地址
// 	string _tel;     // 电话

// private:
// 	int _age = 18; // 年龄 == 私房钱
// };

// class Student : public Person
// {
// public:
// 	// 学习
// 	void study()
// 	{
// 		// ...
// 		cout << _tel << endl;
// 		// cout << _age << endl; // 不可见，类里面无法使用
// 		func(); // 间接使用
// 	}
// protected:
// 	int _stuid; // 学号
// };

// class Teacher : public Person
// {
// public:
// 	// 授课
// 	void teaching()
// 	{
// 		//...
// 	}
// protected:
// 	string title; // 职称
// };

// int main() {
// 	Student s;
// 	Teacher t;
// 	s.identity();
// 	t.identity();

// 	return 0;
// }



// #include<vector>

// namespace bit
// {
// 	template<class T>
// 	class stack : public std::vector<T>
// 	{
// 	public:
// 		void push(const T& x)
// 		{
// 			// 基类是类模板时，需要指定一下类域，
// 			// 否则编译报错:error C3861: “push_back”: 找不到标识符
// 			// 因为stack<int>实例化时，也实例化vector<int>了
// 			// 但是模版是按需实例化，push_back等成员函数未实例化，所以找不到
// 			//vector<T>::push_back(x);
// 			vector<T>::push_back(x);
// 		}
// 		void pop()
// 		{
// 			vector<T>::pop_back();
// 		}

// 		const T& top()
// 		{
// 			return vector<T>::back();
// 		}

// 		bool empty()
// 		{
// 			return vector<T>::empty();
// 		}
// 	};
// }

// int main()
// {
// 	bit::stack<int> st;
// 	st.push(1);
// 	st.push(2);
// 	st.push(3);
// 	while (!st.empty())
// 	{
// 		cout << st.top() << " ";
// 		st.pop();
// 	}
// 	return 0;
// }


// class Person
// {
// public:
// 	// 进入校园/图书馆/实验室刷二维码等身份认证
// 	void identity()
// 	{
// 		cout << "void identity()" << _name << endl;
// 	}

// 	void func()
// 	{
// 		cout << _age << endl;
// 	}

// protected:
// 	string _name = "张三"; // 姓名
// 	string _address; // 地址
// 	string _tel;     // 电话
// 	int _age = 18; // 年龄 == 私房钱
// };

// class Student : public Person
// {
// public:
// 	// 学习
// 	void study()
// 	{
// 		// ...
// 		cout << _tel << endl;
// 		// cout << _age << endl; // 不可见，类里面无法使用
// 		func(); // 间接使用
// 	}
// protected:
// 	int _stuid; // 学号
// };

// int main() {
// 	Student s;
// 	Person* ptr = &s;  //派生类的对象可以赋值给基类的指针或者引用
// 	Person& ref = s;
// }






//Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
// class Person
// {
// protected:
// 	string _name = "小李子"; // 姓名
// 	int _num = 111; // 身份证号
// };

// class Student : public Person
// {
// public:
// 	void Print()
// 	{
// 		cout << " 姓名:" << _name << endl;
// 		cout << " 身份证号:" << Person::_num << endl;
// 		cout << " 学号:" << _num << endl;
// 	}
// protected:
// 	int _num = 999; // 学号
// };

// class A
// {
// public:
// 	void fun()
// 	{
// 		cout << "func()" << endl;
// 	}
// };

// class B : public A
// {
// public:
// 	void fun(int i)
// 	{
// 		cout << "func(int i)" << i << endl;
// 	}
// };

// int main()
// {
// 	//Student s1;
// 	//s1.Print();

// 	B b;
// 	b.fun(10);
//     //b.fun();  // 函数名相同就会隐藏基类的
// 	b.A::fun();

// 	return 0;
// };

/////////////////////////////////////////////////////////////////
// class Person
// {
// public:
// 	Person(const char* name)
// 		: _name(name)
// 	{
// 		cout << "Person()" << endl;
// 	}

// 	Person(const Person& p)
// 		: _name(p._name)
// 	{
// 		cout << "Person(const Person& p)" << endl;
// 	}

// 	Person& operator=(const Person& p)
// 	{
// 		cout << "Person operator=(const Person& p)" << endl;
// 		if (this != &p)
// 			_name = p._name;

// 		return *this;
// 	}

// 	~Person()
// 	{
// 		cout << "~Person()" << endl;
// 	}
// protected:
// 	string _name; // 姓名
// };

// class Student : public Person
// {
// public:
// 	Student(const char* name, int num)
// 		: Person(name)
// 		,_num(num)
// 	{
// 		cout << "Student()" << endl;
// 	}

// 	Student(const Student& s)
// 		: Person(s)
// 		, _num(s._num)
// 	{
// 		cout << "Student()" << endl;
// 	}

// 	// s1 = s3
// 	Student& operator=(const Student& s)
// 	{
// 		if (this != &s) {
// 			Person::operator=(s); // 必须调用基类的复制 由于隐藏 指定基类的类域
// 			_num = s._num;
// 		}

// 		return *this;
// 	}
// 	// :9:12
// 	~Student() {
// 		// Person::~Person();
// 		// ...
// 		cout << "~Student()" << endl;
// 	}

// 	// 析构函数名会被处理成destructor，所以构成隐藏，因为多态一个原因，具体后面讲
// 	/*destructor() {
// 		Person::destructor();
// 	}*/

// protected:
// 	int _num; //学号
// };



// //实现一个不能被继承的类
// // C++11的方法
// class Base final
// {
// public:
// 	void func5() { cout << "Base::func5" << endl; }
// protected:
// 	int a = 1;
// //private:
// 	// C++98的方法
// 	Base()
// 	{}
// };

// class Derive :public Base
// {
// public:
// 	/*Derive()
// 		:Base()
// 	{}*/

// 	void func4() { cout << "Derive::func4" << endl; }
// protected:
// 	int b = 2;
// };

// int main()
// {
// 	Student s1("jack", 18);
// 	//Student s2(s1);

// 	//Student s3("张三", 20);
// 	//s1 = s3;

// 	Derive d;

// 	return 0;
// }



// //前置声明
// class Student;

// class Person
// {
// public:
// 	friend void Display(const Person& p, const Student& s);
// protected:
// 	string _name; // 姓名
// };

// class Student : public Person
// {
// public:
// 	friend void Display(const Person& p, const Student& s);
// protected:
// 	int _stuNum; // 学号
// };

// void Display(const Person& p, const Student& s)
// {
// 	cout << p._name << endl;
// 	cout << s._stuNum << endl;
// }

// int main()
// {
// 	Person p;
// 	Student s;
// 	Display(p, s);
// 	return 0;
// }



// class Person
// {
// public:
// 	string _name;
// 	static int _count;
// };
// int Person::_count = 0;

// class Student : public Person
// {
// protected:
// 	int _stuNum;
// };

// int main()
// {
// 	Person p;
// 	Student s;
// 	// 这里的运行结果可以看到非静态成员_name的地址是不一样的
// 	// 说明派生类继承下来了，父派生类对象各有一份
// 	cout << &p._name << endl;
// 	cout << &s._name << endl;

// 	// 这里的运行结果可以看到静态成员_count的地址是一样的
// 	// 说明派生类和基类共用同一份静态成员
// 	cout << &p._count << endl;
// 	cout << &s._count << endl;

// 	// 公有的情况下，父派生类指定类域都可以访问静态成员
// 	cout << Student::_count << endl;
// 	cout << Person::_count << endl;
// }


class Person
{
public:
	string _name; // 姓名
	int _tel;
	int age;
	//...
};
class Student : virtual public Person
{
protected:
	int _num; //学号
};
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};

int main()
{
	// 编译报错：error C2385: 对“_name”的访问不明确
	Assistant a;
	a._name = "peter";

	// 需要显示指定访问哪个基类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";

	return 0;
}