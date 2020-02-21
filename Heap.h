#ifndef HEAP_H
#define HEAP_H

//Klasa implementuje kopiec typu MIN
class Heap 
{
private:
	//Atrybtuty obiektu
	int* values;
    unsigned int size;	
    
    //Prywatne metody pomocnicze do zachowywania struktury kopca
    void swap(int* x, int* y);
    
    unsigned int left(int index);
    
    unsigned int right(int index);
    
    unsigned int parent(int index);
    
    void extractRoot();
    
    void decreaseKey(int value);
    
    void heapify(unsigned int index);
    
public:
	
	//Publiczne metody do obslugi kopca	
    Heap();

    ~Heap();

    void push(int value);

    void pop(int value);

    bool contains(int value);

    void print();

	void clearHeap();
	
	void fileInput();
    

};


#endif 
