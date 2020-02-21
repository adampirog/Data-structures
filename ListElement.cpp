#include "ListElement.h"
#include <cstddef>

ListElement::ListElement(int val, ListElement *nxt, ListElement *prv) 
{

    ListElement::value = val;
	ListElement::next = nxt;
	ListElement::previous = prv;

}

ListElement::ListElement()
{	
		ListElement::value =0;
		ListElement::next = NULL;
		ListElement::previous = NULL;
}