/*
You are given two sorted arrays, A and B, and A has a large enough buffer at the end
to hold B. Write a method to merge B into A in sorted order.
*/

#include <iostream>

using namespace std;

void merge(int a[],int b[], int m, int n){
	int k = m+n-1;
	int i = m-1;
	int j = n-1;
	while(i>=0 && j>=0){
		if(a[i] > b[j])
			a[k--] = a[i--];
		else
			a[k--] = b[j--];
	}
	while(j>=0)
		a[k--] = b[j--];
}

int main(){
	int a[10] = {1,3,5,7};
	int b[4] = {2,4,6,8};
	merge(a,b,4,4);
	for (int i = 0;i<10;i++)
		cout<<a[i]<<endl;
	return 0;
}