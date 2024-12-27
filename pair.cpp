#include <iostream>
#include <string>

int main(){

    // pair contains 2 element of either type (a, a) or (a, b)
    std::pair<int, int> p = {1, 3};

    std::cout << p.first << " ";        // access first element by using pair.first
    std::cout << p.second << std::endl; // access second element by using pair.second

    // pair in a pair (nested pairs)
    std::pair<int, std::pair<char, std::string>> p2 = {1, {'f', "Potato"}};
    std::cout << p2.first << " "; // access first element by using pair.first

    // if the second or first element in a pair is a pair then we need to access them by using ->
    std::cout << p2.second.first << " ";
    std::cout << p2.second.second << std::endl;

    // size of pairs
    std::cout << "size of pair p: " << sizeof(p) << std::endl;
    std::cout << "size of pair p2: " << sizeof(p2) << std::endl;

    return 0;
}