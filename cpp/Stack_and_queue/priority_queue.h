#pragma once
#include<vector>

namespace bit {
    //template <class T, class Container = std::vector<T>, class Compare = std::less<T> >
    //进行了解耦 Container 可以是不同的
    //Compare
    template <class T , class Container = std::vector<T>  ,class Compare = Less<T> >
    class priority_queue{
    public:
        priority_queue(){}
       template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last) {
    // 将区间中的元素放入底层容器
        while (first != last) {
            _con.push_back(*first);
            ++first;
        }

        // 从最后一个非叶子节点开始，向下调整建堆
        for (int parent = static_cast<int>(_con.size() / 2) - 1;
            parent >= 0;
            --parent) {
            adjust_down(parent);
        }
    }
        void adjust_up(int child){
            int parent = (child - 1) / 2;
            while(child > 0){
               //if (_con[parent] < _con[child])
               Compare compare;
               if(compare(_con[parent], _con[child])){
                    std::swap(_con[child] , _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
               }
               else{
                    break;
               }
            }
        }
        void push(const T& x){
            _con.push_back(x);
            adjust_up(_con.size() - 1);
        }
        void adjust_down(int parent){
            int child = parent * 2 + 1;
            Compare compare;
            while(child < _con.size()){
                if(child+1 < _con.size() && compare(_con[child], _con[child+1]))
                ++child;
                if(compare(_con[parent], _con[child])){
                    std::swap(_con[parent] , _con[child]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else{
                    break;
                }
            }
        }
        void pop(){
            std::swap(_con[0],_con[_con.size() - 1]);
            _con.pop_back();
            adjust_down(0);
        }
        const T& top(){
            return _con[0];
        }
        bool empty(){
            return _con.empty();
        }
    private:
        Container _con;
        //Compare _con;
    };
}