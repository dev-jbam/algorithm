#if 0

#include <cstdio>
#include <stack>
#include <string>
#include <exception>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        
    }

    private:
    stack<int> opstk;
    stack<int> istk;

    void input_parser(string s){
        string target = s.replace(s.begin(), s.end(), " ", "");
        int len = target.length();
        int last_num_idx = 0;
        for( int i = 0 ; i< len; i++){
            if(!is_number(target[i])){
                
            }
        }
    }

    void calculate(char op, int num){
        const int top_value = istk.top();
        istk.pop();
        switch(op){
            case '+' :
                istk.push(top_value + num);
                break;            
            case '-' :
                istk.push(top_value - num);
                break;            
            case '*' :
                break;            
            case '/':
                break;
        }
    }

    bool is_number(char target){
        return  0 <= target -'0'  && target - '0' <=9 ;
    }
    bool is_operator(char op){
        return op == '+' || op =='-';
    }
};


int main(){

    stack<int> a;

    return 0;
}
#endif