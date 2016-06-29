#include <iostream>

using namespace std;

int partition(int array[],int f, int l){
	int aux;
	while(f<l){
		if(array[f]>array[l]){
			aux = array[f];
			array[f] = array[l-1];
			array[l-1] = array[l];
			array[l] = aux;
			l--;
		}else
			f++;
	}
	return l;
}

void quickSort(int array[], int f, int l){
	if(f < l){
		int p = partition(array,f,l);
		quickSort(array,f,p-1);
		quickSort(array,p+1,l);
	}
}

int main(){
	int array[10] = {5,7,2,8,9,10,1,85,0,12};
	quickSort(array,0,9);
	for(int i = 0;i<10;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}