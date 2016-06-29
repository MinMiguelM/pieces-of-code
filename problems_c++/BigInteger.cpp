#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define DIGITS 50

// Write a class to take in a large arbitrary number, also provide a function to increment the number.The number will be passed on as an array of integers.

// 1. Accept large number as string
// 2. Copy each digit into array of integers with one digit in each int (preferred to push number to end of array)
// 3. Create function to increment mega integer array

class LargeNumber {

public:
	LargeNumber();
	void printMegaIntArr();
	void incrementMegaIntArr();

private:
	string entry;
	int arrOfNums[DIGITS];
};

int main(){
	LargeNumber largeNumber;

	largeNumber.printMegaIntArr();
	largeNumber.incrementMegaIntArr();
	largeNumber.incrementMegaIntArr();
	largeNumber.printMegaIntArr();

	cout << endl << endl;
	return 0;
}

LargeNumber::LargeNumber()
{
	memset(arrOfNums, 0, sizeof(arrOfNums));

	cout << "Enter a large number and press enter:";
	cin >> entry;

	// Return if string is empty otherwise save first character
	if (!entry.empty()) {
		char tmpChar = entry[0];

		int j = (DIGITS - entry.size());
		for (int n = 0; tmpChar != NULL; n++, j++) {
			arrOfNums[j] = int(tmpChar - '0');
			cout << "Inserting: " << arrOfNums[j] << " at j =" << j << endl;
			tmpChar = entry[n + 1];
		}
	}
}

// Increment the Mega Array of numbers
void LargeNumber::incrementMegaIntArr()
{
	int tmpNum = 0;

	for (int n = DIGITS -1 ; ; n--) {
		tmpNum = arrOfNums[n] + 1;

		if (tmpNum < 10) {
			arrOfNums[n] = tmpNum;
			return;
		}
		else {
			arrOfNums[n] = 0;
		}
	}
}

// Print the Mega Array of numbers
void LargeNumber::printMegaIntArr()
{
	for (int n = 0; n < DIGITS; n++) {
		cout << arrOfNums[n];
	}
	cout << endl << endl;
}