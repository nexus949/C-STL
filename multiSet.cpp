#include<iostream>
#include "printData.h"
#include<set>

typedef struct Vertex{
    int v1, v2;

    //constructors
    Vertex() : v1(0), v2(0) {}
    Vertex(int _vertex1, int _vertex2) : v1(_vertex1), v2(_vertex2) {}

}vertex;

typedef struct compareVertex{

    //Compare and order the Vertex objects based on the sum of their members (v1 + v2);
    bool operator()(const vertex& vertex1, const vertex& vertex2) const{
        int firstVertex = vertex1.v1 + vertex1.v2;
        int secondVertex = vertex2.v1 + vertex2.v2;
        return firstVertex < secondVertex;
    }
}compareVertex;

int main(){
    
    std::multiset<int> s{3, 5, 7, 9, 11};
    //Unlike sets, multiset allow data storage for duplicates.
    //And like sets, its sorted and implemented as a red black tree.

    //insert into set
    s.insert(5); //inserting duplicate values
    s.insert(5);
    s.insert(15);
    printData(s);

    std::size_t count = s.count(5); //returns the number of the particular element present in the set.
    std::cout<< "Total number of 5s in the set: "<< count << std::endl;

    //erasing element from the set
    s.erase(9); //using key
    auto it = s.find(7); //using iterator
    s.erase(it);
    std::cout<< "Set after erasing elements: ";
    printData(s);

    std::cout<<"------------------------------------------------"<<std::endl;

    std::cout<< "Number of elements present in the set: " << s.size() << std::endl; //returns the number of element present in the set
    std::cout<< "Size of a multiset object: " << sizeof(s) << std::endl; //returns the actual size of the multiset object

    std::cout<<"------------------------------------------------"<<std::endl;

    std::cout<< "set elements with address: "<< std::endl;
    printData_WithAddress(s);

    std::cout<<"------------------------------------------------"<<std::endl;

    //Multiset using custom datatypes
    std::multiset<vertex, compareVertex> s2;
    vertex v1(7, 10);
    vertex v2(9, 11);

    s2.insert(v1);
    s2.insert(v1); //inserting duplicate values
    s2.insert(v2);

    for(const auto& el : s2){
        std::cout<< el.v1 << ", " << el.v2 << std::endl; 
    }
    return 0;
}