#include "StackTest.h"
#include <iostream>
int main()
{
    StaticStack<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.printStack();
    test.pop();
    test.printStack();

    std::cout << "Testing Dynamic Stack" << std::endl;

    DynamicStack<int> test2;
    test2.push(1);
    test2.push(2);
    test2.push(3);
    test2.printStack();
    test2.push(4);
    test2.push(5);
    test2.push(6);

    test2.printStack();

    test2.pop();

    test2.printStack();

    



}