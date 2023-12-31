#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <string>
using namespace std;

class Account
{
private:
	string *name;
	int balance;
	int ID;
public:
	Account(int n);
	Account(const Account& copy);
	void deposit(int value);
	virtual void showInfo()const;
	void withdrawal(int value);
	Account& operator=(const Account& ref);
	~Account();
};

#endif
