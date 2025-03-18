//
//  polygon.cpp
//  polygon
//
//  Created by Yusuf Kapukaya  on 12.03.2025.
//

#include "polygon.hpp"
#include "getFromFlow.hpp"

Polygon::Polygon(const Point& one){
    points.push_back(one);
}

Polygon::Polygon(const std::vector<Point>& dots){
    for(auto& dot:dots){
        points.push_back(dot);
    }
}


Polygon::Polygon(const Polygon& old){
    for (auto& dot :old.points)  {
        points.push_back(dot);
    }
}

Polygon::Polygon(Polygon&& old){
    points.swap(old.points);
}


Polygon& Polygon::operator=(const Polygon & old){
    for (auto& dot :old.points)  {
        points.push_back(dot);
    }
    return *this;
}

Polygon& Polygon::operator=(Polygon&& old){
    points.swap(old.points);
    return *this;
}


Polygon& Polygon::operator+=(Point new_point){
    points.push_back(new_point);
    return *this;
}

Point Polygon::operator[](int index){
    if(index>-1 && index<points.size())
        return points[index];
    else
        throw std::out_of_range("The index is out of range");
}

int Polygon::getAmount(){
    return static_cast<int>(points.size());
}

float Polygon::area(){
    float result=0.0;
    for (auto i=0; i<points.size(); i++) {
        result +=points[i].getX()*points[i+1].getY();
        result -=points[i+1].getX()*points[i].getY();
    }
    return result/2;
}

Point Polygon::gravityCenter(){
    float _x=0.0, _y=0.0,semiResult=0.0;
    
    for (auto i=0; points.size(); i++) {
        semiResult +=points[i].getX()*points[i+1].getY();
        semiResult -=points[i+1].getX()*points[i].getY();
        
        _x +=(points[i].getX()+points[i+1].getX())*semiResult;
        _y +=(points[i].getY()+points[i+1].getY())*semiResult;
    }
    
    _x=_x/(6*area());
    _y=_y/(6*area());
    return Point(_x, _y);
}

Polygon& Polygon::operator()(int angle, Point shift){
    if (angle<0) {
        angle*=-1;
    }
    
    float _x=0.0, _y=0.0;
    float cs=cos(angle*M_PI/180);
    float sn=sin(angle*M_PI/180);
    for (auto point : points) {
        _x= point.getX()-shift.getX();
        _y= point.getY()-shift.getY();
        _x=_x*cs-_y*sn;
        _y=_x*sn+_y*cs;
        _x=_x+shift.getX();
        _y=_y-shift.getY();
        point.setX(_x);
        point.setY(_y);
    }
    return *this;
}

Polygon& Polygon::operator()(Point shift){
    float _x=0.0, _y=0.0;
    for (int i=0;i <points.size(); i++) {
        _x=points[i].getX()+shift.getX();
        _y=points[i].getY()+shift.getY();
        points[i].setX(_x);
        points[i].setY(_y);
    }
    return  *this;
}

std::ostream& Polygon::print(std::ostream& out){
    if (points.empty()) {
        out<<"There is no polygon\n";
    }else{
        for (int i=0; i<points.size(); i++) {
            out<<'('<<i+1<<')'
            <<std::setw(10)<<points[i].getX()
            <<std::setw(10)<<points[i].getY()
            <<'\n';
        }
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, Polygon& object){
    object.print(out);
    return out;
}
std::istream& operator>>(std::istream& in, Polygon& object){
    int size;
    getFromFlow(size,in);
    float _x, _y;
    for (auto k=0; k<size; k++) {
        getFromFlow(_x, in);
        getFromFlow(_y, in);
        object += Point(_x,_y);
    }
    return in;
}
