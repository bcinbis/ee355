#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

void URLify(char* arr, int length) {
	//int buffer_size = sizeof(arr) - length;
	
	for( int i = (length-1); i>=0; i--) {
		if(arr[i] == ' ') {
			
			int j = i+1;
			while(arr[j] != ' ') {
				j++;
			}

			for( int k = j-1; k>= i+1; k-- ) {
				arr[k+2] = arr[k];
			}
			arr[i] = '%';
			arr[i+1] = '2';
			arr[i+2] = '0';

		}

	}
		
}

/*

int main() {
	
	//real size is 14; +1 for null character
	char a[] = "EE355 USC ECE    ";


	URLify(a, 13);


	
	//cout<<sizeof(a);

	cout<<a<<endl;
	
	return 0;
}

*/