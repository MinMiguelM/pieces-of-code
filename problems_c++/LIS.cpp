/*
Longest Increasing Subsequence
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int LIS(int array[], int size){
	int lengths[size];
	for(int i =0;i<size;i++)
		lengths[i] = 1;
	for(int i = 1;i<size;i++)
		for(int j = 0;j<i;j++)
			if(array[i] > array[j] && lengths[i] < lengths[j] + 1)
				lengths[i] = lengths[j]+1;
	int max = 0;
	for(int i= 0;i<size;i++)
		if (lengths[i] > max)
			max = lengths[i];

	return max;
}

int main(){
	int array[] = {-7,10,9,2,3,8,8,1,2,3,4};
	//int array[] = {-7,10,-9,2,3,8,8,1};
	cout<<LIS(array,(sizeof(array)/sizeof(array[0])))<<endl;
	return 0;
}