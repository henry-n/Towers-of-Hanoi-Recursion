#ifndef MYSTACK_H
#define MYSTACK_H

//***************************************//
//static stack template                  //
//finish all functions                   //
//***************************************//

#include <iostream>
#include "towers.h"
using namespace std;

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int numElem;		//index of the top element in the stack array

public:
   // Constructor
   MyStack(int);	//pass in an int: tells the maximum size of the stack

   // Copy constructor
   MyStack(const MyStack &);

   //operator= overloading
   MyStack& operator=(const MyStack &);//copy assignment

   // Destructor
   ~MyStack();

   // Stack operations
   void push(T);	//add an item to the stack by passing in a value
   T pop();	//pop a value out by returning the value
   T top();	//return the value at the top position in the stack
   bool isFull() const;	//tell if the stack is full
   bool isEmpty() const;	//tell if the stack is empty
   int size() const;	//tell how many items are in the stack
};


//YOUR CODE
//......

template <class T>
bool MyStack<T>::isFull() const
{
   bool status;

   if (numElem == stackSize - 1)
      status = true;
   else
      status = false;

   return status;
}

template<class T>
bool MyStack<T>::isEmpty() const
{
   bool status;

   if (numElem == -1)
      status = true;
   else
      status = false;

   return status;
}

template <class T>
MyStack<T>::~MyStack()
{
    delete [] stackArray;
}

template<class T>
MyStack<T>::MyStack(int size)
{
    stackSize = size;
    stackArray = new int[stackSize];
    numElem = -1;

}


template <class T>
int MyStack<T>::size() const
{
    if (numElem == -1)
        return 0;
    else
        return (numElem+1);
}

template <class T>
MyStack<T>::MyStack(const MyStack &obj)
{
    if(obj.stackSize > 0)
        {
            stackArray = new T[obj.stackSize];
        }
    else
        stackArray = nullptr;

    stackSize = obj.stackSize;

    for(int i = 0; i < stackSize; i++)
    {
        stackArray[i] = obj.stackArray[i];
    }

    numElem = obj.numElem;

}

template<class T>
MyStack<T>& MyStack<T>::operator=(const MyStack& obj)
{
    std::cout << "DONT KNOW THE FUCK THIS IS CALLED FOR\n\n";
    this-> stackSize = obj - stackSize;
    this-> numb = obj - numElem;

    return *this;
}

template<class T>
T MyStack<T>::pop()
{
    int disk;

   if (isEmpty())
   {
      //do nothing
   }
   else
   {
      disk = stackArray[numElem];
      numElem--;
      return disk;
   }
}

template<class T>
T MyStack<T>::top()
{
    if(numElem == -1)
        return NULL;
    else
        return (stackArray[numElem]);
}

template<class T>
void MyStack<T>::push(T disk)
{
   if (isFull())
   {
      //do nothing
   }
   else
   {
      numElem++;
      stackArray[numElem] = disk;
   }
}


#endif
