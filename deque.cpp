#include<iostream>
#include "printData.h"
#include<deque>

int main(){
    std::deque<int> deck = {66, 44, 22, 77, 99, 11, 33, 66, 88};

    printData_WithAddress(deck);
    return 0;
}