#include<iostream>
#include "printData.h"
#include<string>
#include<unordered_set>

typedef struct Vertex{
    int v1, v2;

    //constructors
    Vertex() : v1(-1), v2(-1) {}
    Vertex(int _vertex1, int _vertex2) : v1(_vertex1), v2(_vertex2) {}
    
    //overload the equality operator to compare the vertex to ensure unique key entry.
    bool operator==(const Vertex& other) const{
        return (v1 == other.v1 && v2 == other.v2);
    }
}vertex;

typedef struct hashVertex{

    //custom hash function to hash vertex objects.
    //The purpose of hashing is to get random and unique numbers, based on which we can put elements into different buckets.
    std::size_t operator()(const Vertex& v) const noexcept{
        return (v.v1 * 32) + v.v2; 
    }

}hashVertex;

int main(){

    std::unordered_set<std::string> s;
    //Similar to sets, unordered sets also store elements as unique Keys. No Duplicates,
    //but unlike sets unordered set is are not ordered and hence implemented as a hash table where the key is hashed and placed into "buckets" based on the hash value.
    //Keys with similar hash values are stored into same "buckets". Therefore, the avg time complexities is constant. 

    s.insert("Banana");
    s.insert("Papaya");
    s.insert("Mango");
    printData(s);

    std::cout<< "Number of elements present in the set: " << s.size() << std::endl; //returns the number of elements present in the set
    std::cout<< "Size of unordered_set object: "<< sizeof(s) <<std::endl; //returns the size of the actual unordered_set object

    std::cout<<"------------------------------------------------"<<std::endl;

    std::cout<< "Bucket Count: " << s.bucket_count() << std::endl; //returns the bucket count
    std::cout<< "Load factor: "<< s.load_factor() << std::endl; //returns the load factor, rehashes if load factor exceeds 1
    std::cout<< "Bucket for Papaya: " << s.bucket("Papaya") << std::endl; //returns the bucket a Key is stored in
    std::cout<< "Bucket for Banana: " << s.bucket("Banana") << std::endl;
    std::cout<< "Bucket for Mango: " << s.bucket("Mango") << std::endl;
    
    s.erase("Papaya"); //erase using Key
    s.erase(s.begin()); //erase using iterator
    std::cout<< "Set after erasing elements: ";
    printData(s);

    std::cout<<"------------------------------------------------"<<std::endl;

    //Using custom DataType
    std::unordered_set<vertex, hashVertex> s2;
    s2.insert(vertex(7, 10));
    s2.insert(vertex(8, 11));

    for(const auto& el : s2){
        std::cout << el.v1 << ", " << el.v2 << std::endl;
    }
    return 0;
}