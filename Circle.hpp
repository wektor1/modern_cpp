#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle(double r, Color c);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    [[deprecated]] double getPi() const;
    double getRadius() const;
    void print() const override;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
