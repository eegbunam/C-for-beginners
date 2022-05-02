#include <iostream>
#define CAPACITY 4

template<typename T> class StaticStack
{
    public:
        StaticStack()
        {
            top = -1;
        }
        int push( T data)
        {
            if( top == CAPACITY - 1)
            {
                return -1;
            }
            else
            {
                top++;
                stack[top] = data;
                return 0;
            }

        }

        T pop()
        {
            if( top == -1)
            {
                std::cout << "Stack is empty" << std::endl;
                return NULL;
            }
            else
            {
                T data = stack[top];
                top--;
                return data;
            }

        }

        void printStack()
        {
            for( int i = 0; i <= top; i++)
            {
                std::cout << stack[i] << std::endl;
            }
        }
    private:
        T stack[CAPACITY];
        int top;

};


template<typename T> class DynamicStack
{
    public:
        DynamicStack()
        {
            top = -1;
            capacity = CAPACITY;
            stack =  new T[capacity];
        }
        void increaseCapacity()
        {
            T *temp = new T[capacity * 2];
            for( int i = 0; i <= top; i++)
            {
                temp[i] = stack[i];
            }
            delete [] stack;
            stack = temp;
            capacity *= 2;

        }
        void push( T data)
        {
            if( top == capacity - 1)
            {
                increaseCapacity();    
            }
            top++;
            stack[top] = data;
            
          
        }

        T pop()
        {
            if( top == -1)
            {
                std::cout << "Stack is empty" << std::endl;
                return NULL;
            }
            else
            {
                return stack[top--];
            }

        }

        void printStack()
        {
            for( int i = 0; i <= top; i++)
            {
                std::cout << stack[i] << std::endl;
            }
            std::cout<< "Printed Stack of with capacity: " << capacity << std::endl;
        }
    private:
        T *stack;
        int top;
        int capacity;

};