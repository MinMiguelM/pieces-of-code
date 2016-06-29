/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column is set to 0.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

void setMatrix(int **matrix,int m, int n){
	int *row = new int[m];
	int *column = new int[n];
	for(int i = 0;i<m;i++){
		for (int j=0;j<n;j++){
			if (matrix[i][j] == 0){
				row[i] = 1;
				column[j] = 1;
			}
		}
	}
	for(int i = 0;i<m;i++){
		for (int j=0;j<n;j++){
			if (row[i]==1 || column[j]==1){
				matrix[i][j] = 0;
			}
		}
	}
}

void print_matrix(int **matrix,int m, int n){
	for(int i = 0;i<m;i++){
		for (int j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	//{{1,2,3,4,5},{6,7,8,9,10},{1,2,3,4,5},{11,12,13,14,15},{1,2,3,4,0}};
	int **matrix;
	matrix = new int*[5];
	for(int i = 0;i<5;i++)
		matrix[i] = new int[5];
	for(int i = 0;i<5;i++){
		for (int j=0;j<5;j++){
			matrix[i][j] = j+i;
		}
	}
	setMatrix(matrix,5,5);
	print_matrix(matrix,5,5);
	return 0;
}