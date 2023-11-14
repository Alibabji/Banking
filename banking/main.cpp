#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void PETC(); //Press Enter To Continue

int id, amount,order=0;
class Account
{
private:
	string name;
	int balance;
	int ID;
public:
	Account(int n) :balance(0), ID(n)
	{	
		cout << "이름: "; cin >> name;
		cout << "입금액: "; cin >> balance;
	}
	void showinfo()
	{
		cout << "계좌ID: " << ID << "\n이름: " << name << "\n잔액: " << balance << endl << endl;
	}
	void deposit(int value)
	{
		balance += value;
	}
	void withdrawal(int value)
	{
		if (balance >= value)
		{
			balance -= value;
			cout << "출금완료\n";
		}
		else
		{
			cout << "ERROR!! 출금액이 잔액보다 많습니다!!\n";
		}
	}
};

Account* acc[1000] = { NULL }; //creae 1000 account address
int acclist[1000];	//save account ID

void ShowAllInfo()
{
	for (int i = 0; order>i; i++)
	{
		acc[acclist[i]]->showinfo();
	}
}

int main(void)
{
	int num;
	while (true)
	{
		cout << "-----Menu-----\n1. 개좌계설\n2. 입금\n3. 출금\n4. 계좌번호 전체 출력\n5. 프로그램 종료\n선택: ";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "[계좌계설]\n계좌ID: ";
			cin >> id;
			acc[id] = new Account(id);
			acclist[order] = id; order++;
			break;
		case 2:
			cout << "[입  금]\n계좌ID: "; cin >> id;
			cout << "입금액: "; cin >> amount;
			if (acc[id] == NULL)
			{
				printf("!!존재하지 않는 계정입니다!!\n");
				break;
			}
			acc[id]->deposit(amount);
			printf("입금완료\n");
			break;
		case 3:
			cout << "[출  금]\n계좌ID: "; cin >> id;
			cout << "출금액: "; cin >> amount;
			acc[id]->withdrawal(amount);
			break;
		case 4:
			ShowAllInfo();
			break;
		case 5:
			return 0;
		}
		PETC();
		system("CLS");
	}
	return 0;
}

void PETC(void)
{
	cout << "\nPress Enter to continue.";
	cin.ignore();
	cin.get();
}