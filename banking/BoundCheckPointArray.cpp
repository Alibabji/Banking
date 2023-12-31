#include "BoundCheckPointArray.h"
#include <iostream>
using namespace std;

ACC_PTR& BoundCheckPointArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
ACC_PTR& BoundCheckPointArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
BoundCheckPointArray::BoundCheckPointArray(int len) : arrlen(len) { arr = new ACC_PTR[len]; }
int BoundCheckPointArray::GetArrLen() const { return arrlen; }
BoundCheckPointArray::~BoundCheckPointArray() { delete[]arr; }
