#include <iostream>
#include "printData.h"
#include <array>

int main(){

    // simple array data structure stores numbers in contiguous memory
    std::array<int, 4> arr = {1, 3, 5, 7};
    printData(arr);

    // access elements at constant time
    arr[2] = 9;
    printData(arr);

    // size function to access the size of the array
    std::cout << "size: " << arr.size() << std::endl;

    // returns the size of the array in bytes -> Number of elements * size of each element in byte
    std::cout << "size: " << sizeof(arr) << std::endl;
    return 0;
}