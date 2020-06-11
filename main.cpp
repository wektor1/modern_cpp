#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "memory"
#include <utility>

using namespace std;

using Collection = vector<shared_ptr<Shape>>;


template<class DerivedType, class... Arguments>
shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return shared_ptr<DerivedType>(forward<Arguments>(args)...);
}

void printCollectionElements(const Collection& collection)
{
    for(auto it : collection)
    {
            (it)->print();
    }
}

void printAreas(const Collection& collection)
{
    for(auto it: collection)
    {
            cout << (it)->getArea() << std::endl;
    }
}

template<class F>
void findFirstShapeMatchingPredicate(const Collection& collection,
                                     F predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main()
{
    auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
};
int x = 10;
auto areaLessThanX = [=](shared_ptr<Shape> s )
{
    if(s)
    {
        return (s->getArea() < x);
    }
    return false;
};
    Rectangle r(2.0, 5.0);
    Collection shapes{
    make_shared<Circle>(2.0),
    make_shared<Circle>(3.0),
    make_shared<Circle>(4.0),
    make_shared<Rectangle>(10.0, 5.0),
    make_shared<Square>(3.0),
    make_shared<Circle>(4.0),
    make_shared<Rectangle>(std::move(r))
    };

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    shared_ptr<Square> square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    return 0;
}

