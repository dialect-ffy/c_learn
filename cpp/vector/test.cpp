//#include<iostream>
//#include<vector>
//using namespace std;
//
//void test_vector1() {
//	//vector<int> v1;
//	vector<int> v2(10, 1);
//	vector<int> v3(v2);
//
//	vector<char> v4; // string s4; 结尾'\0' 接口跟串相关接口
//
//	for (size_t i = 0; i < v2.size(); i++) {
//		cout << v2[i] << " ";
//	}cout << endl;
//
//	vector<int>::iterator it2 = v2.begin();
//	while (it2 != v2.end()) {
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//
//	v2.push_back(2);
//	v2.push_back(2);
//	v2.push_back(2);
//	v2.push_back(2);
//
//	for (auto x : v2) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v2.insert(v2.begin(), 0); // 头插
//	for (auto x : v2) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v2.insert(v2.begin()+5, 0); // 第5个位置插入数据
//	for (auto x : v2) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v2.erase(v2.begin());// 头删
//	for (auto x : v2) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v2.erase(v2.begin(), v2.begin()+5);// 删[0,4]位置
//	for (auto x : v2) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	//cin >> v1;
//	//cout << v1;
//	//vector<int> v1;
//	////v1.reserve(3);
//	//v1.resize(3);
//
//	vector<int> v1(3, 0);
//	for (size_t i = 0; i < 3; i++) {
//		cin >> v1[i];
//	}
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//}
//
//void test_vector2() {
//	vector<string> v1;
//	v1.push_back("张三");
//	v1.push_back("李四");
//	v1.push_back("xxxxxxxxxxxxxxxxx");
//
//	for (const auto& e : v1) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//	v1[0] = "张三来";
//	v1[2][0] = 'y';
//
//	// 等价于
//	v1.operator[](2).operator[](0) = 'y';
//
//	for (const auto& e : v1) {
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test_vector3() {
//	// 3*5
//	vector<vector<int>> vv(3);
//	for (auto& v : vv) {
//		v.resize(5, 1);
//	}
//	/*vv[0].resize(5, 1);
//	vv[1].resize(3, 2);
//	vv[2].resize(4, 3);*/
//
//	cout << vv[1][2] << endl;
//	cout << vv.operator[](1).operator[](2) << endl; // 等价
//
//	for (size_t i = 0; i < vv.size(); i++) {
//		for (size_t j = 0; j < vv[i].size(); j++) {
//			cout << vv[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//}
//
//int main() {
//	test_vector3();
//
//	return 0;
//}

///////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
using namespace std;

#include"vector.h"

void test_vector1() {
	bit::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v.size(); i++) {
		v[i]++;
	}

	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	v.pop_back();
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	//v.pop_back();
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}


void test_vector2() {
	bit::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin(), 0);
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;

	auto it = v.begin() + 3;
	v.insert(it, 30);
	// insert以后，it是否失效？会失效
	// 注意insert我们认为it失效，不能使用
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3() {
	bit::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;

	auto it = v.begin() + 3;
	v.erase(it);
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl << endl;

	bit::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(6);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);

	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;

	// 删除所有偶数
	auto it1 = v1.begin();
	while (it1 != v1.end()) {
		if (*it1 % 2 == 0) {
			// erase以后的迭代器对象失效了，不能去使用
			// 失效的迭代器要更新以后才能使用
			it1 = v1.erase(it1);
		}
		else {
			++it1;
		}
	}

	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	test_vector3();
}