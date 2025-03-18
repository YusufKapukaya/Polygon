//
//  main.cpp
//  polygon
//
//  Created by Yusuf Kapukaya  on 12.03.2025.
//

#include <iostream>
#include "getFromFlow.hpp"
#include "dialog.hpp"
#include "polygon.hpp"

int main(int argc, const char * argv[]) {

    Dialog items;
    
    enum {EXIT, MAKE, PRINT, GRAVITY, GET, ROTATE, MOVE, ADD};
    
    items.print_line("Hey this is program to test polygons");
    
    Polygon shape;
    bool run=true;
    
    
    while (run) {
        
        switch (items.menu()) {
            case MAKE:
                items.MakeItem(shape);
                continue;
            case PRINT:
                items.PrintItem(shape);
                continue;
            case GRAVITY:
                items.GravityItem(shape);
                continue;
            case GET:
                items.GetPointItem(shape);
                continue;
            case ROTATE:
                items.RotateItem(shape);
                continue;
            case MOVE:
                items.MoveItem(shape);
                continue;
            case ADD:
                items.AddPointItem(shape);
                continue;
            default:
                std::cout<<"Thanks\n";
                run=false;
                break;
        }
    }
    
    return 0;
}
