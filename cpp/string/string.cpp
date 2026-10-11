#include "string.h"
namespace bit{
    string::string()
        :_str(new char[1])
        , _size(0)
        , _capacity(0)
        {
            _str[0] = '\0';
        }
    string::~string(){
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }
    string::string(const char* str)
        :_size(strlen(str))
        //先用初始化列表赋值再进入括号,根据定义的顺序
        {
            _capacity = _size;
            _str= new char[_size + 1];
            strcpy(_str,str);
        }
    string:: string(const string& s)
        :_str(new char[s._capacity + 1])
        ,_size(s._size)
        ,_capacity(s._capacity)
        {
            cout << "string::string(const string& s)" << endl;
            strcpy(_str,s._str);
        }
    string& string::operator=(const string& s)
     {
        if(this != &s){
            cout << "string& string::operator=(const stirng& s)" << endl;
            delete[] _str;
            _str = new char[s._capacity + 1];
            strcpy(_str,s._str);
            _size = s._size;
            _capacity = s._capacity;
        }
        return *this;
     }
    void string::reserve(size_t n )
     {
        if(n > _capacity){
            char * tmp = new char[n+1];
            strcpy(tmp,_str);
            delete [] _str;
            _str = tmp;
            _capacity = n;
        }
     }
    void string::push_back(char ch)
     {
        if(_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity *= 2);
        }
        _str[_size] = ch;
        ++_size;
        _str[_size] = '\0';
     }
    void string::append(const char* str)
    {
        string source(str);
        size_t len = strlen(str);
        if(_size + len > _capacity){
        reserve(_size + len);
        }
        strcpy(_str + _size,source.c_str());
        _size += len;
    }
    string& string::operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }
    string& string::operator += (const char* str)
    {
        append(str);
        return *this;
    }
    void string::insert(size_t pos , char ch)
    {
        assert(pos <= _size);
        if(_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity *= 2);
        }
        size_t end = _size + 1;
        while(end > pos)
        {
            _str[end] = _str[end-1];
            end--;
        }
        _str[pos] = ch;
        _size++;
    }
    void string::insert(size_t pos , const char* str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if(_size + len > _capacity)
        {
            reserve(_size + len);
        }
        size_t end = _size + len;
        //挪动数据
        while(end >= pos + len)
        {
            _str[end] = _str[end - len];
            end--;
        }
        for(size_t i = 0 ; i < len ; i++)
        {
            _str[pos + i] = str[i];
        }
        _size += len;
    }
    void string::erase(size_t pos , size_t len)
    {
        assert(pos <= _size);
        if(len == string::npos || len >= _size - pos){
            _str[pos] = '\0';
            _size = pos;
        }
        else{//跳过要删除的直接覆盖
            for(size_t i = pos + len ; i <= _size; i++){
                _str[pos++] = _str[i];
            }
            _size -= len;
        }
    }

    size_t string::find(char ch , size_t pos ) const
    {
        assert(pos <= _size);
        for(size_t i = pos ; i < _size ; i++)
        {
            if(_str[i] == ch) return i;
        }
        return npos;
    }
   
    size_t string::find(const char* str , size_t pos ) const
    {
        assert(pos <= _size);
        const char* ptr = strstr(_str+pos,str);
        if(ptr == nullptr)
        {
            return npos;
        }
        else{
            return ptr - _str;  //元素个数 等于下标
        }

    }
    string string::substr(size_t pos ,size_t len ) const
    {
        assert(pos <= _size);
        if(len == string::npos || len > _size - pos)
        {
            len  = _size - pos;
        }
        string sub;
        sub.reserve(len);
        for(size_t i = 0 ; i < len ; i++)
        {
            sub += _str[pos + i];
        }
        return sub;
    }
    void string::swap(string & s)
    {
        std::swap(_str,s._str);
        std::swap(_size,s._size);
        std::swap(_capacity,s._capacity);
        //std::swap  交换地址
    }
    string operator+(const string& lhs,const string& rhs)
    {
        string ret(rhs);
        ret += rhs.c_str();
        return ret;
    }
    string operator+(const string& lhs, const char* rhs)
    {
        string ret(lhs);
        ret += rhs;
        return ret;
    }
    string operator+(const char* lhs, const string& rhs)
    {
        string ret(rhs);
        ret += lhs;
        return ret;
    }

    bool operator== (const  string&lhs , const string& rhs)
    {
        return strcmp(lhs.c_str(),rhs.c_str()) == 0;
    }
    bool operator < (const string& lhs , const string& rhs)
    {
        return strcmp(lhs.c_str(), rhs.c_str()) < 0;
    }
    bool operator != (const string& lhs , const string& rhs)
    {
        return !(lhs == rhs);
    }
    bool operator <= (const string&lhs , const string& rhs)
    {
        return lhs < rhs || lhs == rhs;
    }
    bool operator > (const string& lhs , const string & rhs)
    {
        return !(lhs <= rhs);
    }
    bool operator >= (const string& lhs , const string & rhs)
    {
        return !(lhs < rhs);
    }
    ostream& operator<<(ostream& out , const string& s)
    {
        for(auto ch :s)
        {
            out << ch;
        }
        return out;
    }
    istream& operator >> (istream &in,string &s)
    //输入要修改字符串
    {
        char ch;
        while(in.get(ch) && ch != ' ' && ch != '\n'){
             s += ch;
        }
        return in;
    }
    istream& getline(istream& in, string & s)
    {
        char ch;
        while(in.get(ch) && ch != '\n')
        {
            s += ch;
        }
        return in;
    }
    

}
void swap(bit::string&s1,bit::string&s2){
    s1.swap(s2);
} 

