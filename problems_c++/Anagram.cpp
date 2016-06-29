/*
Write a method to decide if two strings are anagrams or not.
*/
#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s1, string s2, int i){
	if(s1 == s2)
		return true;
	if(s1.size() != s2.size())
		return false;
	size_t pos = s2.find(s1[i]);
	if (pos != string::npos){
		s1.erase(i,1);
		s2.erase(pos,1);
		return isAnagram(s1,s2,i);
	}
	return false;
}

int main(){
	bool b = isAnagram("openn","ponen",0);
	if(b) cout<<"true"; else cout<<"false";
	cout<<endl;
	return 0;
}