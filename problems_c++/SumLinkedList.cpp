/*
You have two numbers represented by a linked list, where each node contains a sin-
gle digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
the list. Write a function that adds the two numbers and returns the sum as a linked
list.
EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
*/
#include "LinkedList.h"

using namespace std;


void sumLinkedList(LinkedList<int> *num1,LinkedList<int> *num2,LinkedList<int> *total){
	Element<int> *aux1 = num1->getRoot();
	Element<int> *aux2 = num2->getRoot();
	int sum=0;
	while(aux1 != NULL || aux2 != NULL){
		int digit1 = (aux1==NULL)? 0 : aux1->getData();
		int digit2 = (aux2==NULL)? 0 : aux2->getData();
		sum += digit2 + digit1;
		if(sum < 10){
			total->append(sum);
			sum = 0;
		}else{
			int last = sum%10;
			sum /= 10;
			total->append(last);
		}
		aux1 = (aux1==NULL)?NULL:aux1->getNext();
		aux2 = (aux2==NULL)?NULL:aux2->getNext();
	}
}

int main(){
	LinkedList<int> * num1 = new LinkedList<int>();
	num1->append(3);
	num1->append(1);
	num1->append(5);
	num1->append(5);
	LinkedList<int> * num2 = new LinkedList<int>();
	num2->append(5);
	num2->append(9);
	num2->append(2);
	LinkedList<int> * total = new LinkedList<int>();
	sumLinkedList(num1,num2,total);
	total->print();
	return 0;
}