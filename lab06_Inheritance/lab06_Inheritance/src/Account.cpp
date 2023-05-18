#include "Account.hpp"

#include <iostream>
#include <string>

Account::Account (const std::string& name, int age, int balance)
    : name(name), age(age), balance(balance) {}

void Account::displayDetails()
{
    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl;
    std::cout << "balance: " << balance << std::endl;
}