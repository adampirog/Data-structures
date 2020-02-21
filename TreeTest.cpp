#include<iostream>
#include "RBT.cpp"
#include<cstdlib>
#include<conio.h>

using namespace std;

int main(int argc, char** argv)
{
	int menu=999,tmp;
	
	RBT tree;
	
	
	tree.fileInput();
	
	while(1)
	{
		cout << "Wybierz funkcje:" << endl;
        cout << "1. Dodaj element" << endl;
        cout << "2. Usun element" << endl;
        cout << "3. Czy zawiera" << endl;
        cout << "4. Wyswietl drzewo" << endl;
        cout << "5. Wyczysc drzewo" << endl;
        cin>>menu;
        system("cls");
        switch(menu)
        {
        	case 5:
        		tree.clearRBT();
        		system("cls");
				break;
			case 1:
				cout<<"Podaj wartosc"<<endl;
				cin>>tmp;
				tree.push(tmp);
				getch();
				system("cls");
				break;
			case 2:
				cout<<"Podaj wartosc"<<endl;
				cin>>tmp;
				tree.pop(tmp);
				getch();
				system("cls");
				break;
			case 3:
				cout<<"Podaj wartosc"<<endl;
				cin>>tmp;
				tree.contains(tmp);
				getch();
				system("cls");
				break;
			case 4:
				tree.print();
				getch();
				system("cls");
				break;
			
		}
	}
	
	
	
	
	return 0;
}