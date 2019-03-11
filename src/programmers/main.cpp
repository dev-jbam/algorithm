#if 0

#include "string_to_vector.h"
#include <cstdio>
#include <iostream>

void call_vvi_solution(){
    string input;
    getline(cin, input);
    StringParser<int> sparser;
    vector<vector<int> > vvi = sparser.vector_vector_parser(input, ',');
    // solution(vvi);
}


void call_vi_solution(){

    string input;
    getline(cin, input);
    int limit;
    cin >> limit;

    StringParser<int> sparser;
    vector<int> vi = sparser.vector_parser(input,',');
    
    //  solution(vi, vi);
}

int main(){

    freopen("/home/joon/sources/algorithm/build/input.txt", "r", stdin);

    
    // call_vi_solution();
    return 0;
}


#endif