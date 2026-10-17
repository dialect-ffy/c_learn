#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#include"stack.h"
#include"queue.h"

// int main() {
// 	//bit::stack<int> st;
// 	//bit::stack<int, vector<int>> st;
// 	bit::stack<int, list<int>> st;
// 	//std::stack<int, list<int>> st;
// 	st.push(1);
// 	st.push(2);
// 	st.push(3);
// 	st.push(4);
// 	while (!st.empty()) {
// 		cout << st.top() << " ";
// 		st.pop();
// 	}
// 	cout << endl;

// 	//std::queue<int, list<int>> q;
// 	//std::queue<int, vector<int>> q; // 不支持pop_front
// 	//bit::queue<int> q;
// 	bit::queue<int, list<int>> q;
// 	//bit::queue<int, vector<int>> q; // 不支持pop_front
// 	q.push(1);
// 	q.push(2);
// 	q.push(3);
// 	q.push(4);
// 	while (!q.empty()) {
// 		cout << q.front() << " ";
// 		q.pop();
// 	}
// 	cout << endl;
// }

// void test_op1()
// {
// 	srand(time(0));
// 	const int N = 1000000;

// 	deque<int> dq;
// 	vector<int> v;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		auto e = rand() + i;
// 		v.push_back(e);
// 		dq.push_back(e);
// 	}

// 	int begin1 = clock();
// 	sort(v.begin(), v.end());
// 	int end1 = clock();

// 	int begin2 = clock();
// 	sort(dq.begin(), dq.end());
// 	int end2 = clock();

// 	printf("vector:%d\n", end1 - begin1);
// 	printf("deque:%d\n", end2 - begin2);
// }

// void test_op2()
// {
// 	srand(time(0));
// 	const int N = 1000000;

// 	deque<int> dq1;
// 	deque<int> dq2;

// 	for (int i = 0; i < N; ++i)
// 	{
// 		auto e = rand() + i;
// 		dq1.push_back(e);
// 		dq2.push_back(e);
// 	}

// 	int begin1 = clock();
// 	sort(dq1.begin(), dq1.end());
// 	int end1 = clock();

// 	int begin2 = clock();
// 	// 拷贝到vector
// 	vector<int> v(dq2.begin(), dq2.end());
// 	sort(v.begin(), v.end());
// 	dq2.assign(v.begin(), v.end());
// 	int end2 = clock();

// 	printf("deque sort:%d\n", end1 - begin1);
// 	printf("deque copy vector sort, copy back deque:%d\n", end2 - begin2);
// }



void TestPriorityQueue1() {
	// 默认情况下大的优先级高
	vector<int> v{ 3,2,7,6,0,4,1,9,8,5,2,2,3 };
	/*priority_queue<int> q1;
	for (auto& e : v)
		q1.push(e);*/
	//priority_queue<int> q1(v.begin(), v.end());

	// 调整成小的优先级高
	priority_queue<int, vector<int>, greater<int>> q1(v.begin(), v.end());

	int k;
	cin >> k;
	while (k-- && !q1.empty()) {
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;
}


template <class T>
class Less{
public:
	bool operator()(const T& x , const T& y){
		return x < y;
	}
};
template <class T>
class Greater{
public:
	bool operator()(const T& x , const T&y)
	{
		return x > y;
	}
};
#include"priority_queue.h"

void TestPriorityQueue2() {
	// 默认情况下大的优先级高
	vector<int> v{ 3,2,7,6,0,4,1,9,8,5,2,2,3 };
	//bit::priority_queue<int, vector<int>, Less<int>> q1;
	//bit::priority_queue<int, vector<int>, Greater<int>> q1;
	// bit::priority_queue<int, vector<int>> q1;
	bit::priority_queue<int, vector<int>> q1(v.begin(), v.end());
	/*for (auto& e : v)
		q1.push(e);*/

	int k;
	cin >> k;
	while (k-- && !q1.empty()) {
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;
}



//仿函数 
// class Less{
// public:
// 	bool operator()(int x, int y){
// 		return x < y;
// 	}
// };   因为调用的时候 如果实例化后  _com( , )  这样写 就跟函数一样  比如 Add( ,) ;


//暂时不知道接下来这段何意味 ？？？？？？？？？？？？？？？？？？？？？？？
// int main() {
//	//test_op1();
//	//test_op2();
//	//TestPriorityQueue2();
//
//	/*Less lessFunc;
//	cout << lessFunc(1, 2) << endl;
//	cout << lessFunc.operator()(1, 2) << endl;*/
//
//	//Less<int> lessFunc;
//	//cout << lessFunc(1, 2) << endl;
//	//Greater<int> greaterFunc;
//	//cout << greaterFunc(1, 2) << endl;
//
//	return 0;
//}
/// ///////////////////////////////////////////

// class Date
// {
// public:
// 	Date(int year = 1900, int month = 1, int day = 1)
// 		: _year(year)
// 		, _month(month)
// 		, _day(day)
// 	{}

// 	// 友元声明
// 	friend ostream& operator<<(ostream& _cout, const Date& d);
// // private:
// 	int _year;
// 	int _month;
// 	int _day;
// };

// ostream& operator<<(ostream& _cout, const Date& d)
// {
// 	_cout << d._year << "-" << d._month << "-" << d._day;
// 	return _cout;
// }

// class LessDate {
// public:
// 	bool operator()(const Date& x, const Date& y) {
// 		return (x._year < y._year) ||
// 			(x._year == y._year && x._month < y._month) ||
// 			(x._year == y._year && x._month == y._month && x._day < y._day);
// 	}
// };
// void TestPriorityQueue3() {
// 	// 大堆，需要用户在自定义类型中提供<的重载
// 	bit::priority_queue<Date, vector<Date>, LessDate> q1;  //这样写 就可以比较Date 了 因为Date 本来无法比较
// 	q1.push(Date(2026, 10, 29));
// 	q1.push(Date(2026, 10, 28));
// 	q1.push(Date(2026, 10, 30));
// 	q1.push(Date(2020, 1, 30));
// 	q1.push(Date(2021, 3, 30));

// 	int k;
// 	cin >> k;
// 	while (k-- && !q1.empty()) {
// 		cout << q1.top() << " ";
// 		q1.pop();
// 	}
// 	cout << endl;
// }

// int main() {
// 	TestPriorityQueue3();

// 	return 0;
// }

//////////////////////////////////////////////////////////////////
//接下来是关于模板进阶的内容
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const  //写在里面就可以直接用了 因为相当于可以直接比较 不用再多写一个仿函数了
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	// 友元声明
	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

class LessPDate {
public:
	bool operator()(const Date* x, const Date* y) {
		return *x < *y;
	}
};

//template<class T>
//class Less {
//public:
//	bool operator()(const T& x, const T& y) {
//		return x < y;
//	}
//};

// 特化
//template<>
//class Less<Date*> 
//{
//public:
//	bool operator()(Date* const & x, Date* const & y) {
//		return *x < *y;
//	}
//};


//所有指针都用指向对象去初始化  偏特化  单独写一个版本 就是偏特化
// template <class T>
// class Less<T*>
// {
// public:
// 	bool operator()(T*const & x, T* const & y){
// 		return *x < *y;
// 	}

// };

// class Conditional{
// public:
// 	bool operator()(int x){
// 		return x % 2 && x % 11 == 0;
// 	}
// };

// void TestPriorityQueue3() {
// 	// 自行写仿函数，控制比较逻辑，量身定做
// 	//bit::priority_queue<Date*, vector<Date*>, LessPDate> q1;
// 	bit::priority_queue<Date*> q1;
// 	q1.push(new Date(2026, 10, 29));
// 	q1.push(new Date(2026, 10, 28));
// 	q1.push(new Date(2026, 10, 30));
// 	q1.push(new Date(2020, 1, 30));
// 	q1.push(new Date(2021, 3, 30));

// 	int k;
// 	cin >> k;
// 	while (k-- && !q1.empty()) {
// 		cout << *q1.top() << " ";
// 		q1.pop();
// 	}
// 	cout << endl;

// 	vector<int> v{ 3,2,7,6,0,4,1,9,8,5,2,2,3 };
// 	std::priority_queue<int, vector<int>, greater<int>> q2;
// 	for (auto& e : v)
// 		q2.push(e);

// 	cin >> k;
// 	while (k-- && !q2.empty()) {
// 		cout << q2.top() << " ";
// 		q2.pop();
// 	}
// 	cout << endl;

// 	// 升序
// 	sort(v.begin(), v.end());

// 	// 降序
// 	sort(v.begin(), v.end(), greater<int>());  //带括号的原因是 一个是对象 一个是类 类不用括号

// 	std::vector<int> myvector;

// 	myvector.push_back(10);
// 	myvector.push_back(25);
// 	myvector.push_back(40);
// 	myvector.push_back(55);

// 	std::vector<int>::iterator it = std::find_if(myvector.begin(), myvector.end(), Conditional());
// 	std::cout << "The first odd value is " << *it << '\n';
// }

// int main() {
// 	TestPriorityQueue3();

// 	return 0;
// }

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 全特化
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

// 偏特化
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

template <class T1>
class Data<T1, char>
{
public:
	Data() { cout << "Data<T1, char>" << endl; }
};

//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data()
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
};

template <typename T1, typename T2>
class Data <T1&, T2*>
{
public:
	Data()
	{
		cout << "Data<T1&, T2*>" << endl;
	}
private:
};

int main() {
	Data<double,double> d1;
	Data<int, char> d2;
	Data<double, int> d3;
	Data<char, char> d4;
	Data<char*, char*> d5;
	Data<double*, int*> d6;
	Data<double&, int&> d7;
	Data<double&, int*> d8;

	return 0;
}









