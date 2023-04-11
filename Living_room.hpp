#ifndef LIVING_ROOM_HPP_
#define LIVING_ROOM_HPP_


class Living_room
{
private:
    // double width;
    // double length;
    // double height;
    double m_data[3];

public:
    double getWidth() const;
    double getLenght() const;
    double getHeight() const;
    double getArea();
    double getVolume();
    void setWidth(double value);
    void setLenght(double value);
    void setHeight(double value);// change
};
#endif