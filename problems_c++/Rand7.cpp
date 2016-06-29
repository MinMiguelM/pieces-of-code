/*
Write a method to generate a random number between 1 and 7, given a method
that generates a random number between 1 and 5 (i.e., implement rand7() using
rand5()).
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int rand5(){
	return rand() % 5 + 1;
}

int rand7(){
	int r = rand() % 3;
	return rand5() + r;
}

int main(){
	srand (time(NULL));
	cout<<rand7()<<endl;
	cout<<rand7()<<endl;
	cout<<rand7()<<endl;
	cout<<rand7()<<endl;
	cout<<rand7()<<endl;
	return 0;	
}