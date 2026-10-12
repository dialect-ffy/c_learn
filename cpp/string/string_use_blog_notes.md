# `std::string` 学习笔记：从 `string_use.cpp` 提炼用法、边界与易错点

> 本文依据同目录的 `string_use.cpp` 整理。原文件是学习演示代码，几乎全部被注释；其中既有正确示例，也有几处需要修正的结论。下面以标准库 `std::string` 的真实行为为准。

## 一、先建立三个核心认识

### 1. `std::string` 是字符序列，也是一个动态数组

可以把 `std::string` 理解成专门管理字符的动态数组：

- `size()` 表示当前实际保存的元素数。
- `capacity()` 表示不重新分配内存时最多能保存多少个元素。
- 底层字符连续存放，末尾还会维护一个 `\0`，以便和 C 接口协作。
- 下标从 `0` 开始，有效内容下标是 `[0, size())`。
- 很多区间接口采用左闭右开区间 `[first, last)`。

### 2. `size_type`、`size_t` 和 `npos`

字符串的长度、位置通常使用无符号类型 `std::string::size_type`。`std::string::npos` 是这个类型能够表示的最大值，用来表示“没有找到”或“直到结尾”。

```cpp
std::string::size_type pos = s.find("abc");
if (pos == std::string::npos) {
    // 没找到
}
```

易错点：

- 不要用 `pos < 0` 判断查找失败，无符号数不会小于零。
- 不建议把查找结果保存到 `int`，长字符串可能发生截断。
- 不要在确认成功前计算 `npos + 1`。无符号整数会回绕，结果可能变成 `0`，导致后续逻辑完全错误。

### 3. 下标、长度、容量是三个不同概念

假设字符串长度为 `5`：

- 内容下标为 `0、1、2、3、4`。
- `size()` 等于 `5`。
- `begin() + size()` 等于 `end()`，但 `end()` 不能解引用。
- `capacity()` 可能等于或大于 `5`，其具体增长策略由标准库实现决定。

---

## 二、编码：`std::string` 的长度不一定是“字数”

源文件开头讨论了 UTF-8、UTF-16、UTF-32，这里必须先纠正一个常见误区：`std::string` 本身不理解文字，它只保存 `char` 元素。

UTF-8 中通常有以下情况：

- ASCII 字符一般占 1 字节。
- 常用汉字通常占 3 字节。
- 部分增补平面字符通常占 4 字节。

因此：

```cpp
std::string s = "比特abcd01";
std::cout << s.size();
```

这里的 `size()` 返回 UTF-8 字节数，不是肉眼看到的字符数。两个常用汉字通常就是 6 字节。

源文件中的下面这种操作是危险的：

```cpp
char arr[] = "比特abcd01";
arr[2]++;
```

`arr[2]` 很可能只是第一个汉字的某个 UTF-8 编码字节。单独修改它会破坏编码，而不是把汉字变成“下一个汉字”。同理，直接对包含中文的 UTF-8 字符串执行按字节 `reverse`，也会把多字节字符拆散。

相关字符串类型：

- `std::string`：元素类型是 `char`，常用于保存 UTF-8，但编码由程序约定。
- `std::wstring`：元素类型是 `wchar_t`；Windows 上通常是 16 位，Linux/macOS 上通常是 32 位，跨平台宽度不一致。
- `std::u16string`：元素类型是 `char16_t`，适合保存 UTF-16 码元。
- `std::u32string`：元素类型是 `char32_t`，适合保存 UTF-32 码元。
- `std::u8string`：C++20 中元素类型是 `char8_t`，用于 UTF-8 码元。

即使换成 UTF-16 或 UTF-32，“元素数”也不一定等于用户看到的字形数，因为还存在代理对、组合字符和 emoji 序列。写博客时最好使用“字节数”“码元数”“Unicode 码点数”“用户感知字符数”这些准确说法。

---

## 三、构造、复制与赋值

### 1. 默认构造

```cpp
std::string s1;
```

得到空字符串：

- `s1.empty()` 为 `true`。
- `s1.size()` 为 `0`。
- `s1.c_str()` 指向一个只包含终止符 `\0` 的有效 C 字符串。

### 2. 从 C 字符串构造

```cpp
std::string s2("hello world");
std::string s3 = "hello world";
```

这两种写法都会复制内容。传入的指针必须有效，并且必须能找到结尾的 `\0`；不能把空指针 `nullptr` 当作 C 字符串传入。

### 3. 拷贝构造和拷贝赋值不是一回事

```cpp
std::string a("hello");
std::string b(a);      // 拷贝构造
std::string c = a;     // 也是拷贝构造，不是赋值

std::string d;
d = a;                 // 拷贝赋值
```

判断方法：对象正在创建时叫构造；对象已经存在，再用 `=` 改内容才叫赋值。

### 4. 从另一个 `string` 截取构造

源文件示例：

```cpp
std::string s1("hello worldxxxxxxxxxxxxx");
std::string s2(s1, 6, 3); // "wor"
std::string s3(s1, 6);    // 从下标 6 一直到末尾
```

接口含义：

```cpp
std::string(const std::string& other,
            size_type pos,
            size_type count = npos);
```

边界：

- `pos < size()`：从指定下标开始。
- `pos == size()`：得到空字符串。
- `pos > size()`：抛出 `std::out_of_range`。
- `count` 超过剩余长度：自动截到末尾，不会越界。
- `count == 0`：得到空字符串。

### 5. 构造多个相同字符

```cpp
std::string stars(10, '*'); // "**********"
```

参数顺序是“数量在前，字符在后”。这和 `std::vector` 的填充构造风格一致。

### 6. 从字符指针复制指定数量

```cpp
std::string s("hello world", 6); // "hello "
```

第二个参数是复制的字符数量，所以空格也算一个字符。这个重载不依赖中途出现的 `\0`，可以保存内嵌空字符；但调用者必须保证至少有指定数量的可读元素，否则会越界读取。

---

## 四、元素访问：`operator[]`、`at()` 与边界

### 1. `operator[]`

```cpp
std::string s("12345");
s[0]++;       // '1' 变成 '2'
s[2] = '4';
```

`operator[]` 速度直接，但不做可靠的运行时边界检查。源文件注释写“字符串越界会报错”，这不是标准保证：

- 对内容的正常访问范围应始终看作 `[0, size())`。
- `pos > size()` 是未定义行为。
- C++11 以后读取 `s[s.size()]` 可以看到末尾的空字符，但不能把它当作普通内容位置，更不能把它改成非 `\0` 值。
- Debug 标准库可能触发断言，Release 模式则可能静默地产生错误，所以不能依赖“会报错”。

### 2. `at()`

需要明确检查边界时使用：

```cpp
try {
    char ch = s.at(30);
} catch (const std::out_of_range&) {
    // 下标非法
}
```

`at()` 的有效范围仍是 `[0, size())`，越界会抛出 `std::out_of_range`。

### 3. `front()` 和 `back()`

```cpp
char first = s.front();
char last  = s.back();
```

它们分别访问第一个和最后一个字符。空字符串没有首尾元素，调用前必须保证 `!s.empty()`。

---

## 五、`size()`、`length()`、`capacity()`、`clear()`

### 1. `size()` 与 `length()`

二者对 `std::string` 完全等价，都返回当前元素数量：

```cpp
assert(s.size() == s.length());
```

通常容器风格代码使用 `size()`；强调文本长度时也有人使用 `length()`。

### 2. `capacity()`

`capacity()` 是当前已分配存储空间可容纳的字符数，不包括为 C 字符串维护的终止符。必须记住：

- 标准保证 `capacity() >= size()`。
- 具体初始容量和扩容倍数不属于标准保证。
- 小字符串优化（SSO）可能让短字符串直接保存在对象内部，不进行堆分配。
- 不能根据某台机器输出的容量变化推断所有编译器都一样。

### 3. `clear()`

```cpp
s.clear();
```

它把字符串变为空串，使 `size()` 变为 `0`。它的目的不是释放内存，通常不会降低 `capacity()`。

如果希望请求收缩容量，可以调用：

```cpp
s.shrink_to_fit();
```

但 `shrink_to_fit()` 只是非强制请求，标准库可以选择不收缩。

### 4. `max_size()`

`max_size()` 是实现和分配器给出的理论长度上限，不代表机器当前真的有这么多内存，也不代表一次分配一定成功。

---

## 六、遍历：下标、迭代器、范围 `for`

### 1. 下标遍历

```cpp
for (std::size_t i = 0; i < s.size(); ++i) {
    std::cout << s[i];
}
```

循环条件必须是 `< s.size()`，不能写成 `<= s.size()`。

### 2. 正向迭代器

```cpp
for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
    *it = static_cast<char>(*it + 1); // 非 const 迭代器可以修改元素
}
```

`begin()` 指向第一个元素，`end()` 指向最后一个元素之后的位置。空字符串满足 `begin() == end()`。

### 3. 常量迭代器

```cpp
void print(const std::string& s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it;
        // *it = 'x'; // 错误：只能读，不能改
    }
}
```

也可以明确使用 `s.cbegin()` 和 `s.cend()`。

### 4. 反向迭代器

```cpp
for (auto it = s.rbegin(); it != s.rend(); ++it) {
    std::cout << *it;
}
```

`rbegin()` 从最后一个字符开始，`rend()` 是第一个字符之前的反向边界。它们仍然构成左闭右开区间。

### 5. 范围 `for` 中的复制与引用

```cpp
for (auto ch : s) {       // ch 是副本，修改 ch 不影响 s
    ch++;
}

for (auto& ch : s) {      // ch 是引用，可以修改 s
    ch++;
}

for (const auto& ch : s) {// 只读引用，不复制
    std::cout << ch;
}
```

对 `char` 来说复制成本很小，但理解 `auto`、`auto&`、`const auto&` 的区别对其他容器同样重要。

### 6. 迭代器失效

当追加、插入等操作引发重新分配时，原有指针、引用和迭代器都会失效。`insert`、`erase` 还会让操作位置及其后方的迭代器失效。安全做法是：修改后重新获取迭代器，不要保存 `c_str()`、`data()` 或元素地址再继续修改字符串。

### 7. 源文件 `test5` 若整体取消注释会编译失败

该段演示思路有价值，但当前代码还存在：

- 在声明 `m` 之前就使用了 `m.begin()`。
- `m.begin` 少了调用所需的圆括号，应为 `m.begin()`。
- 同一作用域重复声明了多个名为 `mit` 的变量。
- `auto array[3] = ...` 不合法；数组元素类型不能这样写成待逐项推导的 `auto`。

---

## 七、`std::reverse`

```cpp
std::string s("12345");
std::reverse(s.begin(), s.end()); // "54321"
```

`std::reverse` 接收左闭右开区间 `[first, last)`，要求迭代器至少是双向迭代器，因此也可以用于 `std::list`。

易错点：

- 它是 `<algorithm>` 中的算法，不是 `string` 成员函数。
- `std::reverse(s.begin(), s.end() - 1)` 不会处理最后一个字符，因为右边界不包含在范围内。
- 对 UTF-8 中文直接反转会按字节倒序，破坏编码；反转 Unicode 文本需要先按码点或用户感知字符正确切分。

---

## 八、追加：`push_back`、`append`、`operator+=`

### 1. `push_back`

```cpp
s.push_back('x');
```

一次只能追加一个 `char`，参数使用单引号。空字符串也可以直接 `push_back`。

### 2. `append`

常见重载：

```cpp
s.append("world");                 // 追加 C 字符串
s.append(5, '!');                  // 追加 5 个 '!'
s.append(other);                   // 追加另一个 string
s.append(other, 2, 3);             // 追加 other 从下标 2 开始的 3 个字符
s.append(first, last);             // 追加迭代器区间 [first, last)
```

源文件先把 `s1` 反转为 `"54321"`，再写：

```cpp
s2.append(++s1.begin(), --s1.end());
```

实际追加的是 `"432"`，因为右边界不包含在区间中。更清楚的写法是：

```cpp
s2.append(std::next(s1.begin()), std::prev(s1.end()));
```

不过只有当字符串至少含有两个元素时，递增 `begin()` 和递减 `end()` 才有意义。使用 `std::next`、`std::prev` 时应包含 `<iterator>`。

### 3. `operator+=`

```cpp
s += 'x';        // 单个字符
s += "world";    // C 字符串
s += other;      // std::string
```

源文件中的 `s3 += '';` 是编译错误，因为 C++ 没有“空字符字面量”。

- 空字符串应写成 `""`。
- 空字符是 `\0`，写成 `'\0'`，但它是真实存在于字符串中的一个字符，会增加 `size()`。

`s += s` 是合法的自追加，结果是原内容重复两遍。

### 4. 性能

连续追加通常具有均摊常数复杂度，但多次扩容仍会搬移数据。如果能预估最终长度，可以先 `reserve()`：

```cpp
std::string result;
result.reserve(expected_size);
```

---

## 九、插入：`insert`

源文件覆盖了三类常用重载：

```cpp
std::string s("12345");

s.insert(0, "xxxx");       // 在下标 0 前插入字符串
s.insert(0, 1, 'y');        // 在下标 0 前插入 1 个 'y'
s.insert(s.begin(), 'y');   // 在迭代器指向的位置前插入字符
s.insert(s.size(), "end"); // 在末尾追加
```

位置规则：

- 下标版本允许 `pos` 落在 `[0, size()]`。
- `pos == 0` 表示头插。
- `pos == size()` 表示尾插。
- `pos > size()` 会抛出 `std::out_of_range`。
- 迭代器版本允许位置从 `begin()` 到 `end()`，传入不属于该字符串的迭代器是错误的。

返回值需要看具体重载：按下标插入的重载通常返回 `string&`，单元素迭代器重载返回指向新元素的迭代器。

复杂度与风险：

- 中间或头部插入需要后移已有字符，通常是线性复杂度。
- 空间不够时还要重新分配，原有迭代器、引用和指针会失效。
- 多次头插可能退化为平方级总开销，适合先构造结果或换更合适的数据结构。

源文件前几步的结果依次为：

```text
12345
xxxx12345
yxxxx12345
yyxxxx12345
```

---

## 十、删除：`erase`

最常见的下标版本：

```cpp
s.erase(pos, count);
```

规则：

- 从 `pos` 开始删除最多 `count` 个字符。
- `pos == size()` 时不删除任何内容。
- `pos > size()` 时抛出 `std::out_of_range`。
- `count` 超过剩余长度时，只删除到末尾，不会越界。
- 省略 `count` 时默认是 `npos`，即从 `pos` 删除到末尾。
- `s.erase()` 使用全部默认参数，会清空字符串。

源文件中的连续操作必须结合“字符串已经发生变化”来理解：

```cpp
std::string s("123456789");
s.erase(0, 1); // "23456789"
s.erase(4, 2); // 此时删除的是 '6'、'7'，得到 "234589"
s.erase(4);    // 此时从新下标 4 删除到末尾，得到 "2345"
```

还有迭代器版本：

```cpp
it = s.erase(it);          // 删除一个元素，返回下一个有效位置
it = s.erase(first, last); // 删除 [first, last)，返回删除区间后的下一个位置
```

循环中删除时，应接住返回的迭代器，而不是无条件再执行一次 `++it`。

`erase` 改变 `size()`，通常不会主动缩小 `capacity()`。

---

## 十一、替换：`replace`

```cpp
std::string s("123456789");
s.replace(3, 3, "abc"); // "123abc789"
s.replace(3, 5, "xxx"); // "123xxx9"
```

接口含义：从 `pos` 开始，删除最多 `count` 个原字符，再插入新内容。

边界与易错点：

- `pos > size()` 抛出 `std::out_of_range`。
- `count` 超过剩余长度时按“到末尾”为止处理。
- 新旧长度相等时字符串长度不变。
- 用短串换长串可能扩容并后移数据；用长串换短串会前移数据。
- `replace` 一次只替换指定位置，不会自动“全局查找并全部替换”。

一个常用的全部替换模板：

```cpp
void replace_all(std::string& s,
                 const std::string& from,
                 const std::string& to) {
    if (from.empty()) {
        return; // 防止永远匹配空串
    }

    std::size_t pos = 0;
    while ((pos = s.find(from, pos)) != std::string::npos) {
        s.replace(pos, from.size(), to);
        pos += to.size(); // 从刚插入内容之后继续
    }
}
```

如果替换次数很多，而且替换后长度经常变化，反复 `find + replace` 可能多次搬移数据。一次遍历并构造新字符串往往更容易获得稳定性能。

### 源文件中的 `'%%'` 错误

```cpp
s5 += '%%'; // 错误思路
```

单引号表示字符字面量，`'%%'` 是多字符字面量，其数值和转换结果不可移植，绝不表示两个百分号。应写成：

```cpp
s5 += "%%";
```

源文件注释说这种情况“不可以 `replace`”也不准确：语义上当然可以，只是循环替换时可能发生多次搬移。构造新字符串是一种性能更可控的选择。

---

## 十二、交换：`swap`

```cpp
s1.swap(s2);
std::swap(s1, s2);
```

两种写法都可以。普通 `std::allocator` 场景下，交换主要是交换内部状态，成本很低，不会逐字符进行普通意义上的深拷贝。

在泛型代码中常见下面的写法，它允许类型提供自己的高效 `swap`：

```cpp
using std::swap;
swap(a, b);
```

交换之后，变量 `a` 和 `b` 各自拥有对方原来的内容、长度和容量。源文件中“C++11 前只有成员 `swap` 更高效”的说法过于绝对，不适合直接写进博客。

---

## 十三、`reserve()` 与 `resize()`：最容易混淆的一组

### 1. `reserve()` 只改容量，不创建字符

```cpp
std::string s;
s.reserve(100);
```

此时通常有：

```cpp
s.size() == 0;
s.capacity() >= 100;
```

因此不能因为预留了 100 个位置，就直接访问 `s[50]`。有效元素仍然一个都没有。

当请求容量不大于当前容量时，现代标准库中通常不会收缩；要表达收缩请求使用 `shrink_to_fit()`，但它也不保证一定执行。

### 2. `resize()` 改变实际长度

```cpp
s.resize(100);      // 扩大：新增字符进行值初始化，即 '\0'
s.resize(150, 'x'); // 扩大：新增加的 50 个字符是 'x'
s.resize(10);       // 缩小：只保留前 10 个字符
```

注意：`'\0'` 是字符串中的真实元素，会计入 `size()`。`std::cout << s` 会按字符串长度输出，只是空字符通常没有可见效果；`strlen(s.c_str())` 则会在第一个 `\0` 处停止，可能远小于 `s.size()`。

### 3. 源文件 `test9` 的实际结果

```cpp
std::string s2;
s2.resize(100);      // 现在有 100 个 '\0'
s2.resize(100, 'x'); // 长度没有变化，所以什么也不会填
s2.resize(10);       // 保留前 10 个 '\0'
s2.resize(50, 'y');  // 后面新增 40 个 'y'
```

如果想演示 `resize(count, ch)` 的填充效果，应在当前长度小于 `count` 时直接调用，或者使用一个新的空字符串。

### 4. 扩容测试的注意点

源文件循环打印每次容量变化，这可以观察当前实现，但不能据此总结固定扩容倍数。更严谨的性能测试还应注意：

- 包含 `<ctime>` 后使用 `std::clock_t` 和 `CLOCKS_PER_SEC`，或者使用 `<chrono>` 的 `steady_clock`。
- 循环内频繁 `cout` 的成本可能远高于字符串扩容本身，会污染结果。
- 应使用 Release 优化构建，多次运行并比较统计结果。
- 预先知道最终长度时，`reserve(n)` 能减少重分配，但不应盲目预留远超需要的空间。

---

## 十四、查找：`find`、`rfind` 与查找家族

### 1. `find`：从左向右找第一次出现

常见形式：

```cpp
s.find(ch, pos);     // 查找一个字符
s.find(str, pos);    // 查找一个子串
```

`pos` 是开始搜索的下标，默认值为 `0`。源文件测试可得到：

```cpp
std::string s("abcabc");

s.find('b');       // 1
s.find('b', 2);    // 4
s.find("bc");      // 1
s.find("bc", 2);   // 4
s.find('X');       // npos
s.find('a', s.size()); // npos
```

边界：

- 没找到返回 `std::string::npos`，不会抛出异常。
- 搜索非空内容时，`pos == size()` 返回 `npos`。
- `pos > size()` 也返回 `npos`，`find` 不会像 `substr` 那样因这个位置抛出异常。
- `s.find("", pos)` 在 `pos <= size()` 时返回 `pos`；空模式串在每个合法边界都可以匹配。

### 2. `rfind`：从右向左找最后一次出现

`rfind` 没有出现在当前 `string_use.cpp` 的实际示例中，但它和 `find` 应放在一起掌握：

```cpp
s.rfind(ch, pos);
s.rfind(str, pos);
```

默认 `pos == npos`，表示考虑整个字符串。这里的 `pos` 限制的是“匹配起点不能位于它右侧”，不应简单理解成和 `find` 完全相同的起始位置。

```cpp
std::string s("abcabc");

s.rfind('a');       // 3
s.rfind("bc");      // 4
s.rfind("bc", 3);   // 1，起点为 4 的匹配被排除
s.rfind('a', 2);    // 0
```

边界：

- `pos` 大于字符串长度时，效果类似从最右端开始，不会抛异常。
- 找不到仍返回 `npos`。
- `s.rfind("", pos)` 返回 `min(pos, s.size())`。

典型用途是找最后一个扩展名分隔符：

```cpp
std::size_t dot = filename.rfind('.');
if (dot != std::string::npos) {
    std::string ext = filename.substr(dot + 1);
}
```

真实路径还要考虑目录名中的点、隐藏文件、末尾点以及多后缀，不能只靠这一行覆盖所有规则。

### 3. `find_first_of` 不是查找子串

查找家族还包括：

```cpp
s.find_first_of("aeiou");     // 找第一个属于字符集合的字符
s.find_last_of("/\\");        // 找最后一个 '/' 或 '\\'
s.find_first_not_of(" \t\r\n"); // 找第一个非空白字符
s.find_last_not_of(" \t\r\n");  // 找最后一个非空白字符
```

`find_first_of("abc")` 的含义是查找 `'a'`、`'b'`、`'c'` 中任意一个，不是查找连续子串 `"abc"`。连续子串要用 `find("abc")`。

---

## 十五、子串：`substr`

```cpp
std::string sub = s.substr(pos, count);
```

规则：

- 返回一个独立的新字符串，修改 `sub` 不会影响原字符串。
- `pos == size()` 返回空字符串。
- `pos > size()` 抛出 `std::out_of_range`。
- `count` 超出剩余长度时自动截到末尾。
- 省略 `count`，或者传入 `npos`，表示一直取到末尾。

源文件测试：

```cpp
std::string s("abcdef");
s.substr(2, 3);       // "cde"
s.substr(3);          // "def"
s.substr(4, 100);     // "ef"
s.substr(s.size());   // ""
```

`substr` 会复制结果。只需要只读观察原字符串的一部分、且项目使用 C++17 时，可以了解 `std::string_view`，但必须保证被观察的原字符串仍然存在且相关内存没有失效。

---

## 十六、URL 拆分示例的隐含边界

源文件的思路是：

1. 找到 `:`，得到协议。
2. 跳过 `://`。
3. 找到后面的 `/`，得到域名和路径。

原代码没有检查 `find` 是否成功。典型风险包括：

- 没有协议分隔符时，对 `npos` 做加法会发生无符号回绕。
- 没有路径 `/` 时，`i2 == npos`；`i2 + 1` 会回绕成 `0`，从而错误地把完整 URL 当成路径。
- 输入不一定包含标准的 `://`。
- 查询参数、片段、端口、IPv6 地址、用户信息和百分号编码都有额外规则。

用于学习 `find + substr` 的更安全版本：

```cpp
bool split_url(const std::string& url,
               std::string& protocol,
               std::string& domain,
               std::string& uri) {
    const std::string sep = "://";
    const std::size_t scheme_end = url.find(sep);
    if (scheme_end == std::string::npos) {
        return false;
    }

    const std::size_t domain_begin = scheme_end + sep.size();
    const std::size_t path_begin = url.find('/', domain_begin);

    protocol = url.substr(0, scheme_end);
    if (path_begin == std::string::npos) {
        domain = url.substr(domain_begin);
        uri.clear();
    } else {
        domain = url.substr(domain_begin, path_begin - domain_begin);
        uri = url.substr(path_begin + 1);
    }
    return !protocol.empty() && !domain.empty();
}
```

这个版本仍只是教学用拆分器，不是完整的 URL 标准解析器；生产代码应使用成熟 URL 库。

---

## 十七、`c_str()`、`data()` 与 C 接口

### 1. `c_str()`

```cpp
const char* p = filename.c_str();
```

它返回以 `\0` 结尾的字符序列，可以传给 `fopen` 等 C 接口。

易错点：

- 不要通过 `c_str()` 返回的指针修改内容。
- 字符串执行可能引发重分配的非 `const` 操作后，之前保存的指针可能失效。
- 指针不能比原字符串活得更久。
- 如果字符串内部含有 `\0`，C API 通常只看到第一个 `\0` 之前的部分。

C++17 起，非 `const string` 的 `data()` 可返回可写连续缓冲区，但只能在现有 `[0, size())` 元素范围内按规则修改，不能借此越过长度写入，也不能破坏末尾终止符。

### 2. 源文件 `fopen` 示例的问题

```cpp
FILE* fout = fopen(filename.c_str(), "r");
```

这种转换思路正确，但还要注意：

- 文件名是相对路径时，相对于程序的“当前工作目录”，不一定是源码所在目录。
- 成功打开后应调用 `fclose(fout)`。
- 应显式包含 `<cstdio>`。
- Windows 中 `_CRT_SECURE_NO_WARNINGS` 必须拼写正确，并在相关头文件之前定义；源文件写成了 `_CRT_SECURE_NO_WARINGS`，且放在头文件之后，因此不起作用。

原文件注释中的读取循环也有经典错误：

```cpp
char ch = fgetc(fout); // 不严谨
```

`fgetc` 返回 `int`，因为它既要表示所有 `unsigned char` 值，又要表示额外的 `EOF`。正确写法：

```cpp
int ch = 0;
while ((ch = std::fgetc(fout)) != EOF) {
    std::cout.put(static_cast<char>(ch));
}
std::fclose(fout);
```

在纯 C++ 代码中，也可以优先考虑 `std::ifstream`。

---

## 十八、比较运算与拼接运算

### 1. 比较是字典序，不是比较长度

```cpp
ststd::string a("abc");
d::string b("abd");

a < b;  // true，因为前两个字符相同，'c' < 'd'
```

规则是从左到右找第一个不同元素并比较；如果一个字符串是另一个的前缀，则较短者更小。

```cpp
"ab" < "aba" // 概念上较短前缀更小，但这两个字面量不能直接这样比较内容
```

上面如果两边都只是 `const char*`，运算可能变成指针比较而不是字符串内容比较。应保证至少一边是 `std::string`：

```cpp
std::string("ab") < "aba"; // 内容比较
```

同理，源文件中的 `p1 < s2` 能进行内容比较，是因为另一边 `s2` 是 `std::string`，匹配了标准库重载。

UTF-8 中文字符串的默认比较按编码单元字典序进行，不等于拼音顺序、语言地区排序或人类字典规则。

### 2. `operator+`

```cpp
std::string s1("hello");
const char* p = " world";

s1 + p;
p + s1;
s1 + p + "!";
```

这些都能工作，因为表达式中至少有一边是 `std::string`。两个 C 字符串字面量不能直接相加：

```cpp
// "hello" + "world"; // 编译错误
std::string("hello") + "world"; // 正确
```

大量连续 `+` 可能产生临时对象。循环拼接时通常使用 `reserve` 配合 `append` 或 `+=` 更清楚。

---

## 十九、输入：`operator>>` 与 `getline`

### 1. `operator>>`

```cpp
std::string s;
std::cin >> s;
```

默认行为：跳过开头空白，然后读取一个单词，遇到空格、制表符或换行等空白停止。因此输入 `hello world`，第一次只得到 `hello`。

标准库的字符串提取会把新内容写入字符串，不是简单接在旧内容之后。

### 2. `std::getline`

```cpp
std::getline(std::cin, s);      // 读到换行，结果中不包含换行符
std::getline(std::cin, s, '#'); // 读到 '#'，结果中不包含 '#'
```

### 3. `>>` 与 `getline` 混用

```cpp
int age = 0;
std::cin >> age;
std::getline(std::cin, s); // 往往立即读走上一行留下的 '\n'
```

常见处理方式：

```cpp
#include <limits>

std::cin >> age;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::getline(std::cin, s);
```

如果使用 `std::getline(std::cin >> std::ws, s)`，会吃掉所有前导空白；这也意味着无法保留用户有意输入的行首空格，需要根据需求选择。

---

## 二十、数字与字符串转换：`to_string`、`stoi`

### 1. `to_string`

```cpp
int value = 328148;
std::string text = std::to_string(value); // "328148"
```

还有适用于其他整数和浮点类型的重载。浮点格式由该接口的规则决定；需要精确控制宽度、精度和格式时可使用流、`std::format` 或 `to_chars` 等工具。

### 2. `stoi`

接口：

```cpp
int stoi(const std::string& str,
         std::size_t* idx = nullptr,
         int base = 10);
```

源文件示例：

```cpp
std::string str = "123abc21";
std::size_t used = 0;
int value = std::stoi(str, &used);

// value == 123
// used == 3
// str.substr(used) == "abc21"
```

规则与易错点：

- 会跳过允许的前导空白，并接受正负号。
- 从可转换部分开始解析，在第一个不符合当前进制的字符处停止。
- `idx` 得到“成功解析结束位置”，不是剩余字符数。
- 完全没有可转换内容时抛出 `std::invalid_argument`。
- 结果超出 `int` 范围时抛出 `std::out_of_range`。
- 如果业务要求整个字符串必须都是数字，还应检查 `used == str.size()`。
- `base` 通常可取 `2` 到 `36`；取 `0` 时会根据前缀自动判断常见进制。

示例：

```cpp
std::stoi("1010", nullptr, 2); // 10
std::stoi("0xA", nullptr, 0);  // 10
std::stoi("0xFF", nullptr, 0); // 255
```

还有 `stol`、`stoll`、`stoul`、`stoull`、`stof`、`stod` 等相关接口。高性能、无异常解析可以了解 C++17 的 `std::from_chars`。

---

## 二十一、原文件中适合在写博客前修正的清单

1. `_CRT_SECURE_NO_WARINGS` 拼错，应为 `_CRT_SECURE_NO_WARNINGS`，而且要放在相关头文件之前。
2. UTF-16 的常用汉字通常占一个 16 位码元，即 2 字节，不是统一 4 字节；增补字符才需要代理对的 4 字节。
3. `arr2[2]++` 修改的是 UTF-8 字节，会破坏中文编码。
4. `test4()` 缺少返回类型；现代 C++ 中应写成 `void test4()`。
5. `operator[]` 越界不保证报错；需要检查时用 `at()`。
6. `test5` 中 `m` 先使用后声明、`m.begin` 少括号、`mit` 重复定义，整体取消注释不能编译。
7. `s3 += '';` 是非法的空字符字面量，应根据意图使用 `""` 或 `'\0'`。
8. `s5 += '%%';` 是多字符字面量，不表示两个 `%`，应写 `s5 += "%%";`。
9. `resize(100)` 后紧接 `resize(100, 'x')` 不会填入 `x`，因为长度没有增大。
10. URL 拆分必须先检查每次 `find` 是否返回 `npos`。
11. `fgetc` 的返回值必须先保存在 `int` 中，且文件使用结束后要 `fclose`。
12. 扩容实验中的循环输出会严重干扰计时，容量增长规律也不是跨实现保证。
13. 对 UTF-8 文本直接使用字节下标或 `std::reverse` 不能正确处理中文字符。
14. 当前文件几乎所有内容都在注释中；学习时应每次只启用一个测试，并保证只有一个 `main()`。
15. 当前文件没有 `rfind` 实例；本文已补充其语义、边界和例子。

---

## 二十二、适合写成博客的文章结构

可以按下面顺序用自己的语言展开：

1. `std::string` 的数据模型：连续字符、`size`、`capacity`、`npos`。
2. 构造、拷贝、赋值及各重载的参数含义。
3. 元素访问和越界：`[]` 与 `at()`。
4. 三种遍历方式、`auto&`、常量迭代器和迭代器失效。
5. 追加操作：`push_back`、`append`、`+=`。
6. 修改操作：`insert`、`erase`、`replace`、`swap`。
7. 内存管理：`reserve` 与 `resize` 的根本区别。
8. 查询与切片：`find`、`rfind`、查找家族、`substr`。
9. C/C++ 接口衔接：`c_str`、文件读取、指针有效期。
10. 比较、拼接、整行输入与数字转换。
11. UTF-8 下“字节”和“字符”的区别。
12. 用 URL 拆分或全文替换做一个综合案例。

写每个接口时，可以固定采用四段式：

1. **它解决什么问题。**
2. **最常用的函数形式和参数含义。**
3. **一个能看出结果的最小示例。**
4. **边界、异常、迭代器失效和性能注意事项。**

这样写出来不会只是 API 罗列，而是一份真正能帮助排错和复习的 `std::string` 使用指南。
