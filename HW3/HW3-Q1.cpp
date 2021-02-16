#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main() {

	string inp = "";
	cout << "Enter your password: \n";
	cin>>inp;

	// Reference: https://www.geeksforgeeks.org/convert-string-char-array-cpp/
	int len = inp.length();

	while(len >= 15) {
		cout << "Must be 15 characters or less \nEnter your password: \n";
		cin>>inp;
		len = inp.length();
	}

	char pass[len+1] = {};
	strcpy(pass, inp.c_str());

	for(int i=0; i<len; i++) {
		int var = int(pass[i]);
		if(65 <= var && var <= 90) {
			if(var != 90) {
				pass[i] += 33;
			} else {
				pass[i] = 97;
			}
		} else if(97 <= var && var <= 122) {
			if(var != 122) {
				pass[i] -= 31;
			} else {
				pass[i] = 65;
			}
		}
	}

	cout << "your new password is: " << pass;

	return 0;
}