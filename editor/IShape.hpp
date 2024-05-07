#pragma once

#include <iostream>
#include <string>
#include <sstream>

struct Coordinate
{
    int x;
    int y;
};

class IShape
{
protected:
    Coordinate center;

public:
    void placement(int x, int y)
    {
        center.x = x;
        center.y = y;
    }
    virtual std::string serialize() const = 0;
    virtual std::string getMetaData() const = 0;
    ~IShape() {std::cout << "clear shapes\n";}
};

class Square : public IShape
{
    int a, b;

public:
    Square() = delete;
    Square(int a_, int b_, int x, int y) : a(a_), b(b_)
    {
        placement(x, y);
        std::cout << "square created\n";
    }
    virtual std::string serialize() const override
    {
        std::stringstream ss;
        ss << "square ( a = " << a << " , b = " << b << " ), with center coordinates: (" << 
        center.x << " , " << center.y << ") serialization\n";
        return ss.str();
    }
    virtual std::string getMetaData() const override{
        std::stringstream ss;
        ss << "required metadata and data about square for view\n";
        return ss.str();
    }
    // ~Square()
    // {
    //     std::cout << "square deleted\n";
    // }
};

class Circle : public IShape
{
    int r;
    Coordinate center;
public:
    Circle() = delete;
    Circle(int r_, int x, int y) : r(r_)
    {
        placement(x, y);
        std::cout << "circle created\n";
    }
    virtual std::string serialize() const override
    {
        std::stringstream ss;
        ss << "circle ( r = " << r << " ), with center coordinates: (" << 
        center.x << " , " << center.y << ") serialization\n";
        return ss.str();
    }
    virtual std::string getMetaData() const override{
        std::stringstream ss;
        ss << "required metadata and data about circle for view\n";
        return ss.str();
    }
    // ~Circle()
    // {
    //     std::cout << "circle deleted\n";
    // }
};

class Line : public IShape
{
    int l;
    Coordinate center;
public:
    Line() = delete;
    Line(int l_, int x, int y) : l(l_)
    {
        placement(x, y);
        std::cout << "line created\n";
    }
    virtual std::string serialize() const override
    {
        std::stringstream ss;
        ss << "line ( l = " << l << " ), with center coordinates: (" << 
        center.x << " , " << center.y << ") serialization\n";
        return ss.str();
    }
    virtual std::string getMetaData() const override{
        std::stringstream ss;
        ss << "required metadata and data about line for view\n";
        return ss.str();
    }
    // ~Line()
    // {
    //     std::cout << "line deleted\n";
    // }
};