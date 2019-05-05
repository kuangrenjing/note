// RTTI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include "iostream"   
using namespace std;


class A{
	public:virtual void foo()
	{
		cout << "A:foo()\n";
	}

	void pp()
	{
		cout << "A:pp()\n";
	}
};
class B :public A
{
public:
	void foo()
	{
		cout << "B:foo()\n";
	}
	void pp()
	{
		cout << "B:pp()\n";
	}
	void fun()
	{
		cout << "function in B \n";
	}


};
void main()
{
	B b;
	A *pa = &b;
	pa->foo();//由于存在多态，所以根据指向的类型调用方法，否则根据指针类型调用方法   
	pa->pp();//不存在多态，根据指针类型调用   
	//pa->fun();//出错，无法调用   
	dynamic_cast<B*>(pa)->pp();//运行时动态类型转换，可以指向B的pp（）   
	dynamic_cast<B*>(pa)->fun();//运行时动态类型转换，可以指向B的fun（）   
	dynamic_cast<B*>(pa)->foo();//运行时动态类型转换，可以指向B的foo（）   
}
