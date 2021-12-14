
#ifndef SFML_PROJECT_STACK_H
#define SFML_PROJECT_STACK_H
#include "LinkedList.h"


template<class T>
class Stack {

private:
    LinkedList<T> list;
public:
    Stack<T>();
    void push(T item);
    void pop();
    T getTop();
};
#include"Stack.cpp"
#endif //SFML_PROJECT_STACK_H
