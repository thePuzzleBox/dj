

#include "Queue.h"

template <class T>
Queue<T>::Queue(){}

template <class T>
void Queue<T>::push(T item)
{
    list.push_back(item);
}

template <class T>
void Queue<T>::pop()
{
    list.removeFirstNode();
}

template <class T>
T Queue<T>::getFront()
{
    list.getFirstNode();
}