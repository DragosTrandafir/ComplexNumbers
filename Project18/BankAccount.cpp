#include "BankAccount.h"
#include<iostream>

//initialize it globally
int BankAccount::NUM_INSTANCES = 0;

BankAccount::BankAccount() {
	this->name = "Reputation";
	this->number = 0;
	this->balance = 0;
	NUM_INSTANCES++; //increases 3 times
}

BankAccount::BankAccount(std::string pname, double pnumber, double pbalance) : name{ pname }, number(pnumber), balance{ pbalance } {
	NUM_INSTANCES++;
	//increases 1 time
}

BankAccount::~BankAccount() {
	//we dont really need a distructor, because we dont use memory allocated dynamically
}

std::string BankAccount::get_name() const {
	return name;
}
double BankAccount::get_number() const {
	return number;
}
double BankAccount::get_balance() const {
	return balance;
}
int BankAccount::get_num_inst() {
	return NUM_INSTANCES;
}

// parameterized constructors (setters)
void BankAccount::set_name(std::string name) {
	this->name = name;
}
void BankAccount::set_number(double number) {
	this->number = number;
}
void BankAccount::set_balance(double balance) {
	this->balance = balance;
}

// friend functions
void BankAccount::deposit_balance(double balance) {
	this->balance += balance;
}
void BankAccount::withdraw_balance(double balance) {
	if (balance > (this->balance))
		std::cout << "You can not withdraw this sum"<<std::endl;
	   else 
		this->balance -= balance;
}

// operations 
ostream& operator<<(ostream& os, const BankAccount& b) {
	os << "(" << b.name << "," << b.number << "," << b.balance << ")" << std::endl;
	return os;
}
BankAccount operator+(const BankAccount& b1, const BankAccount& b2) {
	return BankAccount{ b1.name, b1.number + b2.number, b1.balance + b2.balance };
}