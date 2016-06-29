/*
Longest common subsequence
*/

#include <cstring>
#include <iostream>
#include <climits>

using namespace std;

int LCS(char * s1, char* s2,int i, int j){
	if(i == strlen(s1) || j == strlen(s2))
		return 0;
	if(s1[i]==s2[j])
		return LCS(s1,s2,i+1,j+1)+1;
	int one_side = LCS(s1,s2,i,j+1);
	int other_side = LCS(s1,s2,i+1,j);

	if(one_side > other_side)
		return one_side;
	return other_side;
}

template <typename T>
int LCSMemo (T X[], T Y[], int i, int j, int** M){
    if(M[i][j]>-1)
        return M[i][j];
    else{
        if ( i+1==strlen(X) || j+1==strlen(Y))
            M[i][j]=0;
        else{
            if( X[i]==Y[j] ){
                if(M[i][j]>-1)
                    M[i+1][j+1] = M[i][j]+1;
                else
                    M[i+1][j+1] = LCSMemo(X, Y, i+1, j+1, M)+1;
            }
            else{
                int L, R;
                if(M[i+1][j]>-1)
                    L = M[i+1][j];
                else
                    L = LCSMemo(X, Y, i+1, j, M);
                if(M[i][j+1]>-1)
                    R = M[i][j+1];
                else
                    R = LCSMemo(X, Y, i, j+1, M);
                M[i][j] = max(L,R);
            }
        }
        return M[i][j];
    }
}

int LCSMatrix (int r, int c, int **M){
    for(int i=0; i<r; i++)
        *(M+i) =  new int [c];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            *(*(M+i)+j) = -1;
}

int main(){
	char * s1 = "apple";
	char * s2 = "people";

	int r = strlen(s1);
    int c = strlen(s2);
    int** M = new int* [r];

    LCSMatrix (r, c, M);
	cout<<LCS(s1,s2,0,0)<<endl;
	cout<<LCSMemo(s1,s2,0,0,M)<<endl;
	cout<<INT_MAX<<endl;
	return 0;
}