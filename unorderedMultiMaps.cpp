#include<iostream>
#include "printData.h"
#include<string>
#include<unordered_map>

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

typedef struct hashVertex{

    //custom hash function to hash vertex objects(as key).
    //The purpose of hashing is to get random and unique numbers, based on which we can put elements into different buckets.
    std::size_t operator()(const Vertex& v) const noexcept{
        return (v._v1 * 32) + v._v2; 
    }

}hashVertex;

int main(){
    
    std::unordered_multimap<std::string, int> m = {{"Orange", 15}, {"Apple", 17}, {"Banana", 12}};
    //Similar to unordered Maps, the key value pairs are not sorted and is implemented as a hash table.
    //But unlike unordered Maps, it allows key value pairs with duplicate keys. Therefore we cannot use the [] operator !

    //insert and element into the map
    m.insert(std::pair("Guava", 98));
    m.insert({"Strawberry", 50});
    m.insert({"Strawberry", 50}); //inserting duplicate key
    m.insert({"Strawberry", 50});
    printMapData(m);

    std::cout<<"------------------------------------------------"<<std::endl;

    //removing elements from the map
    m.erase("Strawberry"); //using the key  //erasing using the key will erase every instance of it  
    m.erase(m.begin()); //using an iterator
    std::cout << "Map after erasing the elements : " << std::endl;
    printMapData(m);

    std::cout<<"------------------------------------------------"<<std::endl;

    std::cout<< "Number of key-value pairs present inside multimap: "<< m.size() << std::endl; //returns the number of elements inside the map
    std::cout<< "Size of an unordered_multimap object: "<< sizeof(m) << std::endl; //returns the actual size of the unordered_map object
    std::cout<< "Load factor: "<< m.load_factor() << std::endl; //prints the load factor. If the load factor exceeds 1 then more buckets will be allocated.

    std::cout<< "Bucket Count for map m: "<< m.bucket_count() << std::endl; //returns the bucket count
    std::cout<< "Bucket for Orange: "<< m.bucket("Orange") << std::endl; //returns the bucket count for the element
    std::cout<< "Bucket for Banana: "<< m.bucket("Banana") << std::endl; //returns the bucket count for the element
    std::cout<< "Bucket for Guava: "<< m.bucket("Guava") << std::endl; //returns the bucket count for the element

    std::cout<<"------------------------------------------------"<<std::endl;

    //Unordered multimaps using custom dataType
    std::unordered_multimap<vertex, std::string, hashVertex> m2;
    m2.insert({vertex(3, 4), "Vertex One"});
    m2.insert({vertex(7, 8), "Vertex Two"});
    m2.insert({vertex(7, 8), "Vertex Three"}); //inserting duplicate key
    m2.insert({vertex(9, 5), "Vertex Four"});
    m2.insert({vertex(3, 4), "Vertex Five"}); //inserting duplicate key

    for(const auto& [key, value] : m2){
        std::cout << "(" << key._v1 << ", " << key._v2 << "), " << value << std::endl;
    }

    std::cout << "Bucket Count for map m2: " << m2.bucket_count() << std::endl;
    std::cout << "Load factor for map m2: " << m2.load_factor() << std::endl;

    return 0;
}