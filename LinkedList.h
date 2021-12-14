
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    void addFirstNode(T item);
    Node<T>* createNode(T item);

public:
    bool isEmpty();
    int size();
    int find(T item);
    void push_front(T item);
    void push_back(T item);
    void insertBefore(T before, T item);
    void insertAfter(T after, T item);
    void remove(T item);
    void removeLastNode();
    Node<T>* getLastNode();
    void removeFirstNode();
    Node<T>* getFirstNode();
    void clear();

    template <class S>
    friend ostream& operator<<(ostream& out, const LinkedList<S>& list);
    template<class S>
    friend LinkedList<S>& operator+=(LinkedList<S>& list, const S& item);
};


#endif //LINKEDLIST_LINKEDLIST_H
