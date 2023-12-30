#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "AccountHandler.h"
#include "BankingCommonDecl.h"
using namespace std;

void PETC(void)
{
	cout << "\nPress Enter to continue.";
	cin.ignore();
	cin.get();
}

int main(void)
{
	AccountHandler handler;
	int num;
	while (true)
	{
		handler.ShowMenu();
		cin >> num;
		switch (num)
		{
		case CREATE:
			handler.AddAccount();
			break;
		case DEPOSIT:
			handler.Deposit();
			break;
		case WITHDRAWAL:
			handler.Withdrawal();
			break;
		case SHOWINFO:
			handler.ShowAllInfo();
			break;
		case EXIT:
			return 0;
		}
		PETC();
		system("CLS");
	}
	return 0;
}
