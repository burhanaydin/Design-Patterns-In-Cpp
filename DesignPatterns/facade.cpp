#include <iostream>
#include <cmath>
#include "facade.h"
using namespace  std;

singlePoint::singlePoint(double xx, double yy){

    this->x = xx;     this->y = yy;
}
void singlePoint::move(int dx, int dy){

    this->x +=dx;     this->y += dy;
}
std::string singlePoint::toString(){

    return "( " + std::to_string(x) + "," + std::to_string(y) + " )";
}
double singlePoint::getX(){

    return x;
}
double singlePoint::getY(){

    return y;
}

polarPoint::polarPoint(double radius, double angle){

    this->radius = radius;
    this->angle = angle;
}
void polarPoint::rotate(int angl){

    this->angle += angl % 360;
}
std::string polarPoint::toString(){

    return "[ " +  std::to_string(radius) + " @ " +   std::to_string(angle) + " ]";
}
Point::Point(double xx, double yy){

    this->sp = new singlePoint(xx, yy);
}
void Point::move(int dx, int dy){

    this->sp->move(dx, dy);
}
std::string Point::toString(){
    return this->sp->toString();
}

void Point::rotate(int angle, Point *p){

    double x = this->sp->getX() - p->sp->getX();
    double y = this->sp->getY() - p->sp->getY();
    const long double PI = 3.141592653589793238L;
    polarPoint pp(sqrt(x*x+y*y), atan2(y,x)*100/PI);
    pp.rotate(angle);
    std::cout << "Polar Point is " << pp.toString() << endl;
    std::string str = pp.toString();
    int index = str.find_first_of("@",0);
    double r = std::stod(str.substr(1,index-1));
    double a = std::stod(str.substr(index+2, str.length()-1));
    this->sp = new singlePoint(r*cos(a*PI/180) + p->sp->getX(),
                          r*sin(a*PI/180) + p->sp->getY());
}
Line::Line(Point *o, Point *e){
    this->o = o;
    this->e = e;
}
void Line::move(int dx, int dy){
    this->o->move(dx, dy);
    this->e->move(dx, dy);
}
void Line::rotate(int angle){
    this->e->rotate(angle, o);
}
void Line::toString(){
    std::cout << "origin is " << this->o->toString() << ", end is " << this->e->toString() << endl;
}
