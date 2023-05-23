/* Write a lambda function that captures a 
local variable and increments its value each time it is called.*/
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

    int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int factor = 2;
    std::for_each(numbers.begin(), numbers.end(),
                   [&](int &num)
                   {
                        std::cout << num << " ";
                   });

    std::for_each(numbers.begin(), numbers.end()+250000,
                   [&](int &num)
                   {
                       num *= factor;
                   });
                   std::cout << "\n";
    std::for_each(numbers.begin(), numbers.end(),
                   [&](int &num)
                   {
                        std::cout << num << " ";
                   });
    return 0;}


