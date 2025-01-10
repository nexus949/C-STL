#include<iostream>
#include "printData.h"
#include<set>

typedef struct vertex{
    int _vertex;

    //constructors
    vertex() : _vertex(0) {}
    vertex(int _v) : _vertex(_v) {}

}vertex;

typedef struct compareVertex{
    bool operator()(const vertex& v1, const vertex& v2) const{
        return v1._vertex < v2._vertex;
    }
}compareVertex;

int main(){

    std::set<int> s{ 7, 9, 11, 13, 15};
    //set are ordered containers with unique values stored in specific order
    //sets are usually implemented using red - black trees to maintain order. Since its using tree the time complexity is logarithmic.
    s.insert(112);
    s.insert(-8);
    s.insert(116);

    printData_WithAddress(s);

    std::cout<<"------------------------------------------------"<<std::endl;
    
    auto found = s.find(112); //checks for element in the set and returns a iterator
    //check wheather the iterator is at the end or not. If its not at the end then the element was found
    if(found != s.end()){
        std::cout<<"Found: " << *found << std::endl; 
    }

    found = s.find(200);
    if(found == s.end()) std::cout<< "Element 200 not present in the set" << std::endl;

    s.erase(9); //erase from the set
    printData(s);
    std::cout << "Size of set object: " << sizeof(s) << std::endl; //returns the size of a set object
    std::cout << "Number of elements in set s: " << s.size() << std::endl; //returns the number of element in the set

    std::cout<<"------------------------------------------------"<<std::endl;

    //ranges in set
    std::set<int> s2{4, 8, 12, 16, 20, 24, 28, 32};

    //lower_bound and upper_bound returns iterators to the specific elements of the set
    auto lower = s2.lower_bound(12);
    auto higher = s2.upper_bound(28);

    //traverse elements inside of the range
    for(std::set<int>::iterator it = lower; it != higher; it++){ 
        std::cout<< *it << " "; 
    }
    std::cout<<std::endl;

    //erasing everything in the range
    std::cout<<"before erasing: ";
    printData(s2);
    std::cout<<"after erasing: ";
    s2.erase(lower, higher);
    printData(s2);

    //merge 2 sets into 1 (set s2 becomes empty !)
    s.merge(s2);
    std::cout<<"Merged set: ";
    printData(s); 

    std::cout<<"------------------------------------------------"<<std::endl;

    //set with custom data type and comparator
    std::set<vertex, compareVertex> s3;
    vertex v1(6);
    vertex v2(8);

    s3.insert(v1);
    s3.insert(v2);

    for(auto element : s3){
        std::cout << element._vertex << " ";
    }
    std::cout<<std::endl;
    return 0;
}