#include <iostream>
#include <fstream>
#include "List.h"
#include "ListElement.cpp"

using namespace std;

//Konstruktor
List::List() 
{

    head=NULL;
    tail=NULL;
    size=0;

}

//Destruktor
List::~List() 
{
	clearList();
}

void List::clearList()
{
	ListElement* tmp;
    for (unsigned int i = 0; i < size; i++) 
	{

        tmp = head->next;
        delete head;

        head = tmp;
    }
    head=NULL;
    tail=NULL;
    
    size=0;

}

void List::fileInput()
{
	clearList();
	
	int number, quantity;
	ifstream file("Input.txt");
	
	if(file.is_open())
	{
		file>>quantity;
		for(int i=0;i<quantity;i++)
		{
			file>>number;
			pushBack(number);
		}
		file.close();
	}
	else 
		cout<<"Blad otwarcia pliku Input.txt"<<endl;

}


void List::pushFront(int value) 
{

    ListElement* elem = new ListElement(value,NULL,NULL);


	//Sprawdza, czy lista nie jest pusta
    if(head==NULL)
    {
        head=elem;
        tail=elem;

    }
    else
    {
    	//"Podpina" nowy element z przodu
    	head->previous=elem;
    	elem->previous=NULL;
    	elem->next=head;
	    head=elem;
    }
    
    size++;

}

void List::pushBack(int value) 
{
     ListElement *elem=new ListElement(value,NULL,NULL);

	//Sprawdza, czy lista nie jest pusta
    if(tail==NULL)
    {
        head=elem;
        tail=elem;

    }
    else
    {
    	//"Podpina" nowy element z tylu
    	elem->next=NULL;
    	tail->next=elem;
    	elem->previous=tail;
    	tail=elem;
    }
    
    size++;
}

void List::push(int value, int valueBefore)
 {
 	
	 ListElement* elBefore=find(valueBefore);

    
    if (elBefore==NULL) 							//Sprawdza czy wartosc valueBefore jest na liscie
	{	
        pushFront(value);
    }
    else if(elBefore->next==NULL)					//Sprawdza, czy lista nie jest pusta
	{
		pushBack(value);
	}
    else											//Jesli tak "wpina" nowy element miedzy elementy after i before
	{
		
		ListElement* elAfter=elBefore->next;

        ListElement *newElement= new ListElement();

        elBefore->next=newElement;
        elAfter->previous=newElement;
        
        
        newElement->value=value;
        newElement->previous=elBefore;
        newElement->next=elAfter;
		
		size++;
        	
	}
}
	
//Wypisywanie elementow
void List::print() 
{
	if(size==0)
		cout<<"Lista jest pusta!"<<endl;
	else 
	{
		
	ListElement* tmp = head;

    	for (unsigned int i = 0; i < size; i++) 
		{

        	cout << "List [" << i << "] = " << tmp->value << endl;

        	tmp = tmp->next;

    	}
		
	}

    
}
void List::popFront()
{

	if(size==0)										//Sprawdza, czy lista nie jest pusta
		cout<<"Lista jest pusta! "<<endl;
	else if(size==1)								//Jesli usuwany jest ostanti element lista musi byc odpowienio zakonczona
	{
		tail=NULL;
		head=NULL;
		size=0;
	}
	else
	{
		ListElement* tmp= head->next;
		tmp->previous=NULL;
		delete head;
		head=tmp;
		size--;
	}
	
}

void List::popBack()
{
	
	if(size==0)								//Sprawdza, czy lista nie jest pusta
		cout<<"Lista jest pusta! "<<endl;
	else if(size==1)						//Jesli usuwany jest ostanti element lista musi byc odpowienio zakonczona
	{
		tail=NULL;
		head=NULL;
		size=0;
	}
	else
	{
		ListElement* tmp= tail->previous;
		tmp->next=NULL;
		delete tail;
		tail=tmp;
		size--;
	}
}

//Usuwanie elementu po wartosci
void List::pop(int value)
{
	ListElement* element = find(value);
	if(element==NULL)
	{
		cout<<"Podana wartosc nie znajduje sie w liscie. "<<endl;
	}
	else if(element->next==NULL)		//Wykorzystnie juz gotowych funkcji 
	{
		popBack();
	}
	else if(element->previous==NULL)	//Wykorzystnie juz gotowych funkcji 
	{
		popFront();
	}
	else
	{
		ListElement* next=element->next;
		ListElement* previous = element->previous;
		
		previous->next=next;
		next->previous=previous;
		delete element;
		size--;
	}
}

//Funkcja zwraca wskaznik na element o podanej wartosci
ListElement* List::find(int value)
{
	ListElement* tmp = head;
	
	for (unsigned int i = 0; i < size; i++) 
	{

        if(tmp->value==value)
		{
			return tmp;
		}

        tmp = tmp->next;

    }
return NULL;
}

//Funkcja zwraca informacje, czy podana wratosc znajduje sie w liscie
bool List::contains(int value)
{
	ListElement* tmp = head;
	
	for (unsigned int i = 0; i < size; i++) 
	{

        if(tmp->value==value)
		{
			cout<<"Podana wartosc znajduje sie w liscie. "<<endl;
			return true;
		}

        tmp = tmp->next;

    }
	cout<<"Podana wartosc nie znajduje sie w liscie. "<<endl;
return false;
}



