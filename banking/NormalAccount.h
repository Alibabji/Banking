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
		while (true)
		{
			cout << "이자율: ";
			cin >> interestRate;
			try
			{
				if (interestRate < 0)
					throw interestRate;
				break;
			}
			catch (double asdf)
			{
				cout << "다시 선택하십시오!!\n";
			}
		}
	}
	void showInfo() const
	{
		Account::showInfo();
		cout << "이자율: " << interestRate << "%\n\n";
	}
};
#endif
