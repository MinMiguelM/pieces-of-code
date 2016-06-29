#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Element.h"
#include <iostream>

template<class T>
class LinkedList{
private:
	Element<T> *root;
public:
	LinkedList();
	Element<T>* getRoot();
	void append(T);
	void print();
};

template<class T>
LinkedList<T>::LinkedList(){
	root = NULL;
}

template<class T>
Element<T>* LinkedList<T>::getRoot(){
	return this->root;
}

template<class T>
void LinkedList<T>::append(T value){
	Element<T> *element = new Element<T>(value);
	if(root == NULL)
		root = element;
	else{
		Element<T> *auxiliar = root;
		while(auxiliar->getNext()!=NULL){
			auxiliar = auxiliar->getNext();
		}
		auxiliar->setNext(element);
	}
}

template<class T>
void LinkedList<T>::print(){
	Element<T> *auxiliar = root;
	while(auxiliar!=NULL){
		std::cout<<auxiliar->getData()<<" -> ";
		auxiliar = auxiliar->getNext();
	}
	std::cout<<std::endl;
}

#endif