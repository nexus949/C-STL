#include<iostream>
#include "printData.h"
#include<string>
#include<map>

typedef struct Vertex{
    int _v1, _v2;

    //constructors
    Vertex() : _v1(-1), _v2(-1) {}
    Vertex(int vertex1, int vertex2) : _v1(vertex1), _v2(vertex2) {}
    
    //overload the equality operator to compare the vertex to ensure unique key entry.
    bool operator==(const Vertex& other) const{
        return (_v1 == other._v1 && _v2 == other._v2);
    }
}vertex;

typedef struct compareVertex{
    
    bool operator()(const vertex& v1, const vertex& v2) const{
        int firstVertex = v1._v1 + v1._v2;
        int secondVertex = v2._v1 + v2._v2;
        return firstVertex < secondVertex;
    }

}compareVertex;

int main(){

    std::multimap<std::string, int> m;
    //Similar to map, it stores data in a key value pair and in a ordered way and is implemented as a red black tree.
    //As implemented as red black tree the time complexities are logarithmic.
    //But unlike map, this allows duplicate keys to be stored.

    //insert into map
    m.insert({"Mango", 15});
    m.insert({"Peach", 19});
    m.insert({"Mango", 15}); //inserting duplicate value
    m.insert({"Banana", 12});
    m.insert({"Guava", 17});
    m.insert({"Apple", 03});
    printMapData(m);

    std::cout<<"------------------------------------------------"<<std::endl;

    std::size_t count = m.count("Mango"); //returns the number of the particular key value present in the map.
    std::cout<< "The Number of Mango entries is: " << count << std::endl;

    //erasing key value pairs
    m.erase("Mango"); //erase using key //erasing the using duplicate keys will erase every instance of it.
    auto it = m.begin();
    m.erase(it); //erase using iterator
    std::cout<< "After erasing key value pairs : "<<std::endl;
    printMapData(m);

    std::cout<<"------------------------------------------------"<<std::endl;

    std::cout<< "Number of elements present in the multimap: " << m.size() << std::endl; //returns the number of key value pairs present in the multimap
    std::cout<< "Size of multimap object: " << sizeof(m) << std::endl; //returns the actual size of the multimap object

    std::cout<<"------------------------------------------------"<<std::endl;

    //MultiMap using custom DataType
    std::multimap<vertex, std::string, compareVertex> m2;

    m2.insert({vertex(7, 10), "Vertex One"});
    m2.insert({vertex(7, 10), "Vertex Three"}); //inserting pair with duplicate key
    m2.insert({vertex(9, 3), "Vertex Two"});

    for(const auto& [key, value] : m2){
        std::cout<< "(" << key._v1 << ", " << key._v2 << "), " << value << std::endl;
    }
    return 0;
}