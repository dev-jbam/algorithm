/*
https://programmers.co.kr/learn/courses/30/lessons/42839
소수 찾기
문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
입출력 예
numbers	return
17	3
011	2
입출력 예 설명
예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.

*/

#if 0
 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void count_prime(int depth, int limit, vector<bool> used, int target, const string &numbers, vector<bool> &prime_number){
    if(depth == limit){
        if(prime_number[target]){
            prime_number[target]=false;
            answer++;
        }
        return;
    }
    count_prime(depth + 1, limit, used, target, numbers, prime_number);
    for(int i = 0; i< limit; ++i){
        if(!used[i]){
            used[i] = true;
            count_prime(depth + 1, limit, used, target * 10 + numbers[i] - '0', numbers, prime_number);
            used[i] = false;
        }
    }
}


int solution(string numbers) {
    int max_size = 10000000;
    vector<bool> prime_number(max_size, true);

    prime_number[0] = prime_number[1] = false;
    for(int i = 2; i * i < max_size; i++){
        for(int k = i * 2; k < max_size; k += i){
            prime_number[k] = false;
        }
    }
    int length = numbers.length();
    vector<bool> used(length,false);
    count_prime(0,length, used, 0,numbers,prime_number);
    return answer;
}

#endif