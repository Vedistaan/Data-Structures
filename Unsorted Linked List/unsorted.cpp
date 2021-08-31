#include "unsorted.h"
#include <iostream> //for using "NULL"

template <class TYPE>
unsorted <TYPE> :: unsorted() {
    list = NULL;
    index = NULL;
    length = 0;
}

template <class TYPE>
unsorted <TYPE> :: ~unsorted() {

    //clearing all the elements of the list
    Node* temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        delete temp;
    }

    //clearing all the elements of the index
    while (index != NULL) {
        temp = index;
        index = index->next;
        delete temp;
    }
    
    length = 0;
}

template <class TYPE>
bool unsorted <TYPE> :: full() {
    Node* check;

    try {
        check = new Node;
        delete check;

        return false;   //memory allocation successful == list is not full
    }
    catch (bad_alloc& e) {  //bad allocation exception
        return true;
    }
}

template <class TYPE>
bool unsorted <TYPE> :: empty() {
    return list == NULL? true : false;
}

template <class TYPE>
int unsorted <TYPE> :: size() {
    return length;
}

template <class TYPE>
bool unsorted <TYPE> :: find(TYPE n) {
    Node* box = list;
    while(box != NULL) {
        if(n == box->data)
            return true;
        else
            box = box->next;
    }
    return false;
}

template <class TYPE>
void unsorted <TYPE> :: push(TYPE n) {
    //declare a new node
    Node* box;
    box = new Node;

    //define the node
    box->data = n;
    box->next = list;

    //point the node to be the last element in the list
    list = box;

    ++length;
}

template <class TYPE>
void unsorted <TYPE> :: pop(TYPE n) {
    if(find(n)) {
        Node* temp = list;
        Node* target;

        if(n == temp->data) {
            target = temp;
            temp = temp->next;
        }
        else {
            while(!(n == temp->next->data))
                temp = temp->next;

            target = temp->next;
            temp->next = temp->next->next;

            delete target;
            --length;
        }
    }
    else {
        std::cout << "Element not found\n";
    }
}

template <class TYPE>
void unsorted <TYPE> :: reset() {
    index = NULL;
}

template <class TYPE>
void unsorted <TYPE> :: next(TYPE& n) {
    if(index == NULL) 
        index = list;
    else
        index = index->next;
    
    n = index->data;
}
