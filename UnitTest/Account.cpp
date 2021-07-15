#include <iostream>
using namespace std;

class Account{
protected:
	int id = 0;
	double balance = 0.0;
	string dateCreated = "";

public:

	Account(int id = 0, double balance = 0.0);
	int getId();
	void setID(int);
	double getBalance();
	void setBalance(double);
	void WithDraw();
	void Deposit();
	void DisplayAccountBalance();
};


class SavingsAccount : public Account{

public:
	double annualInterestRate = 3.45; // Just  for calculations
	void getMonthlyInterestRate();
	double getMonthlyInterest();
};


class CheckingAccount : public Account{

	double overdraft = .0;
public:
	double getoverdraft() const;

};

Account::Account(int Id, double Balance){
	setID(Id);
	setBalance(Balance);
}

void Account::setID(int newID)
{
	id = newID;
}
int Account::getId()
{
	return id;
}
void Account::setBalance(double newBanlance){
	balance = newBanlance;
}
double Account::getBalance()
{
	return balance;
}


int DisplayMenu() {

	int UserInputOption = -1;
	cout << endl;
	cout << "Main Menu" << endl;
	cout << "1.Check the balance" << endl;
	cout << "2.Withdraw " << endl;
	cout << "3.Deposit " << endl;
	cout << "4.Exit" << endl;
	cin >> UserInputOption;
	cout << endl;
	return UserInputOption;

}

void Account::DisplayAccountBalance() {

	cout << "You Account Balance is: R" << balance << endl;
}

void Account::WithDraw(){

	int UserInputOption = -1;
	double RequestedAmount = 0.0;
	bool isNotFinished = true;
	do {

		cout << "Please Enter 1 to Withdraw or 2 to  cancel transaction" << endl;
		cin >> UserInputOption;
		switch (UserInputOption) {

		case 1:
			cout << "Enter Amount to WithDraw: R";
			cin >> RequestedAmount;
			balance = balance - RequestedAmount;
			cout << endl;
			cout << "Amount of -R" << RequestedAmount << " has been withdrew and new Balance is : R" << balance << endl;
			isNotFinished = false;
			break;

		case 2:
			isNotFinished = false;
			break;

		default:
			cout << "Invalid option! Try again." << endl;
			break;
		}

		if (RequestedAmount != 0) {
			if (RequestedAmount > balance) {
				cout << "Opps!! Your Account Balance is Only R" << balance << ". You can't withdraw R" << RequestedAmount << endl;
			}
			else {
				balance = balance - RequestedAmount;
				isNotFinished = false;
			}
			RequestedAmount = 0.0;
		}

	} while (isNotFinished);

}

void Account::Deposit() {

	int UserInputOption = -1;
	bool isNotFinished = true;
	long depositAmount = 0;

	do {

		cout << "Please Enter 1 to Deposit or 2 to  cancel transaction" << endl;
		cin >> UserInputOption;
		switch (UserInputOption) {
		case 1:
			cout << "Please Enter Amount to Deposit: R";
			cin >> depositAmount;
			balance = balance + depositAmount;
			cout << endl;
			cout << "Amount of +R" << depositAmount << " has been deposited and new Balance is : R" << balance << endl;
			isNotFinished = false;
			break;

		case 2:
			isNotFinished = false;
			break;
		default:
			cout << "Invalid option! Try again." << endl;
			break;
		}

	} while (isNotFinished);

}

void SavingsAccount::getMonthlyInterestRate(){

	double monthlyInterestRate = .0;
	int annual = 12;
	monthlyInterestRate = annualInterestRate / annual;
	//cout << "The amount Interest rate is R" << monthlyInterestRate << endl;
}

double SavingsAccount::getMonthlyInterest(){

	double monthlyInterest = .0;
	//monthlyInterest = balance * getMonthlyInterestRate();
	//cout << "The amount Interest  is R" << monthlyInterest << endl;
	return monthlyInterest;
}


int main() {

	Account account;
	SavingsAccount savingsAccount;
	//CheckingAccount checkingAccount = [];



	int isNotFinished = true;

	do {

		switch (DisplayMenu()) {
		case 1:
			account.DisplayAccountBalance();
			break;
		case 2:
			account.WithDraw();
			break;
		case 3:
			account.Deposit();
			break; 
		case 4:
			isNotFinished = false;
			break;
		default:
			cout << "Please Check your  option! Try again." << endl;
			break;
		}
		savingsAccount.getMonthlyInterestRate();

	} while (isNotFinished);



	return 0;

}
