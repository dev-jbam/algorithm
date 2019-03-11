#ifndef stringtovector
#define stringtovector

#include <vector>
#include <string>
#include <exception>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class StringParser{
public:

    StringParser() {};

    vector<vector<T>> vector_vector_parser(string input, char delimeter){
        string pared_input;
        for(int i =0; i<input.size(); ++i) {
            if( input[i] =='[' || input[i] == ' ') continue;
            if( (input[i] == ',' || input[i]==']') && input[i-1]==']' ) continue;
            pared_input+=input[i];
        }
        vector<vector< T > > tokenVector;
        istringstream iss(pared_input);
        string token;

        try{
            while( getline(iss, token, ']' ) ){
                vector<T> ret = vector_parser(token, delimeter);
                if(!ret.empty()) tokenVector.push_back(ret);
            }
            return tokenVector;
        }
        catch(exception e){
            return tokenVector;
        }
    }    

    vector<string> vector_string(string input, char delimeter){
        vector<string> tokenVector;
        input_trim(input);
        istringstream iss(input);
        string token;
        try{
            while(getline(iss,token,delimeter)){
                if(token.size() == 0) continue;
                tokenVector.push_back(token);
            }
            return tokenVector;
        }
        catch(exception e){
            return tokenVector;
        }
    }   
    vector<T> vector_parser (string input, char delimeter) {
        vector<T> tokenVector;
        input_trim(input);
        istringstream iss(input);
        string token;

        try{
            while(getline(iss,token,delimeter)){
                if(token.size() == 0) continue;
                tokenVector.push_back(stringToT(token));
            }
            return tokenVector;
        }
        catch(exception e){
            return tokenVector;
        }
    }
private:
    void input_trim(string & input){
        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        input.erase(remove(input.begin(), input.end(), '['), input.end());
        input.erase(remove(input.begin(), input.end(), ']'), input.end());
    }

    T stringToT(string input)
    {
        if (std::is_same<T, int>::value) { 
            return stoi(input);
        } 
        if (std::is_same<T, unsigned long>::value) { 
            return stoul(input);
        } 
        if (std::is_same<T, double>::value) { 
            return stod(input);
        }
        if(std::is_same<T, float>::value){
            return stof(input);
        }
        if(std::is_same<T, long long>::value){
            return stoll(input);
        }
        if(std::is_same<T,unsigned long long>::value){
            return stoull(input);
        }
    }
};

#endif