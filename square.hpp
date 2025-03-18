//
//  square.hpp
//  polygon
//
//  Created by Yusuf Kapukaya  on 12.03.2025.
//

#ifndef square_hpp
#define square_hpp

#include <iostream>
#include "polygon.hpp"

class Square:public Polygon {
    
    
public:
    Square();
    ~Square();
    int howMuchTriangleExist()const;
};

#endif /* square_hpp */
