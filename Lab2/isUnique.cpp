
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define BUFFER_SIZE 300


bool method1(char str []){
    // Brute force approach to solve the isUnique problem
    // Time complexity: O(n^2)
    // Space complexity: O(1), not using extra data structure! 
    // Completed for you! 
    for (int i=0; i<strlen(str); i++)
        for (int j=i+1; j<strlen(str); j++)
            if (str[i] == str[j])
                return false;
    return true;
}


bool method2(char str[]){
    // You can use extra data structures
    // The computational complexity should be O(N)
    // TODO: write down your code here!

	int isUsed[95] = {};

	for(int i=0; i<strlen(str); i++) {
		int var = int(str[i]);
		if(var >= 65 && var <= 90 ) {
			var = var + 32;
		}
		
		if(isUsed[(var-32)] == 0) {
			isUsed[(var-32)] = 1;
		}
		else {
			return false;
		}
	}

    return true;
}


int main(int argc, char* argv[]){
    
    // checking the number of arguments: 
    if (argc != 4){
        cout << "Oops! Arguments are not correct!\n";
        return 0;
    }

    // the input methods should be either 1 or 2
    // note: understand why we avoided using argv[3][0]=='1'
    //  ... because "2" would be the same as "23fsdf" which is wrong!
    if ( (strcmp(argv[3], "1")==0) || (strcmp(argv[3], "2")==0) ){

    	

        // create a buffer to store the lines read from file
        char buffer [BUFFER_SIZE]; // no hard coding, we used define! 

        // opening the input file
        ifstream infile;
        infile.open(argv[1]);
        // Check if the file is available
        if (!infile.good()){
            cout << "Oops! File is not found!" << endl;
            return 0;
        }
        
        // opening the output file
        ofstream outfile;
        outfile.open(argv[2]);
        outfile << "Your results are: \n";

        while ( infile.getline(buffer, 300, '\n')  ){
            // TODO:



        	bool state;


            if (strcmp(argv[3], "1")==0) {
            	if(method1(buffer) == true) {
            		outfile << "TRUE" << "\n";

            	} else if(method1(buffer) == false) {
            		outfile << "FALSE" << "\n";
            	}

            }
            else if ( strcmp(argv[3], "2")==0) {
     	      	if(method2(buffer) == true) {
            		outfile << "TRUE" << "\n";

            	} else if(method2(buffer) == false) {
            		outfile << "FALSE" << "\n";
            	}
            }
        }


        //outfile << "your results are: ";
    }

    else 
       cout << "Oops! Method is not covered!\n";

    return 0;
}
