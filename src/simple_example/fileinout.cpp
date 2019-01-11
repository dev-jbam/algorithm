 #if 0

#include <vector>

#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
    }
};

int main(){
    vector<int> arr(1000);

    srand(time(NULL));
    for(int i =0; i< 1000; ++i){
        arr[i] = rand()%1000;
    }
    
    string file_name = "test.txt";
	//write
	ofstream ofile(file_name);
	if (ofile.is_open()){
        for(int i =0; i< 1000; ++i){
		    ofile << arr[i] << "\n";
        }
	}
	//read
	ifstream ifile(file_name);
	string line;
	if (ifile.is_open()){
		while (getline(ifile, line))
			cout << line << endl;
		ifile.close();
	}
	return 0;
}

 #endif