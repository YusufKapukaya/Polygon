//
//  polygon.hpp
//  polygon
//
//  Created by Yusuf Kapukaya  on 12.03.2025.
//

#ifndef polygon_hpp
#define polygon_hpp

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "point.hpp"




class Polygon {
    std::vector<Point> points;
public:
    Polygon(){};
    Polygon(const Point & one);
    Polygon(const std::vector<Point> & dots);
    
    Polygon(const Polygon& old );
    Polygon(Polygon&& old );
//    virtual ~Polygon();
    
    Polygon& operator=(const Polygon&);
    Polygon& operator=(Polygon&&);
    Polygon& operator+=(Point new_point);
    
    Point operator[](int index);
    Polygon& operator()(int angle, Point shift);
    Polygon& operator()(Point shift);
    
    //Stream Operators
    friend std::istream& operator>>(std::istream & in , Polygon & object);
    friend std::ostream& operator<<(std::ostream & out , Polygon & object);
    //gravityCenter, getAmount, print, area
    int getAmount();
    float area();
    Point gravityCenter();
    //virtual void writeNameOfPolygon()const;
    
    std::ostream& print(std::ostream& out);
    friend std::ostream& operator<<(std::ostream& out, Polygon& object);
    friend std::istream& operator>>(std::istream& in, Polygon& object);

};
#endif /* polygon_hpp */
