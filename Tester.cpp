#include<iostream>
#include<conio.h>
#include<cstdlib>
#include "Timer.cpp"
#include "List.cpp"
#include "Array.cpp"


using namespace std;

int main(int argc, char** argv)
{
	Timer timer;
	List struktura;
	int menu =999, value, position;
	
	struktura.fileInput();
	
	while(1)
	{
		cout << "Wybierz funkcje:" << endl;
        cout << "1. Dodaj na poczatek" << endl;
        cout << "2. Dodaj na koniec" << endl;
        cout << "3. Dodaj w srodku" << endl;
        cout << "4. Usun pierwszy" << endl;
        cout << "5. Usun ostatni" << endl;
        cout << "6. Usun w srodku" << endl;
        cout << "7. Wyszukaj element" << endl;
        cout << "8. Wydrukuj " << endl;
        cout << "9. Wyczysc "<<endl;
        cout << "0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> menu;
        
        switch(menu)
        {
        case 9:
			struktura.clearList();
			system("CLS");
        	break;
  	    case 1:
        	cout<<"Wartosc : ";
        	cin>>value;
        	struktura.pushFront(value);
        	getch();
        	system("CLS");
        	break;
        
        case 2:
        	cout<<"Wartosc : ";
        	cin>>value;
        	struktura.pushBack(value);
        	getch();
        	system("CLS");
        	break;
        
        case 3:
        	cout<<"Wartosc : ";
        	cin>>value;
        	cout<<"Pozycja: ";
        	cin>>position;
        	struktura.push(value,position);
        	getch();
        	system("CLS");
        	break;
        
        case 4:
        	struktura.popFront();
        	getch();
        	system("CLS");
        	break;
        
        case 5:
        	struktura.popBack();
        	getch();
        	system("CLS");
        	break;
        
        case 6:
        	cout<<"Pozycja : ";
        	cin>>position;
        	struktura.pop(position);
        	getch();
        	system("CLS");
        	break;
        
        case 7:
        	cout<<"Wartosc : ";
        	cin>>value;
        	struktura.contains(value);
        	getch();
        	system("CLS");
        	break;
        
        case 8:
        	struktura.print();
        	getch();
        	system("CLS");
        	break;	
		}	
        
        
	}
	return 0;
}