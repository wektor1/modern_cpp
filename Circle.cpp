#include "Circle.hpp"
#include <math.h>
#include <iostream>

static_assert(M_PI != 3.14);

Circle::Circle(double r)
    : r_(r)
{}

Circle::Circle(double r, Color c) : Circle(r)
{
    color = c;
}


double Circle::getPi() const
{
    return M_PI;
}

double Circle::getArea() const noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
