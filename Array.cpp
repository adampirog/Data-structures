#include <iostream>
#include<fstream>

#include "Array.h"

using namespace std;

//Konstruktor 
Array::Array() 
{

    Array::headPointer = NULL;
    Array::size = 0;

}

//Destruktor
Array::~Array() 
{
	clearArray();
}

void Array::clearArray()
{
	if (headPointer != NULL) 
	{
        delete[]headPointer;
        headPointer = NULL;
        size=0;
    }	
}

void Array::fileInput()
{
	clearArray();
	
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

void Array::pushFront(int value) 
{

    //Tworzy nowa tablice (o 1 wieksza niz poprzednio) i dodaje element na poczatek
    
    int *newHead = new int[size + 1];
    newHead[0] = value;

    //Kopiuje dane do nowej tablicy
    for (unsigned int i = 0; i < size; i++) 
	{
        newHead[i + 1] = headPointer[i];
    }

    //Usuwa stara tablice, zmienia atrybuty obiektu
    
    delete[] headPointer;
    headPointer = newHead;

    //Zwiêksza rozmiar tablicy
    size++;

}

void Array::pushBack(int value) 
{

    //Tworzy nowa tablice (o 1 wieksza niz poprzednio) i dodaje element na koniec
    
    int *newHead = new int[size + 1];
    newHead[size] = value;

	//Kopiuje dane do nowej tablicy
    for (unsigned int i = 0; i < size; i++) 
	{
        newHead[i] = headPointer[i];
    }

    //Usuwa stara tablice, zmienia atrybuty obiektu
    
    delete[] headPointer;
    headPointer = newHead;

    //Zwiêksza rozmiar tablicy 
    size++;

}

void Array::push(int value, unsigned int position) 
{
    //SprawdŸ, czy wybrana position jest poprawna
    
    
    if (position < 0 || position > size) 
	{
        cout << "Wybrana pozycja nie jest poprawna! "<<endl;
    } 
    else if(position==0)
	{
		pushFront(value);
	}
	else if(position==size)
	{
		pushBack(value);
	}
	else 
	{

         //Tworzy nowa tablice (o 1 wieksza niz poprzednio) i dodaje element na pozycje
        int *newHead = new int[size + 1];
        newHead[position] = value;

        //Kopiuje dane do nowej tablicy (tylko do pozycji)
        for (unsigned int i = 0; i < position; i++) 
		{
            newHead[i] = headPointer[i];
        }

        //Kopiuje dane do nowej tablicy (tylko po pozycji)
        for (unsigned int i = position; i < size; i++) 
		{
            newHead[i + 1] = headPointer[i];
        }

        //Usuwa stara tablice, zmienia atrybuty obiektu
        
        delete[] headPointer;
        headPointer = newHead;

        //Zwiêksz rozmiar tablicy 
        size++;

    }
}

void Array::popBack() 
{
    //SprawdŸ, czy tablica nie jest pusta
    if (size > 0) 
	{
        //Tworzy nowa tablice (o 1 mniejsza niz poprzednio)
        int *newHead = new int[size - 1];

        //Kopiuje dane do nowej tablicy
        for (unsigned int i = 0; i < size - 1; i++) 
		{
            newHead[i] = headPointer[i];
        }

        //Usuwa stara tablice, zmienia atrybuty obiektu
        delete[] headPointer;
        headPointer = newHead;

        //Zmniejsz rozmiar tablicy
        size--;
    } 
	else 
	{
    	
        cout << "Tablica jest pusta!" << endl;
    }

}

void Array::popFront() 
{

    //SprawdŸ, czy tablica nie jest pusta
    if (size > 0) 
	{
        //Tworzy nowa tablice (o 1 mniejsza niz poprzednio)
        int *newHead = new int[size - 1];

        //Kopiuje dane do nowej tablicy
        for (unsigned int i = 0; i < size - 1; i++) {
            newHead[i] = headPointer[i + 1];
        }

        //Usuwa stara tablice, zmienia atrybuty obiektu
        delete[] headPointer;
        headPointer = newHead;

        //Zmniejsz rozmiar tablicy 
        size--;
    } 
	else 
	{
        cout << "Tablica jest pusta!" << endl;
    }

}

void Array::pop(unsigned int position) 
{

    //SprawdŸ, czy tablica nie jest pusta i czy pozycja jest poprawna
	if(size<=0)
	{
        cout << "Tablica jest pusta!"<<endl;
    }
    else if (position < 0 || position > size-1) 
	{
		cout<< "Pozycja jest niepoprawna! "<<endl;
	}
	else if(position==0)
	{
		popFront();
	}
	else if(position==size-1)
	{
		popBack();
	}
    else
	 {
        //Tworzy nowa tablice (o 1 mniejsza niz poprzednio)
        int *newHead = new int[size - 1];

        //Kopiuje dane do nowej tablicy (tylko do pozycji)
        for (unsigned int i = 0; i < position; i++) 
		{
            newHead[i] = headPointer[i];
        }

        //Kopiuje dane do nowej tablicy (tylko do pozycji)
        for (unsigned int i = position; i < size - 1; i++) 
		{
            newHead[i] = headPointer[i + 1];
        }

        //Usuwa stara tablice, zmienia atrybuty obiektu
        
        delete[] headPointer;
        headPointer = newHead;

        //Zmniejsz rozmiar tablicy
        size--;
     } 


}

bool Array::contains(int value) 
{

    //Przeszukuje tablice
    for (unsigned int i = 0; i < size; i++) 
	{
        //Znaleziono wartosc
        if (headPointer[i] == value) 
		{
            cout << "Szukana wartosc znajduje sie na pozycji: "<<i<<endl;
            return true;
        }
    }
    //Nie znaleziono wartosci
    cout << "Szukana wartosc nie zostala znaleziona " << endl;
    return false;
}

void Array::print() 
{
    
    if (size>0) 
	{
        for (unsigned int i = 0; i < size; i++) 
		{
            cout << "Array [" << i << "] =  " << headPointer[i] << endl;
        }
    } 
	else 
	{
        cout << "Tablica jest pusta! " << endl;
    }
}
