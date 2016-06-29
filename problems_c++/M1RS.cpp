/*
Maximum 1D range sum
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int maximumSum(int array[],int n, int &i, int &j){
	int ans = 0,sum=0;
	int ii = 0,jj=0;
	i=0;j=0;
	for (int k = 0;k<n;k++){
		sum += array[k];
		jj = k;
		if(ans < sum){
			ans = sum;
			i = ii;j = jj;
		}
		if (sum <= 0){
			sum = 0;
			ii = k+1;
		}
	}
	return ans;
}

int main(){
	int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int i,j;
	cout<<maximumSum(A,9,i,j)<<endl;
	for (;i<=j;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}