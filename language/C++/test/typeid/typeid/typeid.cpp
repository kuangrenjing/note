// typeid.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

class X
{
public:
	X()
	{
		mX = 101;
	}
	virtual void vfunc()
	{
		cout << "X::vfunc()" << endl;
	}
private:
	int mX;
};

class XX : public X
{
public:
	XX():X()
	{
		mXX = 1001;
	}
	virtual void vfunc()
	{
		cout << "XX::vfunc()" << endl;
	}
private:
	int mXX;
};

class Y
{
public:
	Y()
	{
		mY = 101;
	}
	
private:
	int mY;
};

int main()
{
	int n = 0;
	XX xx;
	Y y;
	Y *py = &y;

	// int和XX都是类型名
	cout << typeid(int).name() << endl;
	cout << typeid(XX).name() << endl;
	// n为基本变量
	cout << typeid(n).name() << endl;
	// xx所属的类虽然存在virtual，但是xx为一个具体的对象
	cout << typeid(xx).name() << endl;
	// py为一个指针，属于基本类型
	cout << typeid(py).name() << endl;
	// py指向的Y的对象，但是类Y不存在virtual函数
	cout << typeid(*py).name() << endl;
	return 0;
}
