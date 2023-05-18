#include "Current.hpp"

#include <iostream>

Current::Current(const std::string& name, int age, int balance, int money_spent)
    : Account(name, age, balance), money_spent(money_spent) {}

void Current::displayDetails()
{
    Account::displayDetails();
    std::cout << "money_spent: " << money_spent << std::endl;
}
