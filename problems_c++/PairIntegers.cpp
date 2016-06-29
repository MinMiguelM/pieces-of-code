/*
Design an algorithm to find all pairs of integers within an array which sum to a speci-
fied value.	
*/

#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
vector<pair<int,int> > sumForceBrute(vector<int> vect, int value){
	pair<int,int> p;
	vector<pair<int,int> > pairIntegers;
	for(int i = 0;i<vect.size()-1;i++){
		for(int j = i+1;j<vect.size();j++){
			if((vect[i]+vect[j])==value){
				p.first = vect[i];
				p.second = vect[j];
				pairIntegers.push_back(p);
			}
		}
	}
	return pairIntegers;
}

int main(){
	vector<int> vect;
	for(int i = 0;i<10;i++)
		vect.push_back(i);
	vector<pair<int,int> > p;
	while(true){
		int n;
		cin>>n;
		p = sumForceBrute(vect,n);
		for(int i = 0;i<p.size();i++)
			cout<<p[i].first<<" "<<p[i].second<<endl;
	}
	return 0;
}