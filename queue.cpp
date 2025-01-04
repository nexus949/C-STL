#include<iostream>
#include<queue>
#include<string>

void printQueue(std::queue<int>& q){
    while(!q.empty()){
        int el_front = q.front();
        int el_back = q.back();
        std::cout<< "front: " << el_front << ", back: "<< el_back << std::endl;
        q.pop();
    }

    std::cout<<std::endl;
}

int main(){
    std::queue<int> q;
    //Similar to stack, queue is not a container itself.
    //Queue is a container adaptor, which uses underlying actual containers to store elements.
    //Just like stack it uses std::deque as its base container
    //Queue follows FIFO method [ First In First Out ];

    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    printQueue(q);
    
    //queue of vector
    std::queue<float, std::vector<float>> f_queue({3.3f, 6.4f, 2.9f});
    std::cout<< "front: " << f_queue.front() << std::endl;
    std::cout<< "back: " << f_queue.back() << std::endl;

    std::cout<< "Number of elements in the queue: " << f_queue.size() <<std::endl; //returns the number of elements in the queue
    std::cout<< "size of queue: " << sizeof(f_queue) <<std::endl; //returns the size of the queue object

    //type mismatch //!!! DO NOT DO THIS !!!
    //std::queue<int, std::vector<std::string>> mismatch_queue;
    //mismatch_queue.push(5); //queue of type int but using string type vector as container; causing Type Mismatch

    return 0;
}