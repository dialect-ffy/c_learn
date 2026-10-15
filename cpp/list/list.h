#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
#include <initializer_list>
namespace bit{




    template <class T>
    struct list_node{
        list_node * _next;
        list_node* _prev;
        T _val;
        list_node(const T& x = T())
            :_next(nullptr)
            ,_prev(nullptr)
            ,_val(x){

        }
    };






    //Node* 不支持迭代器功能 ， 类封装他 重载运算符
    template <class T,class Ref, class Ptr >
    struct list_iterator{
        typedef list_node<T> Node;
        typedef list_iterator<T,Ref> Self;
        Node * _node;
    public:
        list_iterator(Node* node)
            :_node(node){
        }
        Ref operator*(){
            return _node->_val;
        }
        Ptr operator->(){
            return &_node->_val;
        }

        Self & operator++(){
            _node = _node->_next;
            return *this;  // this  &it    *this  it
        }
          Self & operator--(){
            _node = _node->_prev;
            return *this;  // this  &it    *this  it
        }
        Self  operator++(int){
            Self tmp(*this);
            _node = _node->_next;
            return tmp;  // this  &it    *this  it
        }
        Self  operator--(int){
            Self tmp(*this);
            _node = _node->_prev;
            return tmp;  // this  &it    *this  it
        }
        bool operator != (const  Self & it) const{
            return _node != it._node;
        }
         bool operator == (const  Self & it) const{
            return _node == it._node;
        }
    };


    // template <class T>
    // struct list_const_iterator{
    //     typedef list_node<T> Node;
    //     Node * _node;
    // public:
    //     list_const_iterator(Node* node)
    //         :_node(node){
    //     }
    //     const T& operator*(){
    //         return _node->_val;
    //     }
    //     list_const_iterator<T> & operator++(){
    //         _node = _node->_next;
    //         return *this;  // this  &it    *this  it
    //     }
    //      list_const_iterator<T> & operator--(){
    //         _node = _node->_prev;
    //         return *this;  // this  &it    *this  it
    //     }
    //     bool operator != (const list_const_iterator<T> & it){
    //         return _node != it._node;
    //     }
    // };





    template <class T>
    class list{
        typedef list_node<T> Node;
    public:
        // typedef Node* iterator; //不支持迭代器功能
        //typedef list_iterator<T> iterator;
        //typedef list_const_iterator<T> const_iterator;

        typedef list_iterator<T,T&,T*> iterator;
        typedef list_iterator<T,const T&,const T*> const_iterator;
        iterator begin(){
            return iterator(_head->_next);//构造 // 匿名对象
        }
        //end 指向最后一个的下一个 也就是头结点
        iterator end(){
            return iterator(_head);
        }
        const_iterator begin()const {
            return const_iterator(_head->_next);//构造 // 匿名对象
        }
        //end 指向最后一个的下一个 也就是头结点
        const_iterator end ()const{
            return const_iterator(_head);
        }

        void empty_init(){
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
            _size = 0;
        }
        list()
        {
            empty_init();
        }
        list(initializer_list <T> il){
            empty_init();
            for(auto & e : il){
                push_back(e);
            }
        }
        list( const list<T> & lt){
            empty_init();
            for(auto & e : lt){
                push_back(e);
            }

        }
        //lt2 = lt3
        list<T> & operator=(list <T> lt){
            swap(lt);
            return *this;
        }
        
        ~list(){
            clear();  //情空
            delete _head;  //删除哨兵位
            _head = nullptr;
        }
        
        void swap(list <T>& lt){
            std::swap(_head,lt._head);
            std::swap(_size,lt._size);
            
        }
        void push_back(const T& x){
            // Node * tail = _head->_prev;
            // Node * newnode = new Node(x);
            // tail->_next = newnode;
            // newnode -> _prev = tail;
            // newnode->_next = _head;
            // _head -> _prev = newnode;
            insert(end(),x);
            
        }
        void  push_front(const T& x){
            insert(begin(),x);
            
        }
        //pos 之前插入
        void insert(iterator pos,const T&x)
        {   
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            Node* newnode = new Node(x);
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
            _size++;

        }
        iterator erase(iterator pos)
        {
            assert(pos != end());
            Node * cur = pos._node;
            Node* prev = cur->_prev;
            Node* next = cur->_next;
            prev->_next = cur->_next;
            next->_prev = cur->_prev;
            delete cur;
            --_size;
            return iterator(next);
        }
        void pop_back(){
            erase(--end());
        }
        void pop_front(){
            erase(begin());
        }
        void clear(){
            iterator it = begin();
            while(it != end()){
                // iterator next = it;
                // ++next;
                // erase(it);
                // it = next;
                // erase 以后it 失效 ,erase 返回杀出位置下一个位置下标
                it = erase(it);  
            }
        }
    private:
        Node* _head;
        int _size;
    };
}