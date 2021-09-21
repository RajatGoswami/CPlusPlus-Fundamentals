// Implementing smart pointers in C++
#include<iostream>

template<typename T> class uniq_ptr
{
    public:
        // The unique ptr must always be initialized 
        // with a raw pointer upon constructions
        uniq_ptr(T * ptr) : raw_ptr(ptr) {};

        ~uniq_ptr() {
            // raw_ptr deleted once the object 
            // is out of scope
            delete raw_ptr;
        }

        T& operator*(){
            return *raw_ptr;
        }

        T* operator->(){
            return raw_ptr;
        }

    private:
        T* raw_ptr;
};

int main()
{
    return 0;
}