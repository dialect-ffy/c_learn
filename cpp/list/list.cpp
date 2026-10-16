#include "list.h"
#include <iostream>
using namespace std;
// void test1(){
//     bit::list<int> lt;
//     lt.push_back(1);
//     lt.push_back(2);
//     lt.push_back(3);
//     lt.push_back(4);
//     //内存底层中都是一个指针 但是类型让编译器编译不同指令
//     auto* ptr = lt._head->_next;
//     ++ptr;
//     bit ::list<int>::iterator it = lt.begin();
//     while(it != lt.end()){
//         cout << *it << " ";
//         ++it;
//     } cout << endl;
// }
void test2(){
    bit::list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_front(10);
    lt.push_front(20);
    lt.push_front(30);
    lt.push_front(40);
    for(auto& e : lt){
        cout << e << " ";
    }cout << endl;
    lt.pop_front();
    lt.pop_back();
     for(auto& e : lt){
        cout << e << " ";
    }cout << endl;
    lt.clear();
     for(auto& e : lt){
        cout << e << " ";
    }cout << endl;

}

void test3(){
    bit::list<int> lt1;
    lt1.push_back(1);
    lt1.push_back(2);
    lt1.push_back(3);
    lt1.push_back(4);
    for(auto &e : lt1){
        cout << e << " ";
    }cout << endl;
    bit::list<int> lt2(lt1); //浅拷贝会析构两次
    for(auto& e : lt2){
        cout << e << " ";
    }
    cout << endl;
    bit::list<int> lt3 = {10,20,30,40,50};
    bit::list<int>::iterator it3 = lt3.begin();
    while(it3 != lt3.end()){
        *it3 += 10;
        cout << *it3 << " ";
        ++it3;
    }cout << endl;
    for(auto &e : lt3){
        cout << e << " ";
    }cout << endl;
    lt2 = lt3;
    for(auto& e : lt3){
        cout << e << " ";
    }cout << endl;
   for(auto& e : lt2){
        cout << e << " ";
    }cout << endl;
    const bit::list<int> lt4 = {10,20,30,40,50};
    bit::list<int>::const_iterator it4 = lt4.begin(); // 迭代器浅拷贝
    while(it4 != lt4.end()){
        // *it4 += 10;
        cout << *it4 << " ";
        ++it4;
    }cout << endl;
}
struct Pos{
    int row;
    int col;
};
void test4(){
    Pos p1 = {1,1};
    Pos* ptr = &p1;
    ptr->row++;
    bit::list<Pos> lt1;
    lt1.push_back(p1);
    lt1.push_back(p1);
    lt1.push_back(p1);
    lt1.push_back(p1);
    bit::list<Pos>::iterator it1 = lt1.begin(); // 迭代器浅拷贝
    while(it1 != lt1.end()){
      cout << (*it1).row << " :" <<(*it1).col << " ";
      cout << it1->row << " :" <<it1->col << " ";
      cout << it1.operator->()->row<< " "; //省略了一个箭头 为了可读性
        ++it1;
    }cout << endl;
    
}
int main()
{
    test4();
    return 0;
}