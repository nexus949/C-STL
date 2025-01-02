#include<iostream>
#include "printData.h"
#include<list>

int main(){
    std::list<int> li;

    li.push_back(13); //add elements at the back of the list
    li.push_back(2);
    li.push_back(3);
    li.push_back(231);
    li.push_back(22);
    li.push_back(279);
    li.push_front(351); //add elements at the front of the list

    printData(li);
    std::cout<<"----------------------------------------------------------------"<<std::endl;

    std::cout<<"begin() -> "<<*(li.begin())<<std::endl; //returns the first element of the list
    std::cout<<"end() -> "<<*(li.end())<<std::endl;  //returns the element present after the end of the list (garbage value) [DO NOT DEREFERENCE end()]

    std::cout<<"size of list -> "<<sizeof(li)<<std::endl; //returns size of the list object (not number of nodes in the list)
    std::cout<<"size of list(no. of nodes) -> "<<li.size()<<std::endl; //returns the number of nodes in the list 

    //move iterator in the list by n nodes
    std::list<int>::iterator it = li.begin();
    std::advance(it, 2);  //std::advance does not return an iterator
    std::cout<<"Iterator after moving, points to: "<<*it<<std::endl;

    //get a new itertor returned after moving n nodes
    auto next_iter = std::next(li.begin(), 4); //std::next does return a new iterator
    std::cout<<"Iterator after moving, points to: "<<*next_iter<<std::endl;

    //insert after particular node
    std::cout<<"----------------------------------------------------------------"<<std::endl;
    std::cout<<"List before insertion: ";
    printData(li);
    
    li.insert(next_iter, 552);
    
    std::cout<<"List after insertion: ";
    printData(li);

    return 0;
}