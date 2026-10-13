#include <iostream>
#include <vector>
using namespace std;
void test_vector1(){
    // vector<int> v1;//空vector
    vector <int> v2(10,1);
    vector <int> v3(v2);
    vector <char>v4;  // string s4; 结尾'\0'接口跟串相关接口
    //遍历
    for(size_t i = 0 ; i < v2.size(); i++)
    {
        cout  << v2[i] << " ";
    }cout << endl;
    vector <int> :: iterator it2 = v2.begin();
    while(it2 != v2.end())
    {
        cout << *it2 << " ";
        it2++;
    }cout << endl;
    //尾插 尾删
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    for(auto x : v2){
        cout << x << " ";
    }cout << endl;
    v2.pop_back();
    v2.pop_back();
     for(auto x : v2){
        cout << x << " ";
    }cout << endl;

    //头插 头删
    v2.insert(v2.begin(),0);  //比较特殊 要用迭代器
    for(auto x: v2){
        cout << x << " ";
    }cout << endl;
    v2.insert(v2.begin()+5,0); // 第五个位置插入
    for(auto x: v2){
        cout << x << " ";
    }cout << endl;
    v2.erase(v2.begin());  //头删
    for(auto x : v2){
        cout << x << " ";
    }cout << endl;
    v2.erase(v2.begin(),v2.begin() + 5); // 左闭右开  0 - 4
    for(auto x : v2){
        cout << x << " ";
    }cout << endl;

    //输入 
    //cin >> v1;
    // cout << v1;
    //vector<int> v1;
    ////v1.reserve(3);  只会扩大capacity  不会影响size 这也就导致[] 没办法用 因为对于operator[] 第一个条件是assert(pos < size)
    //v.resize(3);   // size也会变 因为会初始化这种   同时resize 不会缩小容量
    vector <int> v1(3,0);
    for(size_t i = 0 ; i < 3 ; i++)
    {
        cin >> v1[i];
    }
    for(auto x : v1){
        cout << x << " ";
    }cout << endl;
}

void test_vector2(){
    vector <string> v1;
    v1.push_back("张三");
    v1.push_back("李四");
    v1.push_back("xxxxxxxxxxxxxxxxxxxxx");
    for(const auto& e : v1){  //不建议不引用 因为那样就会调用拷贝构造（字符串传给字符串）
        cout << e << " ";
    }cout << endl;
    v1[0] = "张三来";
    v1[2][0] = 'y';
    //等价于v1.operator[](2).operator[](0) = 'y';
    for(const auto& e : v1)
    {
        cout << e << " ";
    }cout << endl;

   

}
void test_vector3()
{
    //3 * 5
    vector <vector<int>> vv(3);
    for(auto& v: vv){
        v.resize(5,1);
    }
    //vv[0].resize(5,1);
    //vv[1].resize(3,2);
    //vv[2].resize(4,3);
    cout << vv[1][2] << endl;
    //vv.operator[](1).operator[](2);
    for(size_t i = 0 ; i < vv.size() ; i++){
        for(size_t j = 0; j < vv[i].size() ; j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}
int main()
{
    // test_vector1();
    // test_vector2();
    test_vector3();
    return 0;
}