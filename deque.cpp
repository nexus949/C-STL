#include<iostream>
#include "printData.h"
#include<deque>

int main(){
    // std::deque<int> deck = {66, 44, 22, 77, 99, 11, 33, 88};

    // //1 block of deck can store 128 elements (512 byte block size).
    // //std::deque provides random access using two step lookup by combining hashmap's constant time lookup and array's constant time lookup.
    // //although is slower than std::vector's single step lookup.

    // printData_WithAddress(deck);

    // //std::deque uses fixed size arrays(blocks) to store elements and maintains a hashmap of pointers to the location of the blocks
    // std::cout<<"Size of a deque object: "<<sizeof(deck)<<std::endl;
    // std::cout<<"-----------------------------------------------------"<<std::endl;

    // //insert at front and back; constant time
    // deck.push_back(55);
    // deck.push_front(110);
    // printData(deck);

    // //remove element from the front and back; constant time
    // deck.pop_back();
    // deck.pop_front();
    // printData(deck);

    std::deque<int> deck;
    deck.push_back(45);
    deck.push_back(46);
    deck.push_back(47);

    std::cout<< "value: " << deck[0] << ", address: " << &deck[0] << std::endl;
    std::cout<< "value: " << deck[1] << ", address: " << &deck[1] << std::endl;
    std::cout<< "value: " << deck[2] << ", address: " << &deck[2] << std::endl;

    std::cout<<"-----------------------------------------------------"<<std::endl;

    deck.pop_front();
    std::cout<< "value: " << deck[0] << ", address: " << &deck[0] << std::endl;
    std::cout<< "value: " << deck[1] << ", address: " << &deck[1] << std::endl;
    std::cout<< "value: " << deck[2] << ", address: " << &deck[2] << std::endl;

    return 0;
}