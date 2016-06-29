#ifndef ELEMENT_H
#define ELEMENT_H
#include <cstdlib>

template<class T>
class Element{
private:
	T data;
	Element *next;
public:
	Element(T);
	T getData();
	void setData(T);
	Element<T>* getNext();
	void setNext(Element<T> *);
};

template<class T>
Element<T>::Element(T data){
	this->data = data;
	this->next = NULL;
}

template<class T>
T Element<T>::getData(){
	return this->data;
}

template<class T>
void Element<T>::setData(T newValue){
	this->data = newValue;
}

template<class T>
Element<T>* Element<T>::getNext(){
	return this->next;
}

template<class T>
void Element<T>::setNext(Element<T> *next){
	this->next = next;
}

#endif