#pragma once
#ifndef PRINTDATA_H
#define PRINTDATA_H

template <typename T>

void printData(const T& dataStructure){
    for(auto element : dataStructure){
        std::cout<< element <<" ";
    }

    std::cout<<std::endl;
}

#endif