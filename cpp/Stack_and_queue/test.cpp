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
int main(){
	TestPriorityQueue2();
	return 0;
}