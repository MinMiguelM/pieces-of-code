/*
uva p10074
*/

#include <iostream>
#include <vector>

using namespace std;

int find_area(vector<vector<short int> > matrix){
	vector<vector<short int> > sumMatrix(matrix.size(),vector<short int>(matrix[0].size()));
	for(int i = 0;i<matrix.size();i++){
		for(int j = 0;j<matrix[0].size();j++){
			if(i != 0){
				int sum = matrix[i][j] + sumMatrix[i-1][j];
				if(sum == sumMatrix[i-1][j])
					sumMatrix[i][j] = 0;
				else
					sumMatrix[i][j] = sum;
			}else
				sumMatrix[i][j] = matrix[i][j];
		}
	}
	int max = 0;
	for(int i = 0;i<matrix.size();i++){
		tmpMax = 0;
		for(int j = 0;j<matrix[0].size();j++){
			int cnt = matrix [i] [j];
			for ( int k = j + 1; k < matrix[0].size() && matrix [i] [j] <= matrix[i] [k]; k++ )
				cnt += matrix [i] [j];
			for ( int k = j - 1; k >= 0 && matrix [i] [j] <= matrix [i] [k]; k-- )
				cnt += matrix [i] [j];
			if ( cnt > max) max = cnt;
		}
	}
	return max;
}

int main(){

	return 0;
}