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
    std::unordered_map<std::string, int> m = {{"Orange", 15}, {"Apple", 17}, {"Banana", 12}};
    //Similar to normal maps unordered maps too store elements in key value pairs but
    //Its not ordered hence no need for a comparator. Elements inserted into an unordered map is not sorted !
    //Since its unordered the avg time complexities are constant. Its implemented using a hash table.
    //Its elements are organized into "buckets". Each element's key is hashed using a hash function and based on the hash value they are placed into corresponding buckets.
    //Keys with the same hash code appear in the same bucket.
    //The bucket array is a list of pointer, pointing to the memory location to the elements, meanwhile the elements itself maybe connected using linked lists or dynamic arrays.

    //insert and element into the map
    m.insert(std::pair("Guava", 98));
    m.insert({"Strawberry", 50});
    m["Peach"] = 69; //inserts element if not present
    printMapData(m);

    std::cout<<"------------------------------------------------"<<std::endl;

    //removing elements from the map
    m.erase("Apple"); //using the key  
    m.erase(m.begin()); //using an iterator
    std::cout << "Map after erasing the elements : " << std::endl;
    printMapData(m);

    std::cout<<"------------------------------------------------"<<std::endl;

    std::cout<< "Number of key-value pairs present inside map: "<< m.size() << std::endl; //returns the number of elements inside the map
    std::cout<< "Size of an unordered_map object: "<< sizeof(m) << std::endl; //returns the actual size of the unordered_map object
    std::cout<< "Load factor: "<< m.load_factor() << std::endl; //prints the load factor. If the load factor exceeds 1 then more buckets will be allocated.

    std::cout<< "Bucket Count for map m: "<< m.bucket_count() << std::endl; //returns the bucket count
    std::cout<< "Bucket for Strawberry: "<< m.bucket("Strawberry") << std::endl; //returns the bucket count for the element
    std::cout<< "Bucket for Orange: "<< m.bucket("Orange") << std::endl; //returns the bucket count for the element
    std::cout<< "Bucket for Banana: "<< m.bucket("Banana") << std::endl; //returns the bucket count for the element
    std::cout<< "Bucket for Guava: "<< m.bucket("Guava") << std::endl; //returns the bucket count for the element

    std::cout<<"------------------------------------------------"<<std::endl;

    std::cout<<"Elements in Map with Address: " << std::endl;
    printMapData_WithAddress(m);

    //Map with custom DataType

    std::unordered_map<vertex, std::string, hashVertex> m2;
    m2[vertex(3, 4)] = "Vertex One";
    m2[vertex(7, 8)] = "Vertex Two";
    m2[vertex(1, 2)] = "Vertex Three";
    m2[vertex(7, 8)] = "Vertex Four"; //trying to enter element with duplicate key.(WILL NOT BE INSERTED)

    for(const auto& [key, value] : m2){
        std::cout << "(" << key._v1 << ", " << key._v2 << "), " << value << std::endl;
    }

    std::cout << "Bucket Count for map m2: " << m2.bucket_count() << std::endl;
    std::cout << "Load factor for map m2: " << m2.load_factor() << std::endl;

    return 0;
}