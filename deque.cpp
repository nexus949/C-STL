#include<iostream>
#include "printData.h"
#include<deque>

int main(){
    std::deque<int> deck = {66, 44, 22, 77, 99, 11, 33, 88};

    //1 block of deck can store 128 elements (512 byte block size).
    //std::deque provides random access using two step lookup by combining hashmap's constant time lookup and array's constant time lookup.
    //although is slower than std::vector's single step lookup.

    printData_WithAddress(deck);

    //std::deque uses fixed size arrays(blocks) to store elements and maintains a hashmap of pointers to the location of the blocks
    std::cout<<"Size of a deque object: "<<sizeof(deck)<<std::endl;
    std::cout<<"-----------------------------------------------------"<<std::endl;

    //insert at front and back; constant time
    deck.push_back(55);
    deck.push_front(110);
    std::cout<< "Deque after pushing elements at the back and front: ";
    printData(deck);

    //remove element from the front and back; constant time
    deck.pop_back();
    deck.pop_front();
    std::cout<< "Deque after popping elements at the back and front: ";
    printData(deck);

    std::cout<<"-----------------------------------------------------"<<std::endl;


    // Interesting question here ->
    /*
    Q. If deque maintains "Fixed sized" arrays internally how is removal at front performed at O(1) ?

    A. If a pop_front() is executed [removed first element], rather than removing it the begin pointer is incremented by 1 to point to the next element. The previous element still
       stays in that particular array (block);

       d = {2, 4, 6, 8}; begin pointer points to index 0 (element: 2).
       d.pop_front();
       d = { , 4, 6, 8}; begin pointer points to index 1 (element: 4). Element 2 is still present but inaccessible and we shall not access it either.
    */
   
    std::deque<int> deck2;
    std::deque<int>::iterator it = deck2.begin();
    deck2.push_back(45);
    deck2.push_back(46);
    deck2.push_back(47);

    std::cout<< "value: " << *it << ", address: " << &(*it) << std::endl; it++;
    std::cout<< "value: " << *it << ", address: " << &(*it) << std::endl; it++;
    std::cout<< "value: " << *it << ", address: " << &(*it) << std::endl;

    std::cout<<"-----------------------------------------------------"<<std::endl;

    deck2.pop_front();
    it = deck2.begin();
    //std::cout<< "value: " << *it << ", address: " <<  &(*it) << std::endl; --it; //element at front still present !!! CAUTION - DO NOT DO THIS !!!
    std::cout<< "value: " << *it << ", address: " <<  &(*it) << std::endl;

    return 0;
}