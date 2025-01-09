#include<iostream>

class functor{
    int x, y;

    public: 
    
    //constructors
    functor() : x(0), y(0) {}
    functor(int _x, int _y) : x(_x), y(_y) {}

    //getters
    int getX() const{ return this->x; }
    int getY() const{ return this->y; }

    //overloading the () operator to use it as a functor
    functor operator()(const functor& obj){
        functor f;
        f.x = x * obj.x;
        f.y = y * obj.y;

        return f;
    }
};

//overloading the << operator to log functor type object
std::ostream& operator<<(std::ostream& stream, functor& object){
    stream << object.getX() << ", " << object.getY() << std::endl;
    return stream;
}

int main(){
    
    //functors are function objects...functions wrapped inside of an object, let be a class or struct
    //functors allows us to use objects as functions.
    //This is necssary as it can retain object states unlike normal functions that go out of scope once reached the end.

    functor object1(3, 5);
    functor object2(7, 10);

    //using a functor i can retain the values of object1 and then use object1 as a function passing object2 as a argument. 
    functor result = object1(object2);

    std::cout<< result << std::endl;

    return 0;
}