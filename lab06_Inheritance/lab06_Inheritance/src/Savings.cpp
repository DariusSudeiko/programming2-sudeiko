#include "Savings.hpp"

#include <iostream>

Savings::Savings(const std::string& name, int age, int balance, int money_saved)
    : Account(name, age, balance), money_saved(money_saved) {}

void Savings::displayDetails()
{
    Account::displayDetails();
    std::cout << "money_saved: " << money_saved << std::endl;
}

void Savings::setmoney(int a)
{
        money_saved=a;
}