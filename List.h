#ifndef LIST_H
#define LIST_H

#include "ListElement.h"

class List 
{
private:
	unsigned int size;
	
	ListElement *head;
    ListElement *tail;
    
public:

    

    List();
    ~List();
    
    void pushFront(int value);

    void pushBack(int value);
    
    void push(int value, int valueBefore);

    void popFront();

    void popBack();

    void pop(int value);

    bool contains(int value);
    
    void print();
    
    void clearList();
    
    void fileInput();
    
    ListElement* find(int value);
};

#endif 
