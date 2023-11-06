#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int id, amount,order=0;
struct acc
{
	string name;
	int balance;
};
acc num[1000];
int accnum[1000];

void create()
{
	cout << "[계좌계설]\n계좌ID: ";
	cin >> id;
	cout << "이름: "; cin >> num[id].name;
	cout << "입금액: "; cin >> num[id].balance;
	accnum[order] = id;
	order++;
}

void deposit()
{
	cout << "[입  금]\n계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> amount;
	num[id].balance += amount;
	printf("입금완료\n");
}

//num=int(intput("input a number: "))

void withdrawal()
{
	cout << "[출  금]\n계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> amount;
	if (num[id].balance >= amount)
	{
		num[id].balance -= amount;
		cout << "출금완료\n";
	}
	else
	{
		cout << "ERROR!! 출금액이 잔액보다 많습니다!!\n";
	}
}

void ShowAllInfo()
{
	for (int j = 0; order>j; j++)
	{
		cout << "계좌ID: " << accnum[j] << "\n이름: " << num[accnum[j]].name << "\n잔액: " << num[accnum[j]].balance << endl<<endl;
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
			create();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdrawal();
			break;
		case 4:
			ShowAllInfo();
			break;
		case 5:
			return 0;
		}
		printf("\n");
	}
	return 0;
}
