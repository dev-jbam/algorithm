#if 0 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
int find_max_square(const vvi & matrix) {
    
    int answer = 0;
    for(int y=1; y< matrix.size(); ++y){
        for(int x=1; x< matrix[0].size(); ++x){
            if(maxtrix[y][x]== '1'){
                matrix[y][x] = min( min(matrix[y][x-1], matrix[y-1][x]), matrix[y-1][x-1]) + 1;
                answer = max(answer, matrix[y][x]);
            }
        }
    }


    return 0;
}

#endif