/*
 *983. Minimum Cost For Tickets
User Accepted: 726
User Tried: 943
Total Accepted: 739
Total Submissions: 1500
Difficulty: Medium
In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.
 

Note:

1 <= days.size <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.size == 3
1 <= costs[i] <= 1000 
 */
 
 
 #if 0

#include <vector>
#include <algorithm>

#define TICKET_TYPES 3
#define ONEDAY 1
#define SEVEN_DAYS 7
#define THIRTY_DAYS 30

int covered[3] = {ONEDAY, SEVEN_DAYS, THIRTY_DAYS};

#define MAX 3650000

using namespace std;

int min(const int& a, const int& b){
    return a < b ? a : b;
}

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.size();
        int last_day = days[size -1];

        vector<vector<int> > minimum_cost;
        for(int i  = 0; i < TICKET_TYPES; ++i){
            vector<int > vi(last_day+2, MAX);
            vi[0]=0;
            minimum_cost.push_back(vi);
        }

        int prev = 0;
        int cur = 0;
        for(int i = 0; i < size; ++i) {
            cur = days[i];
            for(int day_idx = prev + 1; day_idx < cur; ++day_idx){
                for(int k=0; k<TICKET_TYPES; ++i){
                    minimum_cost[k][day_idx] = minimum_cost[k][day_idx -1];
                }
            }
            for(int k=0; k<TICKET_TYPES; ++i){
                int prevday = cur - covered[k];
                if( prevday < 0) continue;
                minimum_cost[k][cur] = minimum_cost[k][prevday];
            }


            prev = cur;
        }
    }
};

int main(){
    int size = 30;
    vector<int> arr(size);
    for(int i = 0; i< size; ++i){
        arr[i] = i /3;   
    }

    int l =0, r = size -1;
    int mid = 0;
    int target = 8;
    while( l < r){
        mid = ( l + r ) /2;
        if( arr[mid] <= target){
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    auto upper = upper_bound(arr.begin(), arr.end(), target);
    bool ret = *upper == arr[l];

    l =0; r = size -1;
    mid = 0;
    target = 8;
    while( l < r ){
        mid = ( l + r ) /2;
        if( arr[mid] < target){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    auto lower = lower_bound(arr.begin(), arr.end(), target);
    bool ret_lower = *lower == arr[l];

	return 0;
}

 #endif