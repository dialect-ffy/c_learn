#pragma once
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;
namespace bit{
    class string{
    public:
        string();
        string(const char* str);
        string(const string & s);
        ~string();
        string& operator=(const string& s); 
        void reserve(size_t n);
        void push_back(char ch);
        void append(const char * str);
        string& operator+=(char ch);
        string& operator += (const char* str);
        void insert(size_t pos , char ch);
        void insert(size_t pos , const char* str);
        void erase(size_t pos = 0 , size_t len = string::npos);
        static const size_t npos = -1;  //对于整数类型可以这样写 无需类内声明类外定义  如果要类外定义就在string.cpp里面写就行 否则test.cpp也有 重复
        size_t find(char ch , size_t pos = 0) const;
        size_t find(const char* str , size_t pos = 0) const;
        string substr(size_t pos = 0,size_t len = npos) const;
        void swap(string&s);
        
        const char* c_str()const { return _str;}
        //返回类型中的 const 禁止调用者通过这个指针修改字符；末尾的 const 表示常量字符串对象也能调用它。
       char& operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }
        const char& operator[](size_t pos)const{
        assert(pos < _size);
        return _str[pos];
        }
//         前面的 const char&：返回只读字符引用，不能通过它修改字符。
// 末尾的 const：允许常量字符串对象调用这个成员函数。
        typedef char* iterator;
        iterator begin() {return _str;}
        iterator end() {return _str + _size;}
        typedef const char* const_iterator;
        const_iterator begin() const{return _str;}
        const_iterator end() const {return _str + _size;}
        //const char* 限制的是通过指针修改字符，没有禁止指针本身移动。因此常量迭代器仍然可以向后遍历。
        size_t size()const{
            return _size;
        }
        size_t capacity() const {
            return _capacity;
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };

    string operator+(const string& lhs, const char* rhs);
    string operator+(const char* lhs, const string& rhs);
    string operator+(const string& lhs,const string& rhs);
    bool operator== (const  string& lhs , const string& rhs);
    bool operator < (const string& lhs , const string& rhs);
    bool operator != (const string& lhs , const string& rhs);
    bool operator <= (const string&lhs , const string& rhs);
    bool operator > (const string& lhs , const string & rhs);
    bool operator >= (const string&lhs , const string & rhs);
    ostream& operator<<(ostream& out , const string& s);
    istream& operator >> (istream &in,string &s);
    istream& getline(istream& in, string & s, char delim = '\n');


}
void swap(bit::string&s1,bit::string&s2);
   

