#include<iostream>
#include<conio.h>
#include<time.h>
#include<cstdlib>
#include"StructureMenu.cpp"

using namespace std;


int main(int argc, char** argv)
{
	
	Array array;
	List list;
	Heap heap;
	RBT tree;
	
	int menu =999,tmp1,tmp2,inner=999;
	
	do
	{
		system("cls");
		menu=StructureMenu::mainMenu();
		switch(menu)
		{
			case 1:
				do
				{
					system("cls");
					inner=StructureMenu::arrayMenu();
					switch(inner)
					{
						case 9:
							array.clearArray();
							getch();
							system("CLS");
        				break;
        			
  	   			 	   case 1:
					   	    cout<<"Wartosc : ";
  				       	    cin>>tmp1;
  				       	    array.pushFront(tmp1);
							getch();
        					system("CLS");
						break;
					
        
        				case 2:
        					cout<<"Wartosc : ";
        					cin>>tmp1;
        					array.pushBack(tmp1);
        					getch();
        					system("CLS");
        					break;
        				
        
        				case 3:
        					cout<<"Wartosc : ";
        					cin>>tmp1;
        					cout<<"Indeks: ";
        					cin>>tmp2;
        					array.push(tmp1,tmp2);
        					getch();
        					system("CLS");
        				break;
        			
        
        				case 4:
        					array.popFront();
        					getch();
        					system("CLS");
        				break;
        			
        				case 5:
        					array.popBack();
        					getch();
        					system("CLS");
        					break;
        				
        
        				case 6:
        					cout<<"Indeks : ";
        					cin>>tmp2;
        					array.pop(tmp2);
        					getch();
        					system("CLS");
        				break;
        			
        				case 7:
        					cout<<"Wartosc : ";
        					cin>>tmp1;
        					array.contains(tmp1);
        					getch();
        					system("CLS");
        				break;
        
        				case 8:
        					array.print();
        					getch();
        					system("CLS");
 						break;	
 					
 						case 10:
 							array.fileInput();
 							getch();
        					system("CLS");
  	  	     	 	     break;
					}
				}while(inner!=0);
			break;
		
			case 2:
				do
				{
					system("cls");
					inner=StructureMenu::listMenu();
					switch(inner)
					{
						case 9:
							list.clearList();
							getch();
							system("CLS");
        				break;
        			
  	   			 	   case 1:
					   	    cout<<"Wartosc : ";
  				       	    cin>>tmp1;
  				       	    list.pushFront(tmp1);
							getch();
        					system("CLS");
						break;
					
        
        				case 2:
        					cout<<"Wartosc : ";
        					cin>>tmp1;
        					list.pushBack(tmp1);
        					getch();
        					system("CLS");
        					break;
        				
        
        				case 3:
        					cout<<"Wartosc : ";
        					cin>>tmp1;
        					cout<<"Wartosc poprzedzajaca: ";
        					cin>>tmp2;
        					list.push(tmp1,tmp2);
        					getch();
        					system("CLS");
        				break;
        			
        
        				case 4:
        					list.popFront();
        					getch();
        					system("CLS");
        				break;
        			
        				case 5:
        					list.popBack();
        					getch();
        					system("CLS");
        					break;
        				
        
        				case 6:
        					cout<<"Wartosc : ";
        					cin>>tmp2;
        					list.pop(tmp2);
        					getch();
        					system("CLS");
        				break;
        			
        				case 7:
        					cout<<"Wartosc : ";
        					cin>>tmp1;
        					list.contains(tmp1);
        					getch();
        					system("CLS");
        				break;
        
        				case 8:
        					list.print();
        					getch();
        					system("CLS");
 						break;	
 					
 						case 10:
 							list.fileInput();
 							getch();
        					system("CLS");
  	  	     	 	     break;
					}
				}while(inner!=0);
			break;
		
			case 3:
				do
				{
					system("cls");
					inner=StructureMenu::heapMenu();
					
					switch(inner)
        			{
        				case 5:
        					heap.clearHeap();
        					getch();
        					system("cls");
						break;
					
						case 1:
							cout<<"Wartosc: "<<endl;
							cin>>tmp1;
							heap.push(tmp1);
							getch();
							system("cls");
						break;
					
						case 2:
							cout<<"Wartosc: "<<endl;
							cin>>tmp1;
							heap.pop(tmp1);
							getch();
							system("cls");
						break;
						
						case 3:
							cout<<"Podaj wartosc"<<endl;
							cin>>tmp1;
							heap.contains(tmp1);
							getch();
							system("cls");
						break;
					
						case 4:
							heap.print();
							getch();
							system("cls");
						break;
					
						case 6:
							heap.fileInput();
							getch();
							system("cls");
						break;	
			
					}
				}while(inner!=0);
			break;
		
			case 4:
				do
				{
					system("cls");
					inner=StructureMenu::RBTMenu();
					
					switch(inner)
        			{
        				case 5:
        					tree.clearRBT();
        					getch();
        					system("cls");
						break;
					
						case 1:
							cout<<"Wartosc: "<<endl;
							cin>>tmp1;
							tree.push(tmp1);
							getch();
							system("cls");
						break;
					
						case 2:
							cout<<"Wartosc: "<<endl;
							cin>>tmp1;
							tree.pop(tmp1);
							getch();
							system("cls");
						break;
						
						case 3:
							cout<<"Podaj wartosc"<<endl;
							cin>>tmp1;
							tree.contains(tmp1);
							getch();
							system("cls");
						break;
					
						case 4:
							tree.print();
							getch();
							system("cls");
						break;
					
						case 6:
							tree.fileInput();
							getch();
							system("cls");
						break;
			
					}
				}while(inner!=0);  	
			break;	
		}
		
	}while(menu!=0);
	
	return 0;
}