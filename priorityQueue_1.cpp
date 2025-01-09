#include <iostream>
#include <queue>

void printPriorityQueue(std::priority_queue<int> &p_queue){
    while (!p_queue.empty()){
        int top = p_queue.top();
        std::cout << top << " ";
        p_queue.pop();
    }

    std::cout << std::endl;
}

int main(){

    std::priority_queue<int> p_queue;
    // Similar to stack and queue, priority queue is also a container adaptor. By default its implemented using std::vector as its container.
    // Its similar to a normal std::queue but sorts the elements depending on the configuration, by default its implemented as max heap, meaning the larget element is at the top.
    // Heap here is referred to the structure and not the memory part. Heap structure is a tree based structure that satisfies a certain order property.
    // It also follows FIFO method [ First In First Out ];

    p_queue.push(6);
    p_queue.push(76);
    p_queue.push(8);

    // sorts the elements in max heap property, i.e. the maximum number will be the top.
    printPriorityQueue(p_queue);
    return 0;
}