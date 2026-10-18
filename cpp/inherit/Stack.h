#pragma once

template<class T>
T Add(const T& left, const T& right);  //如果只声明 再链接时Stac.cpp不知道实例化哪一个 就会失败 编译只检查语法

int Func(int x);

template<class T>
T Add(const T& left, const T& right) {
	return left + right;
}