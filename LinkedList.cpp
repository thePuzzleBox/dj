#include "LinkedList.h"

template<class T>
int LinkedList<T>::find(T item)
{
    int index = 0;
    Node<T> * temp = head;

    while(temp!=NULL){
        if(temp->data == item){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;

}

template<class T>
bool LinkedList<T>::isEmpty()
{
    return head == nullptr;
}

template<class T>
int LinkedList<T>::size()
{
    Node<T>* temp = head;
    int count=0;
    while(temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

template<class T>
void LinkedList<T>::addFirstNode(T item)
{
    Node<T>* n = createNode(item);
    head = n;
    tail = n;

}

template<class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    Node<T>* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    return n;

}


template<class T>
void LinkedList<T>::push_front(T item)
{
    if(head == nullptr)
        addFirstNode(item);
    else
    {
        Node<T>* n = createNode(item);
        n->data = item;
        n->next = head;
        head = n;
    }
}

template<class T>
void LinkedList<T>::push_back(T item)
{
    Node<T>* n = createNode(item);

    if(head == NULL) {
        head = n;
        return;
    }
    Node<T> *curr = head;
    while(curr && curr->next)
    {
        curr = curr->next;
    }
    curr->next = n;
    tail = n;
}

template<class T>
void LinkedList<T>::insertBefore(T before, T item)
{

    if (head->data == before) {
        Node<T>* n = createNode(item);
        n->next = head;
        head = n;
    }
    else {

        Node<T> *p, *n = head;
        for (n, p; n->data != before;
            p = n, n = n->next)
            ;
        Node<T>* m = createNode(item);
        m->next = p->next;
        p->next = m;
    }
}

template<class T>
void LinkedList<T>::insertAfter(T after, T item)
{
    if(tail->data == after)
    {
        (*this).push_back(item);
    }
    else {
        Node<T>* temp = head;
        for(int i = 0; i < (*this).find(after); i++)
        {
            temp = temp->next;
            if(temp == NULL)
                return;
        }

        Node<T>* ptr = createNode(item);
        ptr->next = temp->next;
        temp ->next = ptr;
    }
}


template<class T>
void LinkedList<T>::remove(T item)
{
    Node<T>* curr = new Node<T>;
    Node<T>* prev = new Node<T>;
    curr = head;
    for(int i = 0; i < (*this).find(item); i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
}

template <class T>
void LinkedList<T>::removeLastNode()
{
    if (head == NULL){}
    else if (head->next == NULL) {
        delete head;
    }
    else
    {
        Node<T>* second_last = head;
        while (second_last->next->next != NULL)
            second_last = second_last->next;

        delete (second_last->next);
        second_last->next = NULL;
    }
}

template <class T>
Node<T>* LinkedList<T>::getLastNode()
{
    if (head == NULL)
        return NULL;

    else if (head->next == NULL)
        return head;
    else
        return tail;
}

template <class T>
void LinkedList<T>::removeFirstNode()
{
    if (head == NULL){}
    else
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

}

template <class T>
Node<T>* LinkedList<T>::getFirstNode()
{
    if (head == NULL)
        return NULL;
    else
        return head;
}

template<class T>
void LinkedList<T>::clear()
{
    Node<T>* link = NULL;
    while (head != NULL)
    {
        link = head->next;
        free(head);
        head = link;
    }
    head = NULL;
    //cout << "\nList cleared!\n";
}

template <class S>
ostream& operator<<(ostream& out, const LinkedList<S>& list)
{
    Node<S>* temp = list.head;
    while(temp != nullptr)
    {
        out << temp->data;
        temp = temp->next;
    }
    return out;
}

template <class S>
LinkedList<S>& operator+=(LinkedList<S>& list, const S& item)
{
    list.push_back(item);
    return list;
}

