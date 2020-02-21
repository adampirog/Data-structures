#include<iostream>
#include<conio.h>
#include<time.h>
#include<cstdlib>

#include"List.cpp"
#include"Array.cpp"
#include"Heap.cpp"
#include"RBT.cpp"
#include"StructureMenu.h"

using namespace std;

int StructureMenu::arrayMenu()
{
	int menu=999;

		cout << "      ---TABLICA---" << endl;
        cout << "1. Dodaj na poczatek" << endl;
        cout << "2. Dodaj na koniec" << endl;
        cout << "3. Dodaj w srodku" << endl;
        cout << "4. Usun pierwszy" << endl;
        cout << "5. Usun ostatni" << endl;
        cout << "6. Usun srodkowy" << endl;
        cout << "7. Wyszukaj element" << endl;
        cout << "8. Wydrukuj tablice" << endl;
        cout << "9. Wyczysc tablice"<<endl;
        cout << "10.Wypelnij z pliku"<<endl;
        cout << "0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> menu;
        
return menu;
}

int StructureMenu::listMenu()
{
	int menu=999;

		cout << "       ---LISTA---" << endl;
        cout << "1. Dodaj na poczatek" << endl;
        cout << "2. Dodaj na koniec" << endl;
        cout << "3. Dodaj za elementem" << endl;
        cout << "4. Usun pierwszy" << endl;
        cout << "5. Usun ostatni" << endl;
        cout << "6. Usun wartosc" << endl;
        cout << "7. Wyszukaj element" << endl;
        cout << "8. Wydrukuj liste" << endl;
        cout << "9. Wyczysc liste"<<endl;
		cout << "10.Wypelnij z pliku"<<endl;
        cout << "0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> menu;
        
return menu;
}

int StructureMenu::heapMenu()
{
		int menu=999;
	
		cout << "      ---KOPIEC---" << endl;
        cout << "1. Dodaj element" << endl;
        cout << "2. Usun element" << endl;
        cout << "3. Wyszukaj element" << endl;
        cout << "4. Wyswietl kopiec" << endl;
        cout << "5. Wyczysc kopiec" << endl;
		cout << "6. Wypelnij z pliku"<<endl;
        cout << "0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin>>menu;
return menu;
}

int StructureMenu::RBTMenu()
{
		int menu=999;
	
		cout << " DRZEWO CZERWONO - CZARNE" << endl;
        cout << "1. Dodaj element" << endl;
        cout << "2. Usun element" << endl;
        cout << "3. Wyszukaj element" << endl;
        cout << "4. Wyswietl drzewo" << endl;
        cout << "5. Wyczysc drzewo" << endl;
        cout << "6. Wypelnij z pliku"<<endl;
        cout << "0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin>>menu;
return menu;
}

int StructureMenu::mainMenu()
{
		int menu=999;
		cout << "-------MENU GLOWNE-------"<<endl;
		cout << "Wybierz strukture:" << endl;
        cout << "1. Tablica" << endl;
        cout << "2. Lista" << endl;
        cout << "3. Kopiec" << endl;
        cout << "4. Drzewo czerwono - czarne" << endl;
        cout << "0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin>>menu;
        
return menu;
}
		