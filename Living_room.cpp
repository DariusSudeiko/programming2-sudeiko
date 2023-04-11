#include "Living_room.hpp"

double Living_room::getWidth() const
{
    return m_data[0];
}
double Living_room::getLenght() const
{
    return m_data[1];
}
double Living_room::getHeight() const
{
    return m_data[2];
}
double Living_room::getArea() 
{
    return m_data[0]*m_data[1];
}
 
double Living_room::getVolume() 
{
    return m_data[0]*m_data[1]*m_data[2];
}

void Living_room::setWidth(double value)
{
    m_data[0] = value;
}
void Living_room::setLenght(double value)
{
    m_data[1] = value;
}
void Living_room::setHeight(double value){
    m_data[2]=value;
}
