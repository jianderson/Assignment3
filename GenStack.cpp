//implementation file
//
// #include "GenStack.h"
// #include <iostream>
//
// using namespace std;
//
//
//
// GenStack::GenStack()
// {
//     myArray = new T[128];
//     size = 128;
//     top = -1;
//
// }
//
// GenStack::GenStack(int maxSize)
// {
//     myArray = new T[maxSize];
//     size = maxSize;
//     top = -1;
// }
//
// GenStack::~GenStack()
// {
//     delete [] myArray;
//     //figure it out delete`
// }
//
// void GenStack::push(T d)
// {
//     if(myArray.isFull())
//         cout << "Couldn't push " << d << " to the stack because it is full." << endl;
//     else
//         myArray[++top] = d;
// }
//
// T GenStack::pop()
// {
//     //returns and removes
//     //error checking make sure its not isEmpty
//     return myArray[top--];
// }
//
//
// T GenStack::peek()
// {
//     //just returns does not remove
//     //check if isEmpty
//     return myArray[top];
// }
//
// bool GenStack::isFull()
// {
//     return (top == size-1);
// }
//
// bool GenStack::isEmpty()
// {
//     return (top == -1);
// }
