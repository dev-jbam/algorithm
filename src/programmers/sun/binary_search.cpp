/*
문제 설명
Problem Statement
You have several sticks of different lengths, and a stick case of a fixed length.

We want to find 2 sticks that just fit in the case.

*Please describe algorithm complexity as comment.

Input
[L1] [L2] ... [LN]
[target]
The first line of input contains a list of integers separated by a whitespace. This list represents the lengths of the sticks.

The second line of input contains an integer target. This integer represents the length of the case.

Output
Output a pair of lengths whose sum is equal to target.

[La] [Lb]
Output should be ordered in ascending order. (e.g. 1 2 is acceptable. 2 1 is not)

If you find 2 or more pairs, output the pair which contains the stick of the shortest length. (e.g. If the target is 5, and you find both 1 4 and 2 3, output 1 4)

In case there is no such pairs, output a single -1

-1
Input Example
1 2 3 4 5
6
Output Example
1 5
*/


#if 0

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
//O(nlog(n))

vector<int> vector_parser (string input, char delimeter) {
    vector<int> tokenVector;
    istringstream iss(input);
    string token;

    try{
        while(getline(iss,token,delimeter)){
            if(token.size() == 0) continue;
            tokenVector.push_back(stoi(token));
        }
        return tokenVector;
    }
    catch(exception e){
        return tokenVector;
    }
}

// arr[start,end]
int find_binary_search(int start, int end, vector<int> & arr, const int &target) {
    int l = start, r = end;
    int mid = (start + end)/2;

    while( l < r) {
        if( arr[mid] == target ) {
            return arr[mid];
        }
        if ( target < arr[mid]){
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    return -1;
}   

void run_find_target_program() {
    string input;
    getline(cin, input);
    int target;
    cin >> target;
    vector<int> vi = vector_parser(input,' ');
    
    int size = vi.size(); 
    sort(vi.begin(), vi.end());

    for(int i = 0 ; i < size - 1; ++i){
        int ret = binary_search(vi.begin() + i + 1, vi.end(), target - vi[i] );
        if( ret ){
            cout << vi[i] << " " << target - vi[i] <<"\n";
            return;
        }
    }
    cout << -1 << "\n";
}


int main() {

    freopen("/home/joon/sources/algorithm/build/input.txt", "r", stdin);
    run_find_target_program();
    
    return 0;   
}

#endif