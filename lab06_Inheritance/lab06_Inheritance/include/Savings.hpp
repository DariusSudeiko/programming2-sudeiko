#ifndef SAVINGS_HPP_
#define SAVINGS_HPP_

#include "Account.hpp"

class Savings : public Account {
private:
    int money_saved;

public:
    Savings(const std::string& name, int age, int balance, int money_saved);

    void displayDetails();

    void setmoney (int a);
    };

#endif //SAVINGS_HPP_
