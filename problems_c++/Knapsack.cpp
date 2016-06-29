/*
01-knapsack
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct item{
	float value;
	int weight;
};

float maximum_gain_recursive(vector<item> items, int max_weight, int i){
	if (i == 0)
		return 0;
	if (items[i].weight > max_weight)
		return maximum_gain_recursive(items, max_weight,i-1);
	else{
		int f = maximum_gain_recursive(items,max_weight,i-1);
		int s = maximum_gain_recursive(items,max_weight-items[i].weight,i-1)+items[i].value;
		return max(f,s);
	}
}

float maximum_gain_memoization(vector<item> items, int max_weight){ // wrong answer
	vector< vector<float> > m(items.size(),vector<float>(max_weight));
	for(int i = 1;i<items.size();i++){
		for(int j = 0;j<max_weight;j++){
			if(items[i].weight > j){
				m[i][j] = m[i-1][j];
			}else{
				m[i][j] = max(m[i-1][j],m[i-1][j-items[i-1].weight]+items[i-1].value);
			}
		}
	}
	return m[items.size()-1][max_weight-1];
}

int main(){
	vector<item> items;
	item a;
	a.value = 4;
	a.weight = 12;
	items.push_back(a);

	a.value = 2;
	a.weight = 8;
	items.push_back(a);

	a.value = 2;
	a.weight = 10;
	items.push_back(a);

	a.value = 2;
	a.weight = 2;
	items.push_back(a);

	a.value = 10;
	a.weight = 4;
	items.push_back(a);

	cout<<maximum_gain_recursive(items,15,items.size()-1)<<endl;
	cout<<maximum_gain_memoization(items,15)<<endl;
	return 0;
}