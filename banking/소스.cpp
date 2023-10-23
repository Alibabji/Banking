#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void create()
{
	Bank 
	cout << "[계좌계설]" << endl<<"계좌ID: ";

}
void deposit()
{

}
void withdrawal()
{

}
void ShowAllInfo()
{

}
int main(void)
{
	cout << "-----Menu-----" << endl << "1. 개좌계설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌번호 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택: ";
	int num; cin >> num;
	switch (num)
	{
	case 1:
		create();
	case 2:
		deposit();
	case 3:
		withdrawal();
	case 4:
		ShowAllInfo();
	case 5:
		return 0;
	}

	return 0;
}