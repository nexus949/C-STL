#include <iostream>
#include "printData.h"
#include <vector>

int main(){

    // dynamically allocated array which can be resized
    std::vector<int> vec;

    vec.push_back(4); // add element at the end of the vector
    vec.push_back(7); // add element at the end of the vector
    vec.push_back(10); // add element at the end of the vector
    vec.push_back(5); // add element at the end of the vector
    vec.push_back(2); // add element at the end of the vector
    vec.push_back(39); // add element at the end of the vector
    printData(vec);

    vec.pop_back(); // remove the last element from the vector
    printData(vec);

    std::cout << "size: " << vec.size() << std::endl;         // returns the number of elements present in the vector
    std::cout << "capacity: " << vec.capacity() << std::endl; // returns the capacity of how many elements can be held in the vector

    std::cout << sizeof(vec) << std::endl; // return the size of the vector object (24 bytes on 64bit systems)

    std::cout << "Iterating over the Vector using iterator: "<<std::endl;

    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        std::cout<< *it << " ";
    }

    std::cout<<std::endl;
    return 0;
}