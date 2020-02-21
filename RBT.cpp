#include<iostream>
#include<fstream>

#include "RBT.h"

using namespace std;


RBT::RBT()
{
	//Inicjalizacja straznika
	sentinel.color = 'B';
	sentinel.parent = &sentinel;
	sentinel.left = &sentinel;
	sentinel.right = &sentinel;
	
	root=&sentinel;
}

RBT::~RBT()
{
	RBTClear(root);
}

void RBT::RBTClear(RBTNode* node)
{
	if(node!=&sentinel)
	{
		RBTClear(node->left);
		RBTClear(node->right);
		pop(node);
	}
	
	sentinel.color = 'B';
	sentinel.parent = &sentinel;
	sentinel.left = &sentinel;
	sentinel.right = &sentinel;
	
	root=&sentinel;
}

void RBT::clearRBT()
{
	RBTClear(root);
}


void RBT::fileInput()
{
	clearRBT();
	
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
//Podfunkcja wyswietlajaca
void RBT::print(RBTNode* node, int level)
{ 
	int i;
   if(root==&sentinel)
   	cout<<"Drzewo jest puste!"<<endl;
   else
   {
    if (node != &sentinel && node!=NULL)
	{
        print(node->right, level+1);
        cout<<endl;
        if (node == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"          ";
		}
        cout<<node->color<<":"<<node->value;
        print(node->left, level+1);
        
    }
   }
}

//Funkcja wyswietlajaca cale drzewo
void RBT::print()
{
	print(root,1);
}

bool RBT::contains(int value)
{
	RBTNode* tmp=find(value);
	if(tmp!=NULL)
	{
		cout<<"Dany element znajduje sie w drzewie"<<endl;
		return true;
	}
		
cout<<"Dany element nie znajduje sie w drzewie"<<endl;
return false;
}


//Funkcja znajdujaca wezel o podanej wartosci
RBTNode* RBT::find(int value)
{
	RBTNode * tmp=root;

  while((tmp != &sentinel) && (tmp->value != value))
  {
  	if(value < tmp->value) 
		tmp = tmp->left;
    else          
 	    tmp = tmp->right;
  }
    
    
    
  if(tmp == &sentinel) 
  	  return NULL;
return tmp;
}

//Funkcja znajdujaca wezel o minimalnej wartosci
RBTNode* RBT::findMin(RBTNode* node)
{
	if(node != &sentinel)
	{
		while(node->left != &sentinel) 
			node = node->left;
	}
   return node; 
}	

//Funkcja znajdujaca nastepnika
RBTNode* RBT::succ(RBTNode* node)
{
	RBTNode * tmp;

  if(node != &sentinel)
  {
    if(node->right != &sentinel) 
		return findMin(node->right);
    else
    {
      tmp = node->parent;
      while((tmp != &sentinel) && (node == tmp->right))
      {
        node = tmp;
        tmp = tmp->parent;
      }
      return tmp;
    }
  }
  return &sentinel;
}


//Rotacja w lewo
void RBT::rotL(RBTNode* node)
{
	RBTNode * tmp_r, * tmp_p;

  tmp_r = node->right;
  if(tmp_r != &sentinel)
  {
    tmp_p = node->parent;
    node->right = tmp_r->left;
    if(node->right != &sentinel) 
		node->right->parent = node;

    tmp_r->left = node;
    tmp_r->parent = tmp_p;
    node->parent = tmp_r;

    if(tmp_p != &sentinel)
    {
      if(tmp_p->left == node) 
	  	  tmp_p->left = tmp_r; 
      else 
	      tmp_p->right = tmp_r;
    }
    else root = tmp_r;
  }
}


//Rotacja w prawo
void RBT::rotR(RBTNode* node)
{
	RBTNode * tmp_l, * tmp_p;

  tmp_l = node->left;
  if(tmp_l != &sentinel)
  {
    tmp_p = node->parent;
    node->left = tmp_l->right;
    
    if(node->left != &sentinel) 
		node->left->parent = node;

    tmp_l->right = node;
    tmp_l->parent = tmp_p;
    node->parent = tmp_l;

    if(tmp_p != &sentinel)
    {
      if(tmp_p->left == node) 
	  	  tmp_p->left = tmp_l; 
	  else 
	  	  tmp_p->right = tmp_l;
    }
    else root = tmp_l;
  }
}


//Dodaje element do drzewa
void RBT::push(int value)
{
  RBTNode * newNode, * uncle;

  newNode = new RBTNode;        
  newNode->left  = &sentinel;          
  newNode->right = &sentinel;
  newNode->parent    = root;
  newNode->value   = value;
  
  
  if(newNode->parent == &sentinel) 
  	  root = newNode; 
  else
  while(true)             // Szuka miejsca dla nowego wezla
  {
    if(value < newNode->parent->value)
    {
      if(newNode->parent->left == &sentinel)
      {
        newNode->parent->left = newNode;  
        break;
      }
      newNode->parent = newNode->parent->left;
    }
    else
    {
      if(newNode->parent->right == &sentinel)
      {
        newNode->parent->right = newNode; 
        break;
      }
      newNode->parent = newNode->parent->right;
    }
  }
  
  
  
  newNode->color = 'R';         // Nowy wezel staje sie czerwony
  while((newNode != root) && (newNode->parent->color == 'R'))
  {
    if(newNode->parent == newNode->parent->parent->left)
    {
      uncle = newNode->parent->parent->right; // uncle - wujek newNode

      if(uncle->color == 'R')  
      {
        newNode->parent->color = 'B';
        uncle->color = 'B';
        newNode->parent->parent->color = 'R';
        newNode = newNode->parent->parent;
        continue;
      }

      if(newNode == newNode->parent->right) 
      {
        newNode = newNode->parent;
        rotL(newNode);
      }

      newNode->parent->color = 'B'; 
      newNode->parent->parent->color = 'R';
      rotR(newNode->parent->parent);
      break;
    }
    else
    {                  
      uncle = newNode->parent->parent->left;

      if(uncle->color == 'R') 
      {
        newNode->parent->color = 'B';
        uncle->color = 'B';
        newNode->parent->parent->color = 'R';
        newNode = newNode->parent->parent;
        continue;
      }

      if(newNode == newNode->parent->left) 
      {
        newNode = newNode->parent;
        rotR(newNode);
      }

      newNode->parent->color = 'B'; 
      newNode->parent->parent->color = 'R';
      rotL(newNode->parent->parent);
      break;
    }
  }
  root->color = 'B';
}

//Usuwa wezel
void RBT::pop(RBTNode* node)
{
  RBTNode * uncle, * suc, * sucB;

  if((node->left == &sentinel) || (node->right == &sentinel)) 
  	  suc = node;
  else                                   
  	  suc = succ(node);

  if(suc->left != &sentinel) 
  	  sucB = suc->left;
  else              
  	  sucB = suc->right;

  sucB->parent = suc->parent;

  if(suc->parent == &sentinel) 
  	  root = sucB;
  else if(suc == suc->parent->left) 
  	  suc->parent->left  = sucB;
  else                      
  	  suc->parent->right = sucB;

  if(suc != node) 
  	  node->value = suc->value;

  if(suc->color == 'B')   // Przywracanie wlasciwiosci drzewa 
    while((sucB != root) && (sucB->color == 'B'))
      if(sucB == sucB->parent->left)
      {
        uncle = sucB->parent->right;

        if(uncle->color == 'R')
        {              
          uncle->color = 'B';
          sucB->parent->color = 'R';
          rotL(sucB->parent);
          uncle = sucB->parent->right;
        }

        if((uncle->left->color == 'B') && (uncle->right->color == 'B'))
        {              
          uncle->color = 'R';
          sucB = sucB->parent;
          continue;
        }

        if(uncle->right->color == 'B')
        {              
          uncle->left->color = 'B';
          uncle->color = 'R';
          rotR(uncle);
          uncle = sucB->parent->right;
        }

        uncle->color = sucB->parent->color; 
        sucB->parent->color = 'B';
        uncle->right->color = 'B';
        rotL(sucB->parent);
        sucB = root;         
      }
      else
      {                
        uncle = sucB->parent->left;

        if(uncle->color == 'R')
        {              
          uncle->color = 'B';
          sucB->parent->color = 'R';
          rotR(sucB->parent);
          uncle = sucB->parent->left;
        }

        if((uncle->left->color == 'B') && (uncle->right->color == 'B'))
        {              
          uncle->color = 'R';
          sucB = sucB->parent;
          continue;
        }

        if(uncle->left->color == 'B')
        {              
          uncle->right->color = 'B';
          uncle->color = 'R';
          rotL(uncle);
          uncle = sucB->parent->left;
        }

        uncle->color = sucB->parent->color;  
        sucB->parent->color = 'B';
        uncle->left->color = 'B';
        rotR(sucB->parent);
        sucB = root;         
      }

  sucB->color = 'B';

  delete suc;
}

void RBT::pop(int value)
{
	RBTNode* tmp= find(value);
	if (tmp==NULL)
		cout<<"Podanej wartosci nie ma w drzewie! "<<endl;
	else
	{
		pop(tmp);
	}
}