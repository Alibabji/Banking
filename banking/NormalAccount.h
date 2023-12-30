#pragma once
#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__
#include <string>
#include <iostream>
#include "Account.h"
using namespace std;

class NormalAcc :public Account
{
private:
	/*string* name;
	int balance;
	int ID;*/
	double interestRate;
public:
	NormalAcc(int n) :Account(n)
	{
		cout << "이자율: ";
		cin >> interestRate;
	}
	void showInfo() const
	{
		Account::showInfo();
		cout << "이자율: " << interestRate << "%\n\n";
	}
};
#endif
