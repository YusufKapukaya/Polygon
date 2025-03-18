//
//  dialog.hpp
//  polygon
//
//  Created by Yusuf Kapukaya  on 14.03.2025.
//

#ifndef dialog_hpp
#define dialog_hpp

#include <iostream>
#include <string>
#include "polygon.hpp"

class Dialog {
    
public:
    Dialog(){};
    void print_line(const std::string& line);
    int menu();
    
    void MakeItem(Polygon& shape);
    void PrintItem(Polygon& shape);
    void GravityItem(Polygon& shape);
    void GetPointItem(Polygon& shape);
    void RotateItem(Polygon& shape);
    void MoveItem(Polygon& shape);
    void AddPointItem(Polygon& shape);
};

#endif /* dialog_hpp */
