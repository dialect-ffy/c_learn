#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <algorithm>
#include <map>
#define _CRT_SECURE_NO_WARINGS 1
using namespace std;
 //       英文  中文  生僻字
// utf-8    1    3    4  节省空间 主流
//utf-16    2     4   4
//utf - 32   4    4   4
// int main()
// {
//     char arr1[] = "abcd01";
//     char arr2[] =  "比特abcd01";
//     arr2[2]++;  //每个汉字占3个
//     //遵循同音字原则 同音字放到一起
    
    
//     cout << arr1 <<endl;
//     cout << arr2 << endl;
//     return 0;
    
// }

//对于string 的类型  还有
//std:: wstring     windows 通常16位  linux/macos 32位
//std:: u16string  
//std:: u32string


//constructor
// void push_back(const string&s)
// {

// }
void test1()
{
    string s1;
    string s2("hello world");
    string s3(s2);
    string s4 = s2;
    string s5 = "比特abcd01";
    // cout << s2.size() << endl;
    // cout << s5.size() << endl;
    // cin >> s1;
    // cout << s1 << endl;
    // list <string> lt;
    // string s6("张三");
    // lt.push_back(s6);
    // lt.push_back("李四");
    
    //数据和方法是分离的
    char arr1[] = "比特abcd01";
    char arr2[128];   //malloc
    strcpy(arr2,arr1);
   
}
//初始化
// void test2()
// {
//     //string (const string& str, size_t pos, size_t len = npos);

//     string s1("hello worldxxxxxxxxxxxxx");
//     string s2(s1,6,3);
//     cout << s2 << endl;
//     string s3(s1,6);  //不写也是到最后 
//     cout << s3 << endl;
//     //from c-string string (const char* s);
//     //Copies the null-terminated character sequence (C-string) pointed by s.
//     string s4("hello dialectmmmmmmmmmmm");
//     cout << s4 << endl;
//     string s5(10,'*');
//     cout << s5 << endl;
//     string s6("hello world",6);  //前六个
//     cout << s6 << endl;
//     s5 = s6;
//     cout << s5 << endl;
//     s4 = "+";
//     cout << s4 << endl;

// }
//操作符
// void test3()
// {
//     string s1("12345");
//     s1[0]++;  // s1.operator[](0);
//     s1[2] = '4';
//     //cout << s1[30] << endl;  //越界报错
//     cout << s1[3] << endl;
//     cout << s1 << endl;

//     char arr[] = "12345";
//     arr[0]++;
//     //cout << arr[30] << endl;   越界不报错
//     s1 += "xxxxxx";
//     cout << s1 << endl;
// }
//一些函数
// test4()
// {
//     string s1("12345");
//     // cout << s1 << endl;
//     // cout << s1.size() << endl;
//     // cout << s1.capacity() << endl << endl;
//     // s1 += "11111111111111111111111111111111111111111111111111";
//     // cout << s1.size() << endl;
//     // cout << s1.capacity() << endl << endl;
//     // s1.clear();
//     // cout << s1.size() << endl;
//     // cout << s1.capacity() << endl;
//     // cout << s1.max_size() << endl;  //理论上的最大值
//     for(size_t i = 0; i< s1.size() ; i++)
//     {
//         s1[i] += 1;
//     }
//     cout << s1 << endl;
//     for(size_t i = 0; i<s1.length();i++)
//     {
//         s1[i] ++;
//     }
//     cout << s1 << endl;
// }

//迭代器
// void test5()
// {
//     string s1("12345");
//     //下标 + []
//     for(size_t i= 0 ; i < s1.size() ; i++)
//     {
//         cout << s1[i] << '|';
//     }
//     cout << endl;
//     //迭代器
//     string::iterator it = s1.begin();
//     while(it != s1.end())
//     {
//         cout << *it << '%';
//         ++it;
//     }
//     cout << endl;
//     //C++11 语法糖
//     //范围for
//     //自动取容器数据给对象
//     //自动判断开始和结束位置 自动迭代
//     for(auto ch : s1)
//     {
//         cout << ch << "@";
//     }
//     cout << endl;
//     list <int> lt(10,0);
//     list <int> :: iterator lit = lt.begin();
//     while(lit != lt.end())
//     {
//         cout << *lit << '*';
//         ++lit;// lit.operator++()
//     }
//     cout << endl;
//     for(auto x:lt)
//     {
//         cout << x << '@';
//     }
//     cout << endl;
//     auto x1 = 1;
//     auto x2 = 0.1;
//     int x3 = 1;
//     cout <<typeid(x1).name() << endl;
//     cout << typeid(x2).name() << endl;
//     cout << typeid(it).name() << endl;
//     cout << typeid(lit).name() << endl;
//     std::map <std::string,std::string> :: iterator mit = m.begin();
//     auto mit = m.begin;
//     std::map<std::string,std::string> m;
//     auto mit = m.begin();
//     int a = 0;
//     auto p1 = &a;
//     auto * p2 = &a;
//     // auto* p3 = a; // 报错，因为auto*代表必须是指针初始化
//     auto & r1 = a;//r1 是 a 的引用
//     const auto& r2 = a; //r2 是a 的 const 引用
//     //auto array[3] = {3,4,5} 数组中不能具有auto类型的元素
//     //c++11
//     int array[] = {1,2,3,4,5};
//     for(auto&e : array)
//         e*= 2;
//     for(auto e : array)
//     {
//         cout <<e << " " << endl;
//     }


// }
// void func(const string&s)
// {
//     //遍历容器时 可读不可写
//     string::const_iterator it = s.begin();
//     while(it != s.end())
//     {
//         //(*it)++;  错的 不可写
//         cout << *it << '%';
//         it++;
//     }
//     cout << endl;

// }

// void test6()
// {
//     string s1("12345");
//     string :: iterator it = s1.begin();
//     //遍历容器时 可读可写
//     while( it != s1.end())
//     {
//         (*it)++;
//         cout << *it << '%';
//         ++it;
//     }
//     cout << endl;

//     //从后往前遍历
//     string :: reverse_iterator rit = s1.rbegin();
//     while(rit != s1.rend())
//     {
//         (*rit)++;
//         cout << *rit << '%';
//         rit++;
//     }
//     cout << endl; 
// }

// void test7()
// {
//     string s1("12345");
//     reverse(s1.begin(),s1.end());
//     cout << s1 << endl;
//     list <int> lt = {1,2,3,4,5};
//     reverse(lt.begin(),lt.end());
//     string s2("hello");
//     s2.push_back(' ');
//     s2.push_back('w');
//     s2.push_back('o');
//     cout << s2 << endl;
//     s2.append("rld");
//     cout << s2 << endl;
//     s2.append(5,'!'); //五个 
//     cout << s2 << endl;
//     s2.append(s1.begin(),s1.end()); //区间
//     cout << s2 << endl;
//     s2.append(++s1.begin(),--s1.end());
//     cout << s2 << endl;
//     string s3("hello");
//     s3 += '';
//     cout << s3 << endl;
//     s3 += "world";
//     cout << s3 << endl;
//     s3 += s3;
//     cout << s3 << endl;

// }

// void test8()
// {
    // string s1("12345");
    // cout << s1 << endl;
    // //insert慎重使用 因为挪动数据会有损失
    // s1.insert(0,"xxxx");
    // s1.insert(0,1,'y');
    // s1.insert(s1.begin(),'y');
    // cout << s1 << endl;
    // s1.insert(5,1,'y');
    // cout << s1 << endl;
    // s1.insert(s1.begin()+5,'y');
    // cout << s1 << endl;
    // string s2("123456789");
    // cout << s2 << endl;
    // s2.erase(0,1); // 头删
    // cout << s2 << endl;
    // s2.erase(4,2);  //从下标为4开始向后删除
    // cout << s2 << endl;
    // s2.erase(4);
    // cout << s2 << endl;
    // string s3("123456789");
    // cout << s3 << endl;
    // s3.replace(3,3,"abc");
    // cout << s3 << endl;
    // //谨慎使用多替换少 少替换多 涉及挪动数据
    // s3.replace(3,5,"xxx");
    // cout << s3 << endl;
    // // C++11之前，s1.swap(s3);效率更好，C++11以后swap(s1, s3);优化了，他们效率都很好，都可以用
    // s1.swap(s3);
    // swap(s1,s3);
    // string s4("hello world hello world hello world hello world hello world hello world");
    // string s5;
    // //reverse 反转
    // s5.reserve(s4.size()); //保留储备 开空间
    // for(auto ch:s4){
    //     if(ch != ' ')
    //     s5 += ch;
    //     else
    //     s5 += '%%';
    // }
    // cout << s5 << endl; //不可以replace 涉及少换多
    // s4.swap(s5);
    // cout << s4 << endl;
//     int n = 10000;
//     size_t begin1 = clock();
//     string s6;
//     size_t old = s6.capacity();
//     for(size_t i = 0 ; i< n; i++)
//     {
//         s6 += 'x'; //不断扩容
//         if(s6.capacity() != old){
//             cout << i << "s6 扩容" << endl;
//             old = s6.capacity();
//         }
//     }
//     size_t end1 = clock();
//     cout << end1 - begin1 << endl;

//     size_t begin2 = clock();
//     string s7;
//     s7.reserve(n);
//     old = s7.capacity();
//     for(size_t i = 0 ; i< n;i++)
//     {
//         s7 += 'x';
//         if(s7.capacity()!= old){
//             cout << i << "s7扩容" << endl;
//             old = s7.capacity();
//         }
//     }
//     size_t end2 = clock();
//     cout << end2 - begin2 << endl;
// }
// void test9()
// {
//     string s1("12345xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//     cout << s1 << endl;
//     s1.reserve(10);  //不会缩
//     s1.reserve(100); //扩容
//     //大于size
//     //1. 扩容 + 插入数据
//     string s2;
//     s2.resize(100);  //好像时补\0
//     s2.resize(100,'x');
//     //小于size
//     //2.删除数据
//     s2.resize(10);
//     // 大于size
//     //3.部分插入 
//     s2.resize(50,'y');

// }

// void split(const string& url){
//     size_t i1 = url.find(':');
//     string protocol = url.substr(0,i1);
//     size_t i2 = url.find("/",i1+3);
//     string domain = url.substr(i1+3,i2-(i1+3));
//     string uri = url.substr(i2+1);
//     cout << protocol << endl;
//     cout << domain << endl;
//     cout << uri << endl;
// }

// void test10()
// {
//     string filename("string.cpp");
//     FILE*fout  = fopen(filename.c_str(),"r");
//     if(fout == NULL){
//         perror("fopen fail");
//         return;
//     }
//     /*char ch = fgetc(fout);
// 	while (ch != EOF) {
// 		cout << ch;
// 		ch = fgetc(fout);
// 	}*/
//     string url1("http://legacy.cplusplus.com/reference/string/string/find/");
// 	string url2("https://www.baidu.com/s?wd=%E7%BB%BF%E6%B0%B4%E9%9D%92%E5%B1%B1%E5%86%B0%E5%A4%A9%E9%9B%AA%E5%9C%B0%E9%83%BD%E6%98%AF%E9%87%91%E5%B1%B1%E9%93%B6%E5%B1%B1&sa=fyb_n_homepage&rsv_dl=fyb_n_homepage&from=super&cl=3&tn=baidutop10&fr=top1000&rsv_idx=2&hisfilter=1");
// 	split(url1);
// 	split(url2);
// }
void test11(){
    string s1("string.cpp");
    string s2("aaaa");
    const char*p1 = "bb";
    cout << (s1 < s2 ) << endl;
    cout << (s2 < p1) << endl;
    cout << (p1 < s2) << endl;
    cout << s1 + p1 << endl;
    cout << p1 + s1 << endl;
    cout << s1 + p1 + s2 + p1 << endl;
    /*int a, b;
	cin >> a >> b;
	cout << a<<" " <<b<< endl;*/

	// 输入hello world 得到hello 遇到空格终止了
	/*cin >> s1;
	cout << s1 << endl;

	cin >> s2;
	cout << s2 << endl;*/

	// 输入hello world 得到hello world
    // getline(cin, s1);
	// cout << s1 << endl;

	// getline(cin, s2, '#');
	// cout << s2 << endl;
}
int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    // test10();
    test11();

    return 0;
}


