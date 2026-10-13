#include "string.h"

int main() {
    bit::string s("hello");

    bit::getline(cin, s);
    cout << s << endl;

    return 0;
}
// #include "string.h"

// int main() {
//     bit::string s1("abc");
//     bit::string s2(s1);

//     cout << "复制后：" << endl;
//     cout << "s1: " << s1 << endl;
//     cout << "s2: " << s2 << endl;

//     s2[0] = 'X';

//     cout << "修改 s2 后：" << endl;
//     cout << "s1: " << s1 << endl;
//     cout << "s2: " << s2 << endl;

//     return 0;
// }
// #include "string.h"

// int main() {
//     bit::string s1("abc");
//     bit::string s2("hello");

//     s2 = s1;

//     cout << "赋值后：" << endl;
//     cout << "s1: " << s1 << endl;
//     cout << "s2: " << s2 << endl;

//     s2[0] = 'X';

//     cout << "修改 s2 后：" << endl;
//     cout << "s1: " << s1 << endl;
//     cout << "s2: " << s2 << endl;

//     s2 = s2;
//     cout << "自赋值后：" << s2 << endl;

//     return 0;
// }
// #include "string.h"

// int main() {
//     bit::string s;

//     cout << "初始："
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     s.push_back('a');

//     cout << "追加 a：" << s
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     s.reserve(10);

//     cout << "扩容到 10：" << s
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     s.reserve(2);

//     cout << "请求容量 2：" << s
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     s.push_back('b');

//     cout << "追加 b：" << s
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     return 0;
// }
// #include "string.h"

// int main() {
//     bit::string s("ab");

//     s.append("cd");
//     cout << "append 后：" << s
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     s += 'X';
//     cout << "追加字符后：" << s
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     s += "YZ";
//     cout << "追加字符串后：" << s
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     s.append("");
//     cout << "追加空串后：" << s
//          << " _size = " << s.size()
//          << " _capacity = " << s.capacity() << endl;

//     return 0;
// }
// #include "string.h"

// int main() {
//     bit::string s("abc");

//     s.insert(1, 'X');
//     cout << "插入字符：" << s << endl;

//     s.insert(0, "YZ");
//     cout << "头部插入字符串：" << s << endl;

//     s.insert(s.size(), '!');
//     cout << "末尾插入字符：" << s << endl;

//     bit::string empty;
//     empty.insert(0, 'A');
//     cout << "空串插入：" << empty << endl;

//     return 0;
// }

// #include "string.h"

// int main() {
//     bit::string s1("abcdef");
//     s1.erase(2, 2);
//     cout << "删除中间：" << s1
//          << " _size = " << s1.size() << endl;

//     bit::string s2("abcdef");
//     s2.erase(3);
//     cout << "删除到末尾：" << s2
//          << " _size = " << s2.size() << endl;

//     bit::string s3("abcdef");
//     s3.erase();
//     cout << "全部删除：[" << s3 << "]"
//          << " _size = " << s3.size()
//          << " _capacity = " << s3.capacity() << endl;

//     return 0;
// }

// #include "string.h"

// int main() {
//     bit::string s("abcabc");

//     cout << "查找字符 b：" << s.find('b') << endl;
//     cout << "从下标 2 查找 b：" << s.find('b', 2) << endl;

//     cout << "查找字符串 bc：" << s.find("bc") << endl;
//     cout << "从下标 2 查找 bc：" << s.find("bc", 2) << endl;

//     cout << "找不到字符："
//          << (s.find('X') == bit::string::npos) << endl;

//     cout << "找不到字符串："
//          << (s.find("XY") == bit::string::npos) << endl;

//     cout << "从末尾查找字符："
//          << (s.find('a', s.size()) == bit::string::npos) << endl;

//     return 0;
// }

// #include "string.h"

// int main() {
//     bit::string s("abcdef");

//     bit::string sub = s.substr(2, 3);
//     cout << "取中间：" << sub << endl;

//     sub[0] = 'X';
//     cout << "修改子串后：" << sub << endl;
//     cout << "原字符串：" << s << endl;

//     cout << "取到末尾：" << s.substr(3) << endl;
//     cout << "长度超过剩余：" << s.substr(4, 100) << endl;
//     cout << "从末尾取：[" << s.substr(s.size()) << "]" << endl;

//     return 0;
// }

// #include "string.h"

// int main() {
//     bit::string a("abc");
//     bit::string b("hello");

//     a.swap(b);

//     cout << "成员 swap 后：" << endl;
//     cout << "a: " << a
//          << " _size = " << a.size()
//          << " _capacity = " << a.capacity() << endl;
//     cout << "b: " << b
//          << " _size = " << b.size()
//          << " _capacity = " << b.capacity() << endl;

//     ::swap(a, b);

//     cout << "类外 swap 后：" << endl;
//     cout << "a: " << a
//          << " _size = " << a.size()
//          << " _capacity = " << a.capacity() << endl;
//     cout << "b: " << b
//          << " _size = " << b.size()
//          << " _capacity = " << b.capacity() << endl;

//     return 0;
// }

// #include "string.h"

// int main() {
//     bit::string a("ab");
//     bit::string b("cd");

//     bit::string r1 = a + b;
//     bit::string r2 = a + "XY";
//     bit::string r3 = "XY" + a;

//     cout << "string + string：" << r1 << endl;
//     cout << "string + 字符串：" << r2 << endl;
//     cout << "字符串 + string：" << r3 << endl;

//     cout << "原来的 a：" << a << endl;
//     cout << "原来的 b：" << b << endl;

//     cout << "连续相加：" << a + b + "!" << endl;

//     return 0;
// }

// #include "string.h"

// int main() {
//     bit::string a("abc");
//     bit::string b("abc");
//     bit::string c("abd");

//     cout << boolalpha;  // 把布尔值显示为 true、false

//     cout << "相等时：" << endl;
//     cout << "a == b: " << (a == b) << endl;
//     cout << "a != b: " << (a != b) << endl;
//     cout << "a <  b: " << (a < b) << endl;
//     cout << "a >  b: " << (a > b) << endl;
//     cout << "a <= b: " << (a <= b) << endl;
//     cout << "a >= b: " << (a >= b) << endl;

//     cout << "不相等时：" << endl;
//     cout << "a < c: " << (a < c) << endl;
//     cout << "c > a: " << (c > a) << endl;

//     return 0;
// }