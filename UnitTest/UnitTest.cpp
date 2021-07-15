
#include <iostream>
#include "Account.cpp"

using namespace std;

int main()
{


	Account Tester1;
	SavingsAccount Tester2;
	Tester1.DisplayAccountBalance();
	cout << "******************Unit Testing DisplayAccountBalance ***********************************" << endl;

	Tester1.WithDraw();
	cout << "******************Unit Testing WithDraw***********************************" << endl;
	Tester1.Deposit();
	cout << "******************Unit Testing Deposit***********************************" << endl;
	Tester2.getMonthlyInterestRate();
	cout << "******************Unit Testing MonthlyInterestRate***********************************" << endl;
	Tester2.getMonthlyInterest();
	cout << "******************Unit Testing MonthlyInterest***********************************" << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}