//
//  dialog.cpp
//  polygon
//
//  Created by Yusuf Kapukaya  on 14.03.2025.
//

#include "dialog.hpp"
#include "getFromFlow.hpp"

void Dialog::print_line(const std::string &line){
    std::cout<<line<<'\n';
}

int Dialog::menu(){
    
    
    std::cout<<"0. Exit\n";
    std::cout<<"1. make polygon\n";
    std::cout<<"2. print polygon\n";
    std::cout<<"3. find gravity point\n";
    std::cout<<"4. get point by number\n";
    std::cout<<"5. rotate around point\n";
    std::cout<<"6. move polygon\n";
    std::cout<<"7. add point\n";
    
    
    std::cout<<"Make your choice: -->\n";
    int ReturnCode=-1;
    std::cin>>ReturnCode;
    std::cout<<"Your Choose is "<<ReturnCode<<'\n';
    while (ReturnCode >7 || ReturnCode<0) {
        getFromFlow(ReturnCode, std::cin);
    }
    
    return  ReturnCode;
}


void Dialog::MakeItem(Polygon& shape){
    while (true) {
        try {
            std::cout <<"Enter number of apexes: ";
            std::cin>>shape;
            break;
        } catch (const std::exception& msg) {
            std::cout<<msg.what()<<'\n';
        }
    }
}
void Dialog::PrintItem(Polygon& shape){
    std::cout<<"First way\n";
    std::cout<<shape;
    std::cout<<"Second way\n";
    shape.print(std::cout);
}
void Dialog::GravityItem(Polygon& shape){
    Point gravity_center;
    gravity_center= shape.gravityCenter();
    std::cout <<"Gravity center is  : "
    <<std::setw(10)<<gravity_center.getX()
    <<std::setw(10)<<gravity_center.getY()<<'\n';
}
void Dialog::GetPointItem(Polygon& shape){
    std::cout<<"Enter index:    ";
    int index;
    Point dot;
    getFromFlow(index, std::cin);
    try {
        dot=shape[index];
        std::cout<<'('<<index<<')'
        <<std::setw(10)<<dot.getX()
        <<std::setw(10)<<dot.getY()<<'\n';
    } catch (const std::exception& msg) {
        std::cout <<msg.what()<<'\n';
    }
}
void Dialog::RotateItem(Polygon& shape){
    std::cout<<"Enter x:  ";
    float x, y;
    int angle;
    getFromFlow(x, std::cin);
    std::cout <<"Enter y:   ";
    getFromFlow(y, std::cin);
    std::cout <<"Enter angle:   ";
    getFromFlow(angle, std::cin);
    shape(angle, Point(x,y));
    shape.print(std::cout);
}
void Dialog::MoveItem(Polygon& shape){
    int x, y;
    std::cout<<"Enter x: ";
    getFromFlow(x, std::cin);
    std::cout<<"Enter y: ";
    getFromFlow(y, std::cin);
    shape(Point(x, y));
    std::cout<<shape;
}
void Dialog::AddPointItem(Polygon& shape){
    int x,y;
    std::cout<<"Enter x:    ";
    getFromFlow(x,  std::cin);
    std::cout<<"Enter y:    ";
    getFromFlow(y,  std::cin);
    shape += Point(x,y);
    shape.print(std::cout);
}
