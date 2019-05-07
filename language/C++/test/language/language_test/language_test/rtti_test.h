#ifndef RTTI_TEST_H
#define RTTI_TEST_H

/*void visitVtbl(int **vtbl, int count)
{
	cout << vtbl << endl;
	cout << "\t[-1]: " << (long)vtbl[-1] << endl;

	typedef void(*FuncPtr)();
	for (int i = 0; vtbl[i] && i < count; ++i)
	{
		cout << "\t[" << i << "]: " << vtbl[i] << " -> ";
		FuncPtr func = (FuncPtr)vtbl[i];
		func();
	}
}*/

class Base
{
public:
	Base()
	{
		mBase1 = 101;
		mBase2 = 102;
	}
	virtual void func1()
	{
		cout << "Base::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "Base::func2()" << endl;
	}
public:
	int mBase1;
	int mBase2;
};

class Derived : public Base
{
public:
	Derived():Base()
	{
		mDerived1 = 1001;
		mDerived2 = 1002;
	}
	virtual void func2()
	{
		cout << "Derived::func2()" << endl;
	}
	virtual void func3()
	{
		cout << "Derived::func3()" << endl;
	}
public:
	int mDerived1;
	int mDerived2;
};

//void printf_object_info(int)

void rtti_main();

#endif //RTTI_TEST_H#pragma once
