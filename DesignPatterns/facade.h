#ifndef FACADE_H
#define FACADE_H
#include <iostream>
using namespace  std;

//  1. Subsystem
class singlePoint{

    private : double x, y;
    public : singlePoint(double xx, double yy);
    public : void move(int dx, int dy);
    public : std::string toString();
    public : double getX();
    public : double getY();
};
//  2. Subsystem
class polarPoint{

    private : double angle, radius;
    public : polarPoint(double radius, double angle);
    public : void rotate(int angl);
    public : std::string toString();
};
// 1. Desired Interface : move() , rotate()
class Point {

    private : singlePoint *sp;    // 2. Design a wrapper class
    public : Point(double xx, double yy);
    public : void move(int dx, int dy);
    public : void rotate(int angle, Point *p);
    public : std::string toString();
};
class Line{

    private : Point *o, *e;
    public : Line(Point *o, Point *e);
    public : void move(int dx, int dy);
    public : void rotate(int angle);
    public : void toString();
};

#endif // FACADE_H
