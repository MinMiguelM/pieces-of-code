/*
Write program that takes integer, deletes one of two consecutive digits and return 
greatest of all results.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

struct info_digits{
	int index;
	int digit;
};

bool contain(vector<info_digits> array, int x){
	for(int i = 0 ; i<array.size();i++)
		if(array[i].digit==x)
			return true;
	return false;
}

vector<info_digits> consecutive_digits(string number){
	vector<info_digits> consecutive;
	info_digits digit;
	for (int i = 0;i<number.size()-1;i++){
		if (number[i] == number[i+1] && !contain(consecutive,int(number[i]-'0'))){
			digit.index = i;
			digit.digit = int(number[i]-'0');
			consecutive.insert(consecutive.begin(),digit);
		}
	}
	return consecutive;
}

int deleting_digit(string number){
	vector<info_digits> consecutive; 
	consecutive = consecutive_digits(number);
	string cpy_number;
	int max = 0,local_max;
	for( int i = 0;i < consecutive.size();i++){
		cpy_number = number;
		cpy_number.erase(consecutive[i].index,1);
		local_max = atoi(cpy_number.c_str());
		if(local_max > max)
			max = local_max;
	}
	return max;
}

int main(){
	string number;
	while(true){
		cout<<"> ";
		cin>>number;
		cout<<deleting_digit(number)<<endl;
	}
	return 0;
}