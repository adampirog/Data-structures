#ifndef RBTNODE_H
#define RBTNODE_H

//Klasa implementujaca wezel drzewa czerwono czarnego
class RBTNode 
{
private:
	 char color;
 	 int value;

    RBTNode *parent;
    RBTNode *left;
    RBTNode *right;

friend class RBT;

};


#endif 
