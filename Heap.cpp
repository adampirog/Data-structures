#include<iostream>
#include<climits>
#include<fstream>

#include "Heap.h"
using namespace std;


//Konstruktor, destruktor
Heap::Heap()
{
	values=NULL;
	size=0;
}

Heap::~Heap()
{
	clearHeap();
}

void Heap::clearHeap()
{
	if(values!=NULL)
	{
		delete[] values;
		values=NULL;
			
	}
	size=0;
}

void Heap::fileInput()
{
	clearHeap();
	
	int number, quantity;
	ifstream file("Input.txt");
	
	if(file.is_open())
	{
		file>>quantity;
		for(int i=0;i<quantity;i++)
		{
			file>>number;
			push(number);
		}
		file.close();
	}
	else 
		cout<<"Blad otwarcia pliku Input.txt"<<endl;

}


//Prywatne metody pomocnicze do zachowania struktury kopca
void Heap::swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y=tmp;
}

unsigned int Heap::left(int index)
{
	return (2*index+1);
}

unsigned int Heap::right(int index)
{
	return (2*index + 2);
}

unsigned int Heap::parent(int index)
{
	return (index-1)/2;
}

void Heap::heapify(unsigned int index)
{
	unsigned int l=left(index);
	unsigned int r=right(index);
	unsigned int smallest =index;
	
	if(l < size && values[l] < values[index])
		smallest = l;
	if(r < size && values[r] < values[smallest])
		smallest = r;
	if(smallest != index)
	{
		swap(&values[index], &values[smallest]);
		heapify(smallest);
	}
}


void Heap::extractRoot()
{
	if(values==NULL || size==0)
		cout<<"Kopiec jest pusty!"<<endl;
	else if(size==1)
	{
		clearHeap();
	}
	else
	{
		//Funkcja przypisuje ostatni element jako korzen 
			values[0]=values[size-1];
			size--;
			int* newValues = new int [size];
	
			for (unsigned int i = 0; i < size; i++) 
			{
            	newValues[i] = values[i];
        	}
        
        	delete[]values;
        	values = newValues;
        
        
        	heapify(0);
	}
	
}

void Heap::decreaseKey(int value)
{
	unsigned int index=0;
	
	for(unsigned i=0;i<size;i++)
	{
		if(values[i]==value)
		{
			index=i;
			values[index]=INT_MIN;
			
			while(index!=0 && values[parent(index)] > values[index])
			{
				swap(&values[index], &values[parent(index)]);
				index=parent(index);
			}
			
			return;
		}
	}
	
	cout<<"Podana wartosc nie znajudje sie w kopcu!"<<endl;
	
}




//Publiczne metody do obslugi kopca
void Heap::push(int value)
{
	int* newValues = new int [size+1];
	
	
	for (unsigned int i = 0; i < size; i++) 
		{
            newValues[i] = values[i];
        }

        //Dodanie wybranej wartosci na koniec kopca
        newValues[size] = value;
        unsigned int i=size;

		//Usuniecie starej tablicy, zmiana atrybutow
		if(values!=NULL)
        	delete[]values;
        
        values = newValues;
        size++;
        
        //Sprawdzenie struktury kopca
        while(i != 0 && values[parent(i)] > values[i])
		{
			swap(&values[i], &values[parent(i)]);
			i=parent(i);
		}
}

bool Heap::contains(int value)
{
	for(unsigned int i =0;i<size;i++)
	{
		if(values[i]==value)
		{
			cout<<"Kopec zawiera podany element"<<endl;
			return true;
		}
		
	}
cout<<"Kopec nie zawiera podanego element"<<endl;
return false;
}


void Heap::pop(int value)
{
	//Najpierw wartosc wezla jest obnizana do min - by stal sie korzeniem
	//Nastepnie ten korzen jest usuwany
	
	decreaseKey(value);
	extractRoot();
}


//Wyswietlanie kopca poziomami
void Heap::print()  
{  
	if(values==NULL || size==0)
		cout<<"Kopiec jest pusty!"<<endl;
	else
	{
		unsigned int elements=1;
    	unsigned int newline=0;
    	for(unsigned int i=0; i<size;i++)
    	{
        	cout<<values[i]<<" ";
        	if(i==newline)
        	{
            	cout<<endl;
            	elements*=2;
            	newline+=elements;
        	}
    	}
 	
	}
    
}

//Prostsza metoda wyswietlania - pokazuje tablice
/*
void Heap::print()
{
	 if (values != NULL) 
	 {
        for (unsigned int i = 0; i < size; i++) 
		{
            cout << " Heap [" << i << "]=  " << values[i] << endl;
        }
    } 
	else 
	{
        cout << "Kopiec jest pusty! " << endl;
    }

}
*/