#include <iostream> //mish mash of code from my other quiz program and copying notes from class. Dont expect this to work at all.
#include <string>
using namespace std;
int number = 100;

class BankAccount {
private:
public:
	char userInput;
	string name = "default";
	int acct_number;
	string phone;
	bool accountCreated = false;
	int balance = 0;
	float rate;


	void deposit(int x) {
		balance += x;
	}
	void withdraw(int y) {
		balance -= y;
	}

	//BankAccount() {
	//	string nm = "Anonymous";
	//	string ph = "555-555-5555";
	//	BankAccount(nm, ph);
	//}
	void createAccount () {
		cout << "Account name: ";
		cin >> name;
		cout << "Phone number: ";
		cin >> phone;
		rate = 5.0;
		acct_number = number++;
		balance = 0;
		accountCreated = true;
	}
	void print() {
		cout << "Account number: " << acct_number << endl;
		cout << "ACcount name: " << name << endl;
		cout << "Phone: " << phone << endl;
		cout << "Balance: " << balance << endl;
		cout << "Rate: " << rate << endl << endl;
	}

};

class savings : public BankAccount {
private:
	int minimum_balance = 200;
	int withdraw_limit = 1000;

public:

	bool CheckUnderMin() {
		if (balance < minimum_balance) {
			return true;
		}
		else {
			return false;
		}
	}

	//bool overLimit() {
	//	if (BankAccount.withdraw > withdraw_limit) {
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}
};

class checking : public BankAccount {
public:

	int overdraft_fee = 20;

	bool checkOverdraft() {
		if (balance < 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	BankAccount B;
	savings S;
	checking C;
	bool keepAlive = true;
	char userInput;
	char saveOrCheck;
	int amount;

	while (keepAlive == true) {
		cout << endl << "Welcome to 'Not-A-Scam' bank!" << endl << "Menu: " << endl << "Create account (a)" << endl << "Deposit to account (d)" << endl << "Withdraw from account (w)" << endl << "Print totals (p)" << endl << "Show this menu again (m)" << endl << "Exit the program (x)" << endl << "Please make a selection: ";
		cin >> userInput;
		cout << endl;
		switch (userInput) {
		case 'x':
			keepAlive = false;
			break;
		case 'a':
			cout << "Create checking (c) or savings (s) account?: ";
			cin >> saveOrCheck;
			if (saveOrCheck == 'c') {
				if (C.accountCreated == false) {
					C.createAccount();
				}
				else {
					cout << "You already have a checking account." << endl;
				}
			}
			else if (saveOrCheck == 's') {
				if (S.accountCreated == false) {
					S.createAccount();
				}
				else {
					cout << "You already have a savings account." << endl;
				}
			}
			else {
				cout << "Sorry, I didn't get that." << endl;
			}
			break;
		case 'd':
			cout << "Deposit into checking (c) or savings (s) account?: ";
			cin >> saveOrCheck;
			if (saveOrCheck == 'c') {
				if (C.accountCreated == false) {
					cout << "You don't have a checking account." << endl;
				}
				else {
					cout << "Deposit how much? ";
					cin >> amount;
					C.deposit(amount);
					cout << "You now have " << C.balance << " dollars in this account." << endl;
				}
			}
			else if (saveOrCheck == 's') {
				if (S.accountCreated == false) {
					cout << "You don't have a savings account." << endl;
				}
				else {
					cout << "Deposit how much? ";
					cin >> amount;
					S.deposit(amount);
					cout << "You now have " << S.balance << " dollars in this account." << endl;
				}
			}
			else {
				cout << "Sorry, I didn't get that." << endl;
			}
			break;
		case 'w':
			cout << "Withdraw from checking (c) or savings (s) account?: ";
			cin >> saveOrCheck;
			if (saveOrCheck == 'c') {
				if (C.accountCreated == false) {
					cout << "You don't have a checking account." << endl;
				}
				else {
					cout << "Withdraw how much? ";
					cin >> amount;
					C.withdraw(amount);
					cout << "You now have " << C.balance << " dollars in this account." << endl;
				}
			}
			else if (saveOrCheck == 's') {
				if (S.accountCreated == false) {
					cout << "You don't have a savings account." << endl;
				}
				else {
					cout << "Withdraw how much? ";
					cin >> amount;
					S.withdraw(amount);
					cout << "You now have " << S.balance << " dollars in this account." << endl;
				}
			}
			else {
				cout << "Sorry, I didn't get that." << endl;
			}
			break;
		case 'p':
			if (C.accountCreated == false) {
				cout << "You do not have a checking account with us." << endl;
			}
			else{
				C.print();
			}
			if (S.accountCreated == false) {
				cout << "You do not have a savings account with us." << endl;
			}
			else {
				S.print();
			}
			break;
		case 'm':
			break;
		default:
			cout << "Sorry, I didn't get that." << endl;
		}
	}

	return 0;
}
