#if 1

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
    int n  = 0 ;
    cin >> n;
    char a;
    cin >> a;
    string lost, reserve;
    getline(cin, lost);
    getline(cin,reserve);;
    StringParser<int> sparser;
    vector<int> vi = sparser.vector_parser(lost,',');
    vector<int> vi2 = sparser.vector_parser(reserve,',');
    // solution(n,vi,vi2);
}

int main(){

    freopen("/home/joon/sources/algorithm/build/input.txt", "r", stdin);

    return 0;
}


#endif