#pragma once
#ifndef PRINTDATA_H
#define PRINTDATA_H

template <typename T_1>

void printData(const T_1& dataStructure){
    for(const auto& element : dataStructure){
        std::cout<< element <<" ";
    }

    std::cout<<std::endl;
}

template <typename T_2>
void printData_WithAddress(const T_2& dataStructure){
     for(const auto& element : dataStructure){
        std::cout<< "value: " << element << ", address: " << &element << std::endl;
    }

    std::cout<<std::endl;
}

#endif