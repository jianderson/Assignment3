
#include <iostream>

using namespace std;
template <class T>
class GenStack
{
    public:
        GenStack()
        {
            myArray = new T[50];
            size = 50;
            top = -1;

        } //constructor
        GenStack(int maxSize)
        {
            if(maxSize < 1)
                throw runtime_error("Your max size was not right.");

            myArray = new T[maxSize];
            size = maxSize;
            top = -1;
        }

     //overloaded constructure
        ~GenStack()
        {
            //delete [] myArray;
        } //destructor

        void push(T d)
        {
            if(isFull())
            //     throw runtime_error("The stack is full. You can't add anything else.");
                DoubleArraySize();
            //else
            myArray[++top] = d;
        }
        T pop()
        {
            if(isEmpty())
                throw runtime_error("The stack is empty. There are no values to pop.");
            else
                return myArray[top--];
        }
        T peek()
        {
            //peek to the top of the stack
            if(isFull())
                throw runtime_error("The stack is empty. There are no values to peek.");
            else
                return myArray[top];
        }

        bool isFull()
        {
            return (top == size-1);
        }
        bool isEmpty()
        {
            return (top == -1);
        }

        int size;
        int top;

        T *myArray; //pointer is a memory address/ when we do initialize it, it will point to the first address of that array
        //later initialize it to an Array
        //when you want to do it at run time from input
//method to double the array size
        void DoubleArraySize()
        {
            T *newArray;
            //create a new array
            newArray = new T[size * 2];
            //populate it with the old information
            for(int i = 0; i < size; ++i)
            {
                newArray[i] = myArray[i];
            }
            //delete old array
            delete [] myArray;
            size = size*2;
            //set old array equal to the new array
            myArray = newArray;

        }

};
