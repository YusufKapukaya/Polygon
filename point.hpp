//
//  point.hpp
//  polygon
//
//  Created by Yusuf Kapukaya  on 12.03.2025.
//

#ifndef point_hpp
#define point_hpp

#include <iostream>

class Point{
    float mx, my;
public:
    Point(float x=0, float y=0):mx(x),my(y)
    {
    }
    Point(const Point& old):mx(old.getX()), my(old.getY()){}
    Point(const Point&& old):mx(old.mx), my(old.my){}
    Point& operator=(const Point& old){
        setX(old.getX()); //is this->setX() necessary??
        setY(old.getX());
        return *this;
    }
    void setX(float _x){mx=_x;}
    void setY(float _y){my=_y;}
    float getX()const {return mx;}
    float getY()const {return my;}
};

#endif /* point_hpp */
