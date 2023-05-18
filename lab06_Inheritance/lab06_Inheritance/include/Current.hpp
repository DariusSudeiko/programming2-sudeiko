#ifndef CURRENT_HPP_
#define CURRENT_HPP_

#include "Account.hpp"

class Current : public Account {
private:
    int money_spent;

public:
    Current(const std::string& name, int age, int balance, int money_spent);

    void displayDetails();
};


#endif //CURRENT_HPP_
