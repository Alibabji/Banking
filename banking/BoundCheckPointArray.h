#pragma once
#ifndef __BOUND_CHECK_POINT_ARRAY_H__
#define __BOUND_CHECK_POINT_ARRAY_H__
#include "Account.h"
#include "BankingCommonDecl.h"
typedef Account * ACC_PTR;

class BoundCheckPointArray
{
private:
	ACC_PTR* arr;
	int arrlen;
	BoundCheckPointArray(const BoundCheckPointArray& arr) { }
	//BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }
public:
	BoundCheckPointArray(int len=MAX_ACC);
	ACC_PTR& operator[](int idx);
	ACC_PTR& operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckPointArray();
};
#endif
