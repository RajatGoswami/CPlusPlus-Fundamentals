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

        T* get(){
            return raw_ptr;
        }

    private:
        T* raw_ptr;
};

class RefCount
{
    public:
        RefCount() : counter(0) {};
        ~RefCount();

        unsigned int get() {
            return counter;
        }

        // pre-increment (++counter)
        void operator++(){
            counter++;
        }
        // pre increment (counter++)
        void operator++(int) {
            counter++;
        }

        void operator--(){
            counter--;
        }
        void operator--(int){
            counter--;
        }
    private:
        unsigned int counter;
};

template<typename T> class shared_ptr
{
    public:
        shared_ptr(T* ptr) : raw_ptr(ptr) {
            refCount = new RefCount();

            if( raw_ptr != nullptr) {
                (*refCount)++;
            }
        };

        shared_ptr(const T* ptr) {
            raw_ptr = ptr;
            refCount = ptr->refCount;
            (*refCount)++;
        }

        ~shared_ptr() {
            (*refCount)--;

            if ( refCount->get() == 0 ) {
                delete raw_ptr;
                delete refCount;
            }
        }

        T& operator*() {
            return *raw_ptr;
        }

        T* operator->() {
            return raw_ptr;
        }

    private:
        RefCount* refCount;
        T* raw_ptr;
};

int main()
{
    return 0;
}