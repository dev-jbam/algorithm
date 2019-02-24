/*
문제 설명
두 사람 A, B가 사는 집에 냉장고 한 대가 있습니다. A 씨는 좋지 않은 버릇이 있는데, 바로 냉장고 안을 살펴본 다음에 문을 닫지 않는 것입니다. 그래서 B 씨는 가끔 냉장고 문이 열려있는지 확인하고, 만약 열려있다면 냉장고 문을 닫습니다.

A 씨가 냉장고 안을 살펴본 시각이 담긴 배열 openA, B 씨가 냉장고 문이 닫혀 있는지 확인한 시각이 담긴 배열 closeB가 매개변수로 주어질 때, 냉장고 문이 얼마나 열려있었는지 return 하도록 solution 함수를 완성해주세요.

제한사항
openA는 A 씨가 냉장고 안을 살펴본 시각이 오름차순으로 들어있는 배열입니다.
openA의 길이는 1 이상 500 이하입니다.
closeB는 B 씨가 냉장고 문이 닫혀있는지 확인한 시각이 오름차순으로 들어있는 배열입니다.
closeB의 길이는 1 이상 500 이하입니다.
openA, closeB의 원소는 1 이상 5,000 이하인 자연수입니다.
처음에 냉장고 문은 닫혀있습니다.
A 씨가 냉장고 안을 살펴본 시각과 B 씨가 냉장고 문이 닫혀있는지 확인한 시각이 같은 경우는 없습니다.
마지막에는 항상 B 씨가 냉장고 문이 닫혀있는지 확인합니다.
즉, (openA의 마지막 원소 < closeB의 마지막 원소)인 경우만 입력으로 주어집니다.
입출력 예
openA	closeB	result
[3, 5, 7]	[4, 10, 12]	6
[4, 7, 9, 16]	[2, 5, 12, 14, 20]	10
입출력 예 설명
입출력 예 #1
처음에 냉장고 문은 닫힌 상태입니다. 이후 각 시각의 냉장고 상태는 아래와 같습니다.

시각	냉장고 상태	설명
0 ~ 2	닫힘	처음에 냉장고 문은 닫혀있습니다.
3	열림	A가 냉장고 문을 열어둡니다.
4	닫힘	B가 냉장고 문을 닫습니다.
5 ~ 6	열림	A가 냉장고 문을 열어둡니다.
7 ~ 9	열림	냉장고 문이 이미 열린 상태입니다. A는 마찬가지로 냉장고 안을 살펴보고 그대로 문을 열어둡니다.
10 ~ 11	닫힘	B가 냉장고 문을 닫습니다.
12 ~	닫힘	A가 다시 열지 않았으므로, 냉장고 문은 잘 닫힌 상태입니다.
따라서 냉장고 문이 열린 시각은 3, 5 ~ 9로 6을 return 하면 됩니다.

입출력 예 #2
냉장고 문이 열린 시각은 4, 7 ~ 11, 16 ~ 19로 10을 return 하면 됩니다.
*/


#if 0


#include <string>
#include <vector>
#include <algorithm>

struct fridge_log{
    int time;
    int opened;
    fridge_log(int time, bool opened):time(time),opened(opened){};
};
using namespace std;

int solution(vector<int> openA, vector<int> closeB) {
    int answer = 0;
    int a_len = openA.size();
    int b_len  = closeB.size();
    int len = a_len + b_len;
    vector<fridge_log> log_v;

    int open_idx = 0 , close_idx = 0;
    for(int i = 0; i<len; ++i){
        if(open_idx < a_len && openA[open_idx] < closeB[close_idx]){
            log_v.push_back(fridge_log(openA[open_idx++], true));
            continue;
        }
        log_v.push_back(fridge_log(closeB[close_idx++], false));        
    }    
    log_v.push_back(fridge_log(closeB[b_len-1], 0));

    int start = 0;    
    for(int i = 0; i < len;){    
        while(i < len && !log_v[i].opened) ++i;
        
        if( i == len ) break;

        int opend_at = log_v[i].time;   
        while(i < len && log_v[i].opened) ++i;
        
        int closed_at = log_v[i].time;
        answer += (closed_at - opend_at);
    }
    return answer;
}

#endif


#if 0


#include <string>
#include <vector>
#include <algorithm>

struct fridge_log{
    int time;
    int opened;
    fridge_log(int time, bool opened):time(time),opened(opened){};

    bool operator<(const fridge_log &b)const {
        return time < b.time;
    }
};
using namespace std;

int solution(vector<int> openA, vector<int> closeB) {
    int answer = 0;
    int a_len = openA.size();
    int b_len  = closeB.size();
    vector<fridge_log> log_v;

    for(int i = 0; i<a_len; ++i){
        log_v.push_back(fridge_log(openA[i], 1));
    }

    for(int i = 0; i < b_len; ++i){
        log_v.push_back(fridge_log(closeB[i], 0));
    }
    log_v.push_back(fridge_log(closeB[b_len-1], 0));

    sort(log_v.begin(), log_v.end());

    int len = a_len + b_len;
    int start = 0;
    
    for(int i = 0; i < len;){    
        while(i < len && !log_v[i].opened){
            ++i;
        }
        if( i == len ) break;

        int opend_at = log_v[i].time;
        
        while(i < len && log_v[i].opened){
            ++i;
        }
        int closed_at = log_v[i].time;
        answer += (closed_at - opend_at);
    }

    return answer;
}
#endif