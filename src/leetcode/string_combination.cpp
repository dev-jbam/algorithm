#if 0
#include <string>
#include <stack>
#include <iostream>
using namespace std;

int main(){
    string input = "0101010101010101";

    stack<char> input_stack;

    for(int i = 0;i< input.length(); ++i){
        input_stack.push(input[i]);

        while(!input_stack.empty() && input_stack.size() > 1){
            char first = input_stack.top(); input_stack.pop();
            char second =  input_stack.top(); input_stack.pop();
            
            if( first == second){
                input_stack.push(second);
                input_stack.push(first);
            }
        }
    }

    cout << input_stack.size();
    return 0;
}



#endif