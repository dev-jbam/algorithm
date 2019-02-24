/*
https://programmers.co.kr/learn/courses/30/lessons/42860

조이스틱
문제 설명
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동
예를 들어 아래의 방법으로 JAZ를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.
입출력 예
name	return
JEROEN	56
JAN	23


*/

#if 0

#include <string>
#include <vector>
#include <deque>
#define MAX_CHAR 26

int max = 0;

using namespace std;


int absii(int a, int b){
    return a < b ? b-a : a-b;
}

int get_minimum_movement(char from, char to, int max_length){
    int middle = max_length/2;
    int diff = absii(from,to);
    int move = diff > middle ? max_length - diff: diff;
    return move;
}

int solution(string name) {
    int answer = 0;

    deque<int> next_target;
    int length = 0;
    while(name[length]){
        if(name[length] != 'A') {
            next_target.push_back(length);
        }
        ++length;
    }

    int size = next_target.size();

    int cur = 0;
    while(!next_target.empty()){
        int target = next_target.front();
        int target2 = next_target.back();
        int middle = length/2;
        int diff1 = get_minimum_movement(cur, target, length);
        int diff2 = get_minimum_movement(cur, target2, length);
        if(diff1 > diff2){
            target = next_target.back();
            next_target.pop_back();
        }else{
            next_target.pop_front();
        }
        answer += get_minimum_movement(cur, target, length);
        answer += get_minimum_movement('A', name[target], MAX_CHAR);
        cur = target;
    }

    return answer;
}

#endif