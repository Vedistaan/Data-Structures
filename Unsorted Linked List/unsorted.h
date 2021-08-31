#ifndef UNSORTED_H_INCLUDED
#define UNSORTED_H_INCLUDED

template <class TYPE>
class unsorted {
    struct Node {
        TYPE data;
        Node* next;
    };

    private:
        Node* list;
        int length;

        //for use with iteration
        Node* index;

    public:
        unsorted();
        ~unsorted();

        bool full();
        bool empty();
        int size();
        bool find(TYPE);
        void push(TYPE);
        void pop(TYPE);

        //for iteration
        void reset();
        void next(TYPE&);

        //reverses the list
        void reverse();

};

#endif
