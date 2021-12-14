#ifndef PROJEC_STACK_CPP
#define PROJEC_STACK_CPP
#include "Stack.h"

template<class T>
Stack<T>::Stack(){}

template <class T>
void Stack<T>::push(T item)
{
    list.push_back(item);
}

template <class T>
void Stack<T>::pop()
{
    list.removeLastNode();
}

template <class T>
T Stack<T>::getTop()
{
    return list.getLastNode();
}
#endif
