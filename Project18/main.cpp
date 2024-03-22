#include "BankAccount.h"
#include<iostream>

int main() {
	std::cout << "BankAccount class:\n";
	{
		BankAccount b;
		BankAccount b1{};
		BankAccount b2{};

		b.set_name("Dragos Trandafir");
		b.set_number(722);
		b.set_balance(700);

		std::cout << b.get_name() << std::endl;
		std::cout << b.get_number() << std::endl;
		std::cout << b.get_balance() << std::endl;

		std::cout << b<<std::endl;

		b.deposit_balance(123);
		std::cout << b << std::endl;

		b.withdraw_balance(999999);
		std::cout << b << std::endl;

		b1.set_name("John Doe");
		b1.set_number(123);
		b1.set_balance(1000);

		b2.set_name("Jane Smith");
		b2.set_number(456);
		b2.set_balance(1500);
		BankAccount add = b1 + b2;
		std::cout << "diff result " << add.get_number() << " " << add.get_balance() << std::endl;

		std::cout << b.get_num_inst();
	}
	return 0;
}