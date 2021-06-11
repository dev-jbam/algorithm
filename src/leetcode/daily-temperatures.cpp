/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

#if 0

#include <vector>
#include <stack>


#define MIN_TEMP 30
#define MAX_TEMP 100

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> answer(T.size(),0);
        int size = T.size();

        stack<int> p_stk;

        for(int i = 0; i < size; ++i){
            while( i < size && !p_stk.empty() && T[p_stk.top()] >= T[i] ){
                p_stk.push(i);
                i++;
            }
            while( i < size && !p_stk.empty() && T[p_stk.top()] < T[i] ){
                answer[p_stk.top()] = i - p_stk.top();
                p_stk.pop();
            }
            p_stk.push(i);
        }
       return answer;
    }
};

int main(){

    return 0;
}


#endif