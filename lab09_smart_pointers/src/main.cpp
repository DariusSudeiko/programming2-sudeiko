/*Tasks:
1. Implement a class `Shape` with private member variables for the name (string) and color (string). Use `std::unique_ptr` to manage dynamically allocated memory for the name string.
   - Implement the constructor that takes the name and color as parameters and initializes the member variables using `std::make_unique`.
   - Implement a display function to print the name and color of the shape.
   - Test the class by creating an instance of `Shape` and calling the display function.
2. Add a member function `calculateArea()` to the `Shape` class that calculates and returns the area of the shape.
   - Use appropriate member variables and logic for each type of shape (e.g., circle, square, triangle).
   - Test the function by creating different shapes and calling the `calculateArea()` function. 
3. Implement a move constructor for the `Shape` class that transfers ownership of the unique pointer when a `Shape` object is moved.
   - Create two `Shape` objects and move one into the other.
   - Verify that the ownership of the unique pointer is correctly transferred.  */

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <math.h>

enum class ShapeType
{
    square,
    triangle,
    circle
};

class Shape
{
private:
    std::unique_ptr<std::string> name;
    std::unique_ptr<std::string> color;
    ShapeType type;
public:
    Shape(const std::string &name, const std::string &color, ShapeType type)
        : name(std::make_unique<std::string>(name)),
          color(std::make_unique<std::string>(color)),type(type) {}
    void display() const
    {
        std::cout << "name: " << (*name) << std::endl;
        std::cout << "color: " << (*color) << std::endl;
        switch (type)
        {
        case ShapeType::circle:
            std::cout << "shape: " << "circle " << std::endl;
            break;
        case ShapeType::square:
            std::cout << "shape: " <<  "square" << std::endl;
            break;
        case ShapeType::triangle:
            std::cout << "shape: " <<  "triangle" << std::endl;
            break;
        }
        
    }

    void calculateArea() const
    {
        switch (type)
        {
        case ShapeType::square:
            {
            std::cout << "Calculate area of square: ";
            std::cout << "enter lenght followed by width: ";
            double width;
            double lenght;
            std::cin >> width >> lenght;
            double square_area = width*lenght;
            std::cout << "square area: " << square_area << "\n";
            break;
            }
        case ShapeType::triangle:
            {
            std::cout << "Calculate area of triangle: ";
            std::cout << "enter lenghts of all three sides: ";
            double side1,side2,side3;
            std::cin >> side1 >> side2 >> side3;
            double s = (side1+side2+side3)/2;
	        double triangle_area = std::sqrt(s*(s-side1)*(s-side2)*(s-side3));
            std::cout << "triangle area: " << triangle_area << "\n";
            break;
            }
        case ShapeType::circle:
            {
            std::cout << "Calculate area of circle: ";
            std::cout << "enter lenght of radius: ";
            double radius;
            std::cin >> radius;
            double circle_area = 3.14*(radius*radius);
            std::cout << "circle area: " << circle_area << "\n";
            break;
            }
        }
    }
    // Move constructor
    Shape(Shape &&other) noexcept
        : color(std::move(other.color)),
          name(std::move(other.name)),
          type(other.type)
    {
    }
};

int main(){
    Shape shape1("big", "red", ShapeType::circle);
    Shape shape2("funny","black", ShapeType::square);
    Shape shape3("silly", "yellow", ShapeType::triangle);
    shape2.display();
      // Move the second MusicPlayer to a new MusicPlayer object
    Shape shape4(std::move(shape2));
    std::cout << "Moved Shape:" << std::endl;
    shape4.display();
    std::cout << "------------------------" << std::endl;
    shape1.display();
    shape3.display();
    shape1.calculateArea();
    shape2.calculateArea();
    shape3.calculateArea();

}

