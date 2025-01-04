#include<iostream>
#include<stack>
#include<vector>
#include<string>

void printStack(std::stack<int>& s){
    while(!s.empty()){
        int el = s.top();
        std::cout<< el <<" ";
        s.pop(); //removes the last element in the stack
    }

    std::cout<<std::endl;
}

int main(){
    std::stack<int> s;
    //Unlike Vector, List or array or any other container, stack is not a container.
    //Stack is a container adaptor. Its main task is to perform stack based operations i.e. push, pop or view top element of any underlying actual container.
    //By default a std::deque is implemented as the base container for std::stack
    //Stack follow the LIFO method [ Last In First Out ];

    s.push(7);    
    s.push(9);    
    s.push(11);
    printStack(s);
    
    //stack of vector
    std::stack<std::string, std::vector<std::string>> v_stack;
    v_stack.push("Hello");
    v_stack.push("World");
    std::cout<< v_stack.top() << std::endl;

    std::cout<< "Number of elements in the stack: " <<v_stack.size() << std::endl; //returns the number of elements in the stack
    std::cout<< "Size of stack: " << sizeof(v_stack) << std::endl; //returns the size of the stack object

    //type mismatch //!!! DO NOT DO THIS !!!
    //std::stack<std::string, std::vector<float>> mismatch_stack; //stack of type string but using float type vector as container
    //mismatch_stack.push("WOW"); //will throw an error because of type mismatch

    return 0;
}