#pragma once
#include <assert.h>
namespace bit{
    template <class T>
    class vector{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        iterator begin() {return _start;}
        iterator end() {return _finish;}
        const_iterator begin() const{return _start;}
        const_iterator end() const{return _finish;}
        //构造函数
        vector()
            {

        }
        vector(size_t n , const T& val = T() )
        {
            // reserve 之前要初始化 所以可以在private那里给一个缺省值然后同时可以把默认构造那里的空出来了
            reserve(n);
            for(size_t i = 0 ; i < n ; i ++){
                *_finish = val;
                ++_finish;
            }
        }
        vector(initializer_list<T> il){
            reserve(il.size());
            for(auto & e : il){
                push_back(e);
            }
        }
         template<class InputIterator>
        vector (InputIterator first , InputIterator last){
            while(first != last){
                push_back(*first);
                ++first;
            }
        }
        void swap(vector <T> & v){
            std:: swap(_start, v._start);
            std:: swap(_finish, v._finish);
            std:: swap(_end_of_storage, v._end_of_storage);
        }
        vector(const vector<T>& v){
            vector tmp(v.begin(),v.end());
            swap(tmp);
        }
        //v1 = v4
        vector<T> & operator = (vector<T> v ){
            swap(v);
            return *this;
        }
        ~vector(){
            if(_start){
                delete[] _start; 
                _start = _finish = _end_of_storage;
            }
        }
        size_t size()const {return _finish - _start;}
        size_t capacity()const{return _end_of_storage - _start;}
        bool empty(){return size() == 0;}
        T& operator[](size_t pos){
            assert(pos < size() );
            return _start[pos];
        }

        void reserve(size_t n);
        void resize(size_t n , const T& x = T());
        void push_back(const T& x);
        void pop_back();
        void insert(iterator pos, const T& x);
        iterator erase(iterator pos);

    private:
        iterator _start =nullptr;
        iterator _finish = nullptr;
        iterator _end_of_storage = nullptr;

    };
    template <class T>
    void vector<T>::reserve(size_t n){
        //不考虑缩容 因为不支持释放部分空间，缩容代价很大
        if(n > capacity()){
            size_t old_size = size();
            //size() 是 finish - start 如果扩容 start是新空间  finish是旧空间 算出来的size()有问题
            //开空间 + 拷贝数据 + 释放旧空间
            T * tmp = new T[n];
            if(_start){
                // memcpy(tmp,_start,old_size * sizeof(T));
                for(size_t i = 0 ; i < old_size ; i++){
                    tmp[i] = _start[i];
                }  //对于深拷贝的类 入string 调用他的operator= 来完成深拷贝
                delete[] _start;
            }
            _start = tmp;
            _finish = _start + old_size;
            _end_of_storage = _start + n;
        }
    }
    template <class T>
    void vector<T>::resize(size_t n , const T& x){
        if(n > capacity())
            reserve(n);
        if( n > size()){  //插入
            while(_finish != _start + n){
                *_finish =  x;
                ++_finish;
            }
        }
        else{ //删除保留前n个
            _finish = _start + n;
        }
    }
    template <class T>
    void vector<T>::push_back(const T& x){
        if(_finish == _end_of_storage){
            size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
            reserve(newCapacity);
        }
        *_finish = x;
        _finish++; 
    }
    template <class T>
    void vector<T>::pop_back(){
        assert(!empty());
        _finish--;
    }
    template <class T>
    void vector<T>::insert(iterator pos , const T& x){
        assert(pos >= _start);
        assert(pos <= _finish);
        //扩容， pos迭代器失效
        if(_finish == _end_of_storage){
            size_t len = pos - _start;
            size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
            reserve(newCapacity);
            pos = _start + len; //因为reserve是重开一段空间 因此可能会失效
        }
        //挪动数据
        // memmove(pos+1,pos,sizeof(T) * (_finish - pos));
       iterator it = _finish - 1;
       while(it >= pos ){
        *(it+1) = *(it);
        it--;
       }
        *pos = x;
        ++_finish;
    }

    //无法区分内嵌类型和静态成员变量,typename 告诉编译器这里是内嵌类型
    template <class T>
    typename vector<T>::iterator vector<T>::erase(iterator pos){
        assert(pos >= _start);
        assert(pos < _finish);
        iterator it = pos + 1;
        //对于最后一个偶数会有bug 判断逻辑错开最后越界
        while(it < _finish){
            *(it - 1) = *it;
            ++it;
        }//删除会导致往前挪动 如果在遍历的过程在中++迭代器 就会有没判断的。 
        --_finish;
        return pos;
    }
}