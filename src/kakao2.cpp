#if 0

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

#define MAX_ITEM 1000000

int item_count[MAX_ITEM + 1];

void init(){
    memset(item_count, 0, MAX_ITEM +1);
}

void count_items(int *items, int n){

    for(int i = 0; i< n; ++i){
        item_count[items[i]]++;
    }
    
    for( int i= 0; i<n; ++i){
        if( item_count[i]!= 0){
            priority_queue<pair<int,int>>
        }
    }
}



string pattern;
int max_day;
int total_work_hour;
void find_totalhour(int cur_day, int cur_total_hour, string prev_pattern, vector<string> &answer){    
    
    if(pattern[cur_day] == '?' ){
        for(int i = 0; i<= 8; ++i){
            if( cur_total_hour + i == total_work_hour){
                string cur_pattern = prev_pattern + i_to_char(i);
                
                if(cur_day == max_day){
                    answer.push_back(cur_pattern);
                }else{
                    find_totalhour(cur_day +1, cur_total_hour+ i, cur_pattern, answer);
                }
            }
            if( cur_total_hour + i > total_work_hour){
                break;
            }
        }
    } else {
        int curday_hour = char_to_i(pattern[cur_day]);
        if(cur_day == max_day && total_work_hour == cur_total_hour + curday_hour) {
            string new_answer = prev_pattern + pattern[cur_day];
            answer.push_back(new_answer);
        }
        if( total_work_hour < cur_total_hour + curday_hour){
            find_totalhour(cur_day+ 1, cur_total_hour + curday_hour, prev_pattern + pattern[cur_day], answer);
        }

    }
}

char i_to_char(int i){
    if(0 <= i && i<=9){
        return i + '0';
    }
    return 0;
}
int char_to_i (char a){
    return a -'0';
}

int main(){

    return 0;
}

#endif