#ifndef ARRAY_H
#define ARRAY_H

//Klasa Array - Tablica
class Array
{
	private:
		int* headPointer;
		
		unsigned int size;
		
	public:
		Array();
		~Array();
		
		void pushFront(int value);
		
		void pushBack(int value);
		
		void push(int value, unsigned int position);
		
		void popFront();
		
		void popBack();
		
		void pop(unsigned int position);
		
		bool contains(int value);
		
		void print();
		
		void clearArray();
		
		void fileInput();
			
			
	
};
#endif