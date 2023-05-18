#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_

#include <string>

class Account {
protected:
    std::string name;
    int age;
    int balance;

public:
    Account (const std::string& name, int age, int balance);
    void displayDetails();
};

#endif //ACCOUNT_HPP_
