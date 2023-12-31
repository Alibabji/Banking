#pragma once
#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__
#include <vector>
#include "Account.h"
#include "BoundCheckPointArray.h"

class AccountHandler
{
private:
	BoundCheckPointArray accList;
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
