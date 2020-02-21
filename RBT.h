#ifndef RBT_H
#define RBT_H

#include "RBTNode.h"


class RBT 
{

private:
	RBTNode sentinel;
	RBTNode*  root;
	
	//Prywatne metody pomocnicze
	void print(RBTNode* node, int level);
	
	RBTNode* succ(RBTNode* node);
	
	RBTNode* find(int value);
	
	RBTNode* findMin(RBTNode* node);
	
	void rotL(RBTNode* node);
	
	void rotR(RBTNode* node);
	
	void pop(RBTNode* node); 
	
	void RBTClear(RBTNode* node);
	
public:
	
	RBT();
	~RBT();
		
	//Publiczne metody do sterowania struktura
	void print();
	
	bool contains(int value);	
	
	void push(int value);
	
	void pop(int value);
	
	void clearRBT();
	
	void fileInput();
	

    
};

#endif 
