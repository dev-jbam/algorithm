/*
https://programmers.co.kr/learn/courses/30/lessons/42746
가장 큰 수
문제 설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

제한 사항
numbers의 길이는 1 이상 100,000 이하입니다.
numbers의 원소는 0 이상 1,000 이하입니다.
정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
입출력 예
numbers	return
[6, 10, 2]	6210
[3, 30, 34, 5, 9]	9534330

*/

#if 0

#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare_str(const string &a, const string & b){
    return a + b < b + a;
}

int _partition(int l, int r, vector<string> &arr){

    int pivot = r;
    
    int j=l;
    for(int i = l; i < r; ++i){
        if(compare_str(arr[i], arr[pivot])){
            swap(arr[i], arr[j]);
            j++;
        }
    }

    swap(arr[j], arr[pivot]);
    return j;
}

void quick(int l , int r, vector<string> &str_v){
    if( l < r ) {
        int pivot = _partition(l,r,str_v);
        quick(l, pivot -1, str_v);
        quick( pivot + 1, r, str_v);
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> number_str;

    for(int i = 0; i < size; ++i){
        number_str.push_back( to_string(numbers[i]) );
    }

    sort(number_str.begin(), number_str.end(), compare_str);
    
    if(number_str[size - 1] == "0"){
        return "0";
    }

    for(int i = 0; i < size; ++i){
        answer = number_str[i] + answer;
    }
    return answer;
}

#endif

#if 0

#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare_str(string a, string b){
    int alen = a.length();
    int blen = b.length();
    int limit = alen < blen ? blen : alen;

    int i = 0;
    while( a[i%alen] == b[i%blen] && i < limit ){
        i++;
    }

    return a[ i % alen ] < b[ i % blen ];    
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> number_str;

    for(int i = 0; i<size ; ++i){
        number_str.push_back( to_string(numbers[i]) );
    }

    sort(number_str.begin(), number_str.end(), compare_str);
    if(number_str[size - 1] == "0"){
        return "0";
    }

    for(int i = 0; i < size; ++i){
        answer = number_str[i] + answer;
    }
    return answer;
}

#endif