/*
Given an integer between 0 and 999,999, print an English phrase that describes the
integer (eg, “One Thousand, Two Hundred and Thirty Four”).	
*/

#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int digits(int n){
	int count = 0;
	if(n==0)
		return 1;
	while(n>0){
		n /= 10;
		count++;
	}
	return count;
}

char * toEnglishStr(int n,map<int,char*> dictionary){
	int cDigits = digits(n);
	int firstDigit,rest;
	char englishStr[500];
	if (cDigits < 3){
		if(dictionary.find(n) == dictionary.end()){
			firstDigit = (n/10)*10;
			rest = n%10;
			strcpy(englishStr,dictionary[firstDigit]);
			strcat(englishStr," ");
			strcat(englishStr,dictionary[rest]);
			return englishStr;
		}else
			return dictionary[n];
	}else if(cDigits==3){
		if(dictionary.find(n) == dictionary.end()){
			firstDigit = (n/100);
			strcpy(englishStr,dictionary[firstDigit]);
			strcat(englishStr," ");
			strcat(englishStr,dictionary[100]);
			strcat(englishStr," ");
			if(n%100 > 0)
				strcat(englishStr,toEnglishStr(n%100,dictionary));
			return englishStr;
		}else
			return dictionary[n];
	}else{
		if(dictionary.find(n) == dictionary.end()){
			int firstPart = n/1000;
			int lastPart = n%1000;
			strcpy(englishStr,toEnglishStr(firstPart,dictionary));
			strcat(englishStr," ");
			strcat(englishStr,dictionary[1000]);
			strcat(englishStr," ");
			if(lastPart > 0)
				strcat(englishStr,toEnglishStr(lastPart,dictionary));
			return englishStr;
		}else
			return dictionary[n];
	}
}

int main(){
	map<int,char*> dictionary;
	dictionary[0]="Zero";dictionary[1]="One";dictionary[2]="Two";dictionary[3]="Three";dictionary[4]="Four";
		dictionary[5]="Five";dictionary[6]="Six";dictionary[7]="Seven";dictionary[8]="Eight";dictionary[9]="Nine";
		dictionary[10]="Ten";dictionary[11]="Eleven";dictionary[12]="Twelve";dictionary[13]="Thirteen";dictionary[14]="Fourthteen";
		dictionary[15]="Fifteen";dictionary[16]="Sixteen";dictionary[17]="Seventeen";dictionary[18]="Eighteen";dictionary[19]="Nineteen";
		dictionary[20]="Twenty";dictionary[30]="Thirty";dictionary[40]="Fourty";dictionary[50]="Fifty";dictionary[60]="Sixty";
		dictionary[70]="Seventy";dictionary[80]="Eighty";dictionary[90]="Ninety";dictionary[1000]="Thousand";dictionary[100]="Hundred";
	int n;
	while(true){
		//cout<<dictionary[7]<<endl;
		cin>>n;
		cout<<toEnglishStr(n,dictionary)<<endl;
	}
	return 0;
}