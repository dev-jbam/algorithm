/*
문제 설명
금 한 돈의 값은 매일 변합니다. 금값이 낮을 때 금을 사고, 높을 때 팔면 이익을 낼 수 있습니다. 
다음 규칙에 맞게 금을 사고팔아 이익을 남기려고 합니다.

금은 여러 번 사고팔 수 있습니다.
금을 살 때는 한 돈만 살 수 있으며 팔 때도 한 돈만 팔 수 있습니다.
금은 최대 한돈 까지만 가지고 있을 수 있습니다. (즉, 현재 가지고 있는 금을 팔기 전까지는 금을 살 수 없습니다.)
금을 판 날과 다음날에는 금을 사지 않습니다.
이익이 발생하지 않는다면 금을 사고팔지 않아도 됩니다.
i번째 요소가 i번째 일의 금 한 돈의 값인 배열 gold_prices가 매개변수로 주어질 때,
금을 사고팔아 얻을 수 있는 최대 이윤을 return 하도록 solution 함수를 완성해 주세요.

제한사항
배열 gold_prices의 크기 : 100,000 이하의 자연수
금값 (배열의 원소) : 10,000 이하의 자연수
입출력 예
gold_prices	result
[2, 5, 1, 3, 4]	4
[7, 2, 5, 6, 1, 4, 2, 8]	10
[1, 3, 1, 4, 5]	4

입출력 예 설명
입출력 예 #1
금 한 돈의 시세가 [2, 5, 1, 3, 4]일 때 첫날 금을 사서 둘째 날 금을 팔고, 
하루를 쉰 다음 넷째 날 금을 사서 다섯째 날 금을 팔면 총 4의 이익이 생깁니다.

입출력 예 #2
다음과 같이 금을 사고팔면 10의 이익을 남길 수 있습니다.

[-, Buy, -, Sell, X, -, Buy, Sell]
즉, 둘째 날에 2에 금을 사고 넷째 날에 6에 팝니다. 다섯째 날은 금을 살 수 없고, 
일곱째 날에 금을 2에 사서 마지막 날에 8에 팔면 총 10의 이익이 생깁니다.
또는 다음과 같은 방법도 가능합니다.

[-, Buy, Sell, X, Buy, -, -, Sell]
즉, 둘째 날에 2에 금을 사서 셋째 날에 5에 팝니다. 넷째 날은 금을 살 수 없고, 
다섯째 날에 1에 금을 사서 마지막 날에 8에 팔면 총 10의 이익이 생깁니다.
금을 사고팔 수 있는 다양한 방법들이 있지만 10보다 큰 이익을 낼 방법은 없으므로 최대 이윤인 10을 return 합니다.
*/

#if 0

#include <vector>
#include <deque>

#define MAX_PRICE 10001
using namespace std;

int maxii(int a, int b){
    return a < b ? b : a;
}

int find_all(int cur, int limit, vector<int> &max_profit, const vector<int> & prices){
    if ( cur >= limit ) return 0;
    int &ans = max_profit[cur];
    if( ans != -1 ) return ans;

    ans = find_all(cur + 1, limit, max_profit, prices);

    for(int i = cur + 1; i < limit; i++){
        if( prices[cur] <prices[i] ) {
            ans = maxii(ans, find_all(i + 2, limit, max_profit, prices) + prices[i] - prices[cur]);
        }
    }
    return ans;
}   

int solution(vector<int> gold_prices){
    int size = gold_prices.size();
	int answer = 0;

    vector<int> max_profit(size, -1);

    answer = find_all(0, size, max_profit, gold_prices);

	return answer;
}

#endif