/*

https://programmers.co.kr/learn/courses/30/lessons/42584

주식가격
문제 설명
초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 유지된 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

제한사항
prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
prices의 길이는 2 이상 100,000 이하입니다.
입출력 예
prices	return
[498,501,470,489]	[2,1,1,0]
입출력 예 설명
1초 시점의 ₩498은 2초간 가격을 유지하고, 3초 시점에 ₩470으로 떨어졌습니다.
2초 시점의 ₩501은 1초간 가격을 유지하고, 3초 시점에 ₩470으로 떨어졌습니다.
3초 시점의 ₩470은 최종 시점까지 총 1초간 가격이 떨어지지 않았습니다.
4초 시점의 ₩489은 최종 시점까지 총 0초간 가격이 떨어지지 않았습니다.
*/

#if 0

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size, 0);
    stack<int> price_stk;
    for( int i = 0; i < size; ++i) {
        while(!price_stk.empty() && prices[price_stk.top()] > prices[i]){
            answer[price_stk.top()] = i - price_stk.top();
            price_stk.pop();
        }
        price_stk.push(i);
    }
    while(!price_stk.empty()){
        answer[price_stk.top()]  = size - price_stk.top() - 1;
        price_stk.pop();
    }
    return answer;
}


#endif


#if 0 

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();
    
    for( int i = 0; i < size - 1; ++i) {
        int timer = 0;
        for(int j = i + 1; j < size; ++j){
            if(prices[j] >= prices[i]){
                timer++;
            } else{
                answer.push_back(timer + 1);
            }
        }
    }
    answer.push_back(0);
    return answer;
}
#endif