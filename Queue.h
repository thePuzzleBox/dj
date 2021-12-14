
#ifndef SFML_PROJECT_QUEUE_H
#define SFML_PROJECT_QUEUE_H
#include "LinkedList.h"

template<class T>
class Queue {

private:
    LinkedList<T> list;
public:
    Queue();
    void push(T item);
    void pop();
    T getFront();
};


#endif //SFML_PROJECT_QUEUE_H
