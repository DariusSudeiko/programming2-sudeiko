#include "Savings.hpp"
#include "Current.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "what kind of an account are we creating?: " << std::endl;
    std::cout << "0 for savings, 1 for daily " << std::endl;
    int a,c;
    std::cin >> a;
    switch(a){
        case 0:
        {
        Savings Savings1("Tom", 25, 30043, 50);
        std::cin >> c;
        Savings1.setmoney(c);
        std::cout << std::endl;
        Savings1.displayDetails();
        break;
        }
        case 1:
        {Current Current("Mike", 26, 4000, 100);
        std::cout << std::endl;
        Current.displayDetails();
        break;
        }
        default:
        std::cout << "Choose a different bank for that! " << std::endl;
        return 0;
    }


}
