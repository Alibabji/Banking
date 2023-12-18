#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void PETC(); //Press Enter To Continue

int id, amount,order=0;

class Account
{
private:
	string *name;
	int balance;
	int ID;
public:
	Account(int n) :balance(0), ID(n)
	{	
		
		cout << "이름: "; 
		name = new string;
		cin >> *name;
		cout << "입금액: "; 
		cin >> balance;
	}

	Account(const Account &copy):name(copy.name)
	{
		name = new string;
		*name = *copy.name;
	}

	void deposit(int value)
	{
		balance += value;
	}
	virtual void showInfo()const;
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

	~Account()
	{
		delete name;
	}
};

void Account::showInfo() const
{
	cout << "계좌ID: " << ID << "\n이름: " << *name << "\n잔액: " << balance << endl;
}

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
		cout << "이자율: " << interestRate<<"%\n\n";
	}
};

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
			creditRate= 7;
			break;
		case 2:
			creditRate= 4;
			break;
		default:
			creditRate= 2;
		}
	}
	void showInfo() const
	{
		Account::showInfo();
		cout << "이자율: " << interestRate << "%\n";
		printf("신용등급: %c\n\n", creditScore + 64);
	}
};

class AccountHandler
{
private:
	Account* accList[1000];
	int accNum;
	vector<int> accID;
public:
	AccountHandler() :accNum(0)
	{
		for (int i = 0; i < 1000; i++)
			accList[i] = NULL;
		accID = {};
	};
	
	void ShowMenu() const
	{
		cout << "-----Menu-----\n1. 개좌계설\n2. 입금\n3. 출금\n4. 계좌번호 전체 출력\n5. 프로그램 종료\n선택: ";
	}
	void AddAccount()
	{
		cout << "[계좌종류선택]\n1.보통예금계좌 2.신용신뢰계좌\n선택: ";
		int accType;
		cin >> accType;
		accType -= 1;
		if (accType == 1)
		{
			cout << "[신용신뢰계좌 개설]\n계좌 ID: ";
			cin >> id;
			accID.push_back(id);
			accList[accNum++] = new HighCreditAcc(id);
		}
		else
		{
			cout << "[보통예금계좌 개설]\n계좌 ID: ";
			cin >> id;
			accID.push_back(id);
			accList[accNum++] = new NormalAcc(id);
		}
	}

	void ShowAllInfo() const
	{
		for (int i = 0; i < accNum; i++)
			accList[i]->showInfo();
	}

	void Deposit()
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

	void Withdrawal()
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

	~AccountHandler()
	{
		for (int i = 0; i < accNum; i++)
			delete accList[i];
	}
};

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
		case 1:
			handler.AddAccount();
			break;
		case 2:
			handler.Deposit();
			break;
		case 3:
			handler.Withdrawal();
			break;
		case 4:
			handler.ShowAllInfo();
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