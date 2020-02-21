#include <iostream>
#include<time.h>
#include<cstdlib>
#include<conio.h>
#include "Heap.cpp"

using namespace std;

int main(int argc, char** argv)
{
	int menu=999, tmp;
	Heap heap;
	srand(time(NULL));
	
	
	heap.fileInput();
	
	while(1)
	{
		cout << "Wybierz funkcje:" << endl;
        cout << "1. Dodaj element" << endl;
        cout << "2. Usun element" << endl;
        cout << "3. Czy zawiera" << endl;
        cout << "4. Wyswietl kopiec" << endl;
        cout << "5. Wyczysc kopiec" << endl;
        cin>>menu;
        system("cls");
        
        switch(menu)
        {
        	case 5:
        		heap.clearHeap();
        		system("cls");
				break;
			case 1:
				cout<<"Podaj wartosc"<<endl;
				cin>>tmp;
				heap.push(tmp);
				getch();
				system("cls");
				break;
			case 2:
				cout<<"Podaj wartosc"<<endl;
				cin>>tmp;
				heap.pop(tmp);
				getch();
				system("cls");
				break;
			case 3:
				cout<<"Podaj wartosc"<<endl;
				cin>>tmp;
				heap.contains(tmp);
				getch();
				system("cls");
				break;
			case 4:
				heap.print();
				getch();
				system("cls");
				break;
			
		}
	}
	
	
	
	return 0;
}