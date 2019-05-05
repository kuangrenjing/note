#include "pch.h"
#include <iostream>
using namespace std;


#include "rtti_test.h"




void rtti_main()
{
	Derived d;
	//Derived* pd = &
	cout << "d's addr is " << &d << endl;
	cout << "d.mBase1's addr is " << &d.mBase1 << endl;
	//char *p = (char*)&d;
	//visitVtbl((int**)*(int**)p, 3);
	//p += sizeof(int**);

	//cout << *(int*)p << endl;
	//p += sizeof(int);

	//cout << *(int*)p << endl;
	//p += sizeof(int);

	//cout << *(int*)p << endl;
	//p += sizeof(int);

	//cout << *(int*)p << endl;

	return;
}