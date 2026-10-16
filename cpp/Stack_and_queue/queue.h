#pragma once
#include <deque>
namespace bit{
    template<class T, class Container = std::deque<T>>
    class queue{
    public:
        void push(const T& x) {_con.push_back(x);}
        //void pop(){_con.erase(_Con.begin());}  //工程场景不可用 因为效率太低 涉及移动
        void pop() { _con.pop_front();}
        size_t size() { return _con.size();}
        bool empty(){return _con.empty();}
        T& front() {return _con.front();}
        T& back() {return _con.back();}
    private:
        Container _con;

    };
    
}