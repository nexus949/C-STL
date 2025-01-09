#include <iostream>
#include <queue>
#include <vector>

//priority qeue with custom comparator

typedef struct vertex{
    int v1, v2;

    // constructors
    vertex() : v1(0), v2(0) {}
    vertex(int _v1, int _v2) : v1(_v1), v2(_v2) {}

} vertex;

//custom compareVertex functor to compare 2 vertex
typedef struct compareVertex{
    bool operator()(vertex& vertex1, vertex& vertex2){
        return (vertex1.v1 + vertex1.v2 < vertex2.v1 + vertex2.v2);
    }
}compareVertex;

void printPriorityQueue(std::priority_queue<vertex, std::vector<vertex>, compareVertex>& v_queue){
    
    while(!v_queue.empty()){
        vertex v = v_queue.top();
        std::cout << v.v1 << ", " << v.v2 << std::endl;
        v_queue.pop();
    }

    std::cout<<std::endl;
}

int main(){

    std::priority_queue<vertex, std::vector<vertex>, compareVertex> v_queue;
    vertex v1(5, 9);
    vertex v2(2, 3);

    //need to define a custom comparator to compare to vertex objects.
    v_queue.push(v1);
    v_queue.push(v2);

    printPriorityQueue(v_queue);
    return 0;
}