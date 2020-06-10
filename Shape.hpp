#pragma once

enum class Color 
{
    red,
    green,
    blue
};

class Shape
{
public:
    virtual ~Shape() {}
    Color color;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
