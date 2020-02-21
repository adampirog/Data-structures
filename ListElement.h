#ifndef LISTELEMENT_H
#define LISTELEMENT_H


class ListElement 
{

private:
	ListElement(int, ListElement *, ListElement *);
    ListElement();
    

    ListElement *next;
    ListElement *previous;
    int value;
    
friend class List;

    
};


#endif
