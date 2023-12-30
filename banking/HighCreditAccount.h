#pragma once
#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__
#include <string>
#include <iostream>
#include "Account.h"
#include "BankingCommonDecl.h"
using namespace std;

class HighCreditAcc :public Account
{
private:
	double interestRate;
	double creditRate;
	int creditScore;
public:
	HighCreditAcc(int n) :Account(n)
	{
		cout << "이자율: ";
		cin >> interestRate;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> creditScore;
		switch (creditScore)
		{
		case 1:
			creditRate = CREDIT_A;
			break;
		case 2:
			creditRate = CREDIT_B;
			break;
		default:
			creditRate = CREDIT_C;
		}
	}
	void showInfo() const
	{
		Account::showInfo();
		cout << "이자율: " << interestRate << "%\n";
		printf("신용등급: %c\n\n", creditScore + 64);
	}
};
#endif
