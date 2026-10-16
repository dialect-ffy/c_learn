#pragma once
#include <deque>
//stack<int> -> deque
// stack<int,vector<int>>
// stack<int ,list<int>>
namespace bit{
    template <class T, class Container = std::deque<T>>
    class stack{
    public:
        void push(const T& x) {_con.push_back(x);}
        void pop(){_con.pop_back();}
        size_t size() {return _con.size();}
        bool empty() { return _con.empty();}
        T& top() { return _con.back();}
    private:
        Container _con;
    };
}