
#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

template<class T>
struct Node
{
    T data;
    Node<T>* next = nullptr;
};

#endif //LINKEDLIST_NODE_H
