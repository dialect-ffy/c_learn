// #include <iostream>
// #include <list>
// #include <vector>
// #include <forward_list>
// #include <algorithm>
// using namespace std;
// void test1(){
//     list<int> lt1(10,1);
//     list <int> lt2;
//     lt2.push_back(1);
//     lt2.push_back(2);
//     lt2.push_back(3);
//     lt2.emplace_back(4);
//     lt2.emplace_back(5);
//     list<int> lt3 = {1,2,345,6,7};
//     list<int>::iterator it1 = lt1.begin();
//     //为什么只能用迭代器不可用[ ] 
//     //由于底层结构的原因 list 的底层结构是双向循环链表 链式结构
//     while(it1 != lt1.end()){
//         cout << *it1 << " ";
//         it1++;
//     } cout << endl;
//     for(auto &e : lt2){
//         cout << e << " ";
//     } cout << endl;
//     for(auto & e : lt3){
//         cout << e << " ";
//     } cout << endl; 

// }
// //关于迭代器的部分知识点
// //均支持 * != ==
// //单向迭代器  ++  forward_list
// //双向迭代器 ++ -- list map/set  bidirectional
// //随机迭代器  ++ -- + -  random
// //因此这就会引发一些问题 比如std中有的模板只支持随机迭代器 因为涉及 + = 如sort 则传入的如果是list 
// //list 是双向迭代器 无法使用 std的sort 会报错 但是它自己有自己的迭代器
// //对于 reverse 其模板是双向迭代器 的类型 的 可以传random bi 但是单向的就不可以 比如forward_list
// //同时也有特殊的比如find 其模板为inputiterator 表示所有的都可以用


// void test2(){
//     list <int> lt2;
//     lt2.push_back(1);
//     lt2.push_back(2);
//     lt2.push_back(3);
//     lt2.push_back(4);
//     lt2.push_back(5);
//     for(auto & e : lt2){
//         cout << e << " ";
//     }cout << endl;
//     auto it2 = lt2.begin();
//     int n = 3;
//     while(n--){
//         it2++;  //找到第三个位置 然后插入
//     }
//     lt2.insert(it2,30);   //不可写lt2.begin() + 3 因为对于list的迭代器是双向迭代器而非随机迭代器 没有 + - 这种运算符重载
//     for(auto&e : lt2){
//         cout << e << " ";
//     }cout << endl;
//     it2 = find(lt2.begin(),lt2.end(),30);
//     // find (InputIterator first, InputIterator last, const T& val);
//     if(it2 != lt2.end()){
//         lt2.erase(it2);//看是按照下标删除 还是按照迭代器删除
//     }
//     for(auto&e : lt2){
//         cout <<e << " ";
//     }cout << endl;
//     reverse(lt2.begin(),lt2.end());
//     for(auto &e:lt2){
//         cout << e << " ";
//     }cout << endl;
//     forward_list <int> flt = {1,2,3,4,5};
//     //reverse(flt.begin(),flt.end()); //不支持单向迭代器
//     //sort(lt2.begin(),lt2.end()) // 不支持双向迭代器

// }
// bool single_digit(const int& value) {return value < 10;}
// bool is_even(const int& value) {return value % 2 == 0;}
// void test3()
// {
//     list<int> lt2;
//     lt2.push_back(1);
//     lt2.push_back(2);
//     lt2.push_back(3);
//     lt2.push_back(4);
//     lt2.push_back(5);
//     for(auto & e : lt2){
//         cout << e << " ";
//     }cout << endl;

//     //结点移到头部
//     auto it2 = find(lt2.begin(),lt2.end(),4);
//     if(it2 != lt2.end()){
//         lt2.splice(lt2.begin(),lt2,it2);
//     }
//     // list<int> a = {1, 2, 3};  // 4 5 6 1 2 3
//     // list<int> b = {4, 5, 6};  // 
//     // a.splice(a.begin(), b);  

//     // list<int> a = {1, 2, 3};
//     // list<int> b = {4, 5, 6};
//     // auto it = b.begin(); // it 指向 4
//     // ++it;                // it 现在指向 5
//     // a.splice(a.begin(), b, it);
//     //         a.splice(a.begin(), b, it);
//     // //       放在哪里  从哪搬  搬哪个
//         //list<int> a = {1, 2, 3};
//     // list<int> b = {4, 5, 6};
//     // auto first = b.begin(); // first 指向 4
//     // auto last = b.begin();
//     // ++last;                // 指向 5
//     // ++last;                // 指向 6
//     // a.splice(a.begin(), b, first, last);
//     for(auto & e : lt2){
//         cout << e << " ";
//     }cout << endl;

//     //friend + erase
//     lt2.remove(3);
//     lt2.remove(30); //不存在也不会报错
//     for(auto& e : lt2){
//         cout << e << " ";

//     } cout << endl;
//     lt2.remove_if(is_even);  //里面加条件 会自动遍历判断  无需带括号
//     for(auto & e : lt2){
//         cout << e << " ";
//     }cout << endl;
//     lt2.sort();//属于list的sort
//     lt2.unique(); //要求是有序的
//     for(auto & e : lt2){
//         cout << e << " ";
//     }cout << endl;
// }




// //接下来是看排序的耗时 对于顺序表排序肯定是比链表要有优势的
// void test_op1()
// {
// 	srand(time(0));
// 	const int N = 1000000;

// 	list<int> lt1;
// 	vector<int> v;

// 	for (int i = 0; i < N; ++i)
// 	{
// 		auto e = rand() + i;
// 		lt1.push_back(e);
// 		v.push_back(e);
// 	}

// 	int begin1 = clock();
// 	// 排序
// 	sort(v.begin(), v.end());
// 	int end1 = clock();

// 	int begin2 = clock();
// 	lt1.sort();
// 	int end2 = clock();

// 	printf("vector sort:%d\n", end1 - begin1);
// 	printf("list sort:%d\n", end2 - begin2);
// }

// void test_op2()
// {
// 	srand(time(0));
// 	const int N = 1000000;

// 	list<int> lt1;
// 	list<int> lt2;

// 	for (int i = 0; i < N; ++i)
// 	{
// 		auto e = rand() + i;
// 		lt1.push_back(e);
// 		lt2.push_back(e);
// 	}

// 	int begin1 = clock();
// 	// 拷贝vector
// 	vector<int> v(lt2.begin(), lt2.end());
// 	// 排序
// 	sort(v.begin(), v.end());

// 	// 拷贝回lt2
// 	lt2.assign(v.begin(), v.end());

// 	int end1 = clock();

// 	int begin2 = clock();
// 	lt1.sort();
// 	int end2 = clock();

// 	printf("list copy vector sort copy list sort:%d\n", end1 - begin1);
// 	printf("list sort:%d\n", end2 - begin2);
// }

// int main(){
//     test_op1();
//     test_op2();
//     return 0 ;
// }