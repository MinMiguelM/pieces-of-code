/*
You are given a range [first, last], initially white. You need to paint it black. 
For this purpose you have a set of triples 
[(f, l, cost), ...] - where each triple means that you can paint range [f, l] for `cost` coins 
(limitations: cost is floating point >= 0, f, l, first, last are integers). 
Find minimum cost needed to paint the whole range [first, last] or return -1 if it's impossible 
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cfloat>

using namespace std;

struct triple{
	int f,l;
	float cost;
};

bool is_into_range(int f,int l, int f_check,int l_check){
	if((f_check >= f && f_check < l) && (l_check > f && l_check <= l))
		return true;
	return false;
}

float minimum_cost(vector<triple> setTriple,int f,int l){
	triple actual_cost;
	float minimum = FLT_MAX;
	for(int i = 0;i<setTriple.size();i++){
		if(setTriple[i].f == f && setTriple[i].l == l){
			actual_cost.f = f;
			actual_cost.l = l;
			actual_cost.cost = setTriple[i].cost;
		}else{
			actual_cost.cost = setTriple[i].cost;
			actual_cost.f = setTriple[i].f;
			actual_cost.l = setTriple[i].l;
			for (int j = i+1;j<setTriple.size();j++){
				float local_f = setTriple[j].f;
				float local_l = setTriple[j].l;
				if(!is_into_range(setTriple[i].f,setTriple[i].l,local_f,local_l)){
					actual_cost.cost += setTriple[j].cost;
					if(local_f <= setTriple[i].f){
						actual_cost.f = local_f;
						actual_cost.l = 
					}
					else if (local_l >= setTriple[i].l){
						actual_cost.l = local_l;
					}
				}
			}
		}
		if(minimum > actual_cost.cost && actual_cost.f == f && actual_cost.l == l)
				minimum = actual_cost.cost;
	}
	if(minimum == FLT_MAX)
		return -1;
	return minimum;
}

int main(){
	int f,l,n;
	vector<triple> setTriple;
	triple input;
	cout<<"f l"<<endl;
	cin>>f>>l;
	cin>>n;
	while(n!=0){
		cout<<"f l cost"<<endl;
		cin>>input.f>>input.l>>input.cost;
		setTriple.insert(setTriple.begin(),input);
		cin>>n;
	}
	float cost = minimum_cost(setTriple,f,l);
	cout<<cost<<endl;
	return 0;
}