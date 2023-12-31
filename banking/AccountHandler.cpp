#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"
#include "BankingCommonDecl.h"
#include <iostream>
#include <vector>

AccountHandler::AccountHandler() :accNum(0), id(0)
{
	for (int i = 0; i < MAX_ACC; i++)
		accList[i] = NULL;
	accID = {};
};
void AccountHandler::ShowMenu() const
{
	cout << "-----Menu-----\n1. 개좌계설\n2. 입금\n3. 출금\n4. 계좌번호 전체 출력\n5. 프로그램 종료\n선택: ";
}
void AccountHandler::AddAccount()
{
	cout << "[계좌종류선택]\n1.보통예금계좌 2.신용신뢰계좌\n선택: ";
	int accType;
	cin >> accType;
	if (accType == HIGHCREDIT)
	{
		cout << "[신용신뢰계좌 개설]\n계좌 ID: ";
		cin >> id;
		accID.push_back(id);
		accList[accNum++] = new HighCreditAcc(id);
	}
	else if(accType == NORMAL)
	{
		cout << "[보통예금계좌 개설]\n계좌 ID: ";
		cin >> id;
		accID.push_back(id);
		accList[accNum++] = new NormalAcc(id);
	}
	else
	{
		cout << "INPUT VALUE INVALID!!" << endl;
	}
}
void  AccountHandler::ShowAllInfo() const
{
	for (int i = 0; i < accNum; i++)
		accList[i]->showInfo();
}

void  AccountHandler::Deposit()
{
	vector<int>::iterator it;
	cout << "[입  금]\n계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> amount;
	it = find(accID.begin(), accID.end(), id);
	if (it != accID.end())
		accList[it - accID.begin()]->deposit(amount);
	else
	{
		printf("!!존재하지 않는 계정입니다!!\n");
		return;
	}
	printf("입금완료\n");
}

void  AccountHandler::Withdrawal()
{
	vector<int>::iterator it;
	cout << "[출  금]\n계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> amount;
	it = find(accID.begin(), accID.end(), id);
	if (it != accID.end())
		accList[it - accID.begin()]->withdrawal(amount);
	else
	{
		printf("!!존재하지 않는 계정입니다!!\n");
		return;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accList[i];
}
