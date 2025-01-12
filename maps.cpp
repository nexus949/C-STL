#include<iostream>
#include "printData.h"
#include<string>
#include<map>

typedef struct studentMarks{
    int s_marks;
    std::string s_name;

    //constructors
    studentMarks() : s_marks(0), s_name("Unknown") {}
    studentMarks(std::string _name, int _marks) : s_marks(_marks), s_name(_name) {}

}marks;

typedef struct compareMarks{
    bool operator()(const marks& m1, const marks& m2) const{
        return m1.s_marks < m2.s_marks;
    }
}compareMarks;

int main(){
    std::map<std::string, int> m;
    //std::maps store values in a key value pair. Its an ordered container therefore its implemented as a red black tree.
    //Therefore the time complexities are logrithmic.
    //std::maps use std::pair to store data.

    m["Orange"] = 5;
    m["Banana"] = 7;
    m["Mango"] = 9;

    //insert into map
    m.insert({"Peach", 15});
    m.insert(std::pair("Apple", 10));

    printMapData(m);
    // printMapData_WithAddress(m);
    
    std::cout << "Number of key value pairs present : " << m.size() << std::endl;  //returns the number of key value pairs present in the map.
    std::cout << "Size of a map object : " << sizeof(m) << std::endl; //returns the size of a map object.

    std::cout<<"------------------------------------------------"<<std::endl;

    //remove a pair from the map
    m.erase("Apple");
    printMapData(m);

    std::cout<<"------------------------------------------------"<<std::endl;

    //Using custom comparator in maps
    std::map<marks, char, compareMarks> m_marks;
    marks m1("John Cena", 45);
    marks m2("AJ Styles", 33);

    m_marks.insert({m1, 'A'});
    m_marks.insert({m2, 'B'});
    
    //print map using structured binding
    // for(const auto& [key, value] : m_marks){
    //     std::cout << "Name: " <<key.s_name << ", Marks: " << key.s_marks << ", Grade: "<< value << std::endl;
    // }

    for(const auto& el: m_marks){
        std::cout << "Name: " << el.first.s_name << ", Marks: " << el.first.s_marks << ", Grade: "<< el.second << std::endl;
    }
    return 0;
}