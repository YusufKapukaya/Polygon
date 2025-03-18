//
//  getFromFlow.hpp
//  polygon
//
//  Created by Yusuf Kapukaya  on 13.03.2025.
//

#ifndef getFromFlow_hpp
#define getFromFlow_hpp

#include <stdio.h>
#include<iostream>


template<typename Number>
int getFromFlow(Number &num, std::istream &flow){
    flow>>num;
    while (!flow.good()) {
        std::cout<<"Error. Repeat:";
        flow.clear();
        flow.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        flow>>num;
    }
    return 1;
}

#endif /* getFromFlow_hpp */
