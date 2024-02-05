#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(int n) :balance(0), ID(n)
{
	cout << "이름: ";
	name = new string;
	cin >> *name;
	while (true)
	{
		cout << "입금액: ";
		cin >> balance;
		try
		{
			if (balance < 0)
				throw 0;
			break;
		}
		catch (...)
		{
			cout << "0보다 큰 값을 입력하시오!!\n";
			continue;
		}
	}
}

Account::Account(const Account& copy) :name(copy.name)
{
	name = new string;
	*name = *copy.name;
}

void Account::deposit(int value)
{
	balance += value;
}

void Account::withdrawal(int value)
{
	try
	{
		if (balance <= value)
			throw 0;
		balance -= value;
		cout << "출금완료\n";
	}
	catch (...)
	{
		cout << "ERROR!! 출금액이 잔액보다 많습니다!!\n";
	}
}

Account::~Account()
{
	delete name;
}

void Account::showInfo() const
{
	cout << "계좌ID: " << ID << "\n이름: " << *name << "\n잔액: " << balance << endl;
}

Account& Account::operator=(const Account& ref)
{
	name = new string;
	*name = *ref.name;
	balance = ref.balance;
	ID = ref.ID;
	return *this;
}
