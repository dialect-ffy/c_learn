#pragma once
#include <iostream>
using namespace std;
#include <assert.h>
class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
public:
    Date(int year = 1000,int month = 1,int day = 1);
    void Print()
    {
        cout << _year <<"/" << _month << "/" <<_day << endl;
    } //直接定义到类里面 默认内联
    int GetMonthDay(int year,int month);
    bool CheckDate();
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator>(const Date& d) ;
    bool operator>=(const Date& d) ;
    bool operator==(const Date& d) ;
    bool operator!=(const Date& d) ;
    //d1 += 天数
    Date & operator+=(int day);
    Date operator+(int day);
    //d1 -= 天数
    Date & operator-=(int day);
    Date operator-(int day);
    //++
    Date& operator++();
    Date operator++(int);
    //--
    Date & operator--();
    Date  operator--(int);
    int  operator-(const Date &d);
private:
    int _year;
    int _month;
    int _day;
};

//重载
ostream& operator << (ostream &out,  const Date& d);
istream& operator >> (istream &in, Date& d);
