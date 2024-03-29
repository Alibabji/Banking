#pragma once
#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__
#include <vector>
#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<ACC_PTR> accList;
	//Account* accList[1000];
	int accNum, id, amount;
	vector<int> accID;
public:
	AccountHandler();
	void ShowMenu() const;
	void AddAccount();
	void ShowAllInfo() const;
	void Deposit();
	void Withdrawal();
	~AccountHandler();
};
#endif
