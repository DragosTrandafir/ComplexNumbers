#include<iostream>
using namespace std;

class BankAccount
{
public:
	BankAccount();
	BankAccount(std::string pname, double pnumber, double pbalance);
	~BankAccount();

	std::string get_name() const;
	double get_number() const;
	double get_balance() const;

	void set_name(std::string name);
	void set_number(double number);
	void set_balance(double balance);

	//deposit funds
	void deposit_balance(double balance);
	void withdraw_balance(double balance);

	friend ostream& operator<<(ostream& os, const BankAccount& b);
	friend BankAccount operator+(const BankAccount& b1, const BankAccount& b2);

	static int get_num_inst();
private:
	std::string name;
	double number;
	double balance;
	//static variable
	static int NUM_INSTANCES;
};

