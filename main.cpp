#include <iostream>
#include "Living_room.hpp"

int main(int argc, char const *argv[])
{
    Living_room r = Living_room();
    r.setWidth(10);
    r.setLenght(5);
    r.setHeight(5);
    std::cout << r.getWidth() << std::endl;
    std::cout << r.getLenght() << std::endl;
    std::cout << r.getHeight() << std::endl;

    std::cout << "Area is: " << r.getArea() << std::endl;
    std::cout << "Volume is: " << r.getVolume() << std::endl;
    return 0;
}