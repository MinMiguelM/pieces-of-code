/*
Write a program to sort a stack in ascending order. You should not make any assump-
tions about how the stack is implemented. The following are the only functions that
should be used to write this program: push | pop | peek | isEmpty.
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void sortStack(stack<int> &mystack){
	vector<int> temp_vector;
	while(!mystack.empty()){
		temp_vector.push_back(mystack.top());
		mystack.pop();
	}
	sort(temp_vector.begin(),temp_vector.end());
	while(temp_vector.size() != 0){
		mystack.push(temp_vector.back());
		temp_vector.pop_back();
	}
}

int main(){
	stack<int> mystack;
	mystack.push(10);
	mystack.push(2);
	mystack.push(9);
	mystack.push(20);
	mystack.push(1);
	mystack.push(30);
	sortStack(mystack);
	while(!mystack.empty()){
		int n = mystack.top();
		cout<<n<<endl;
		mystack.pop();
	}
	return 0;
}