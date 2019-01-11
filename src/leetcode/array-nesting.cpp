//https://leetcode.com/problems/array-nesting/submissions/
#if 0

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        vector<int> path_len(len, 0);
        int max = 0; 
        for(int i = 0 ; i < len; ++i){
            if( path_len[nums[i]] == 0 ) {
                int ret = traversal(nums, path_len, i);
                max = max < ret? ret: max;
            }
        }
        return max;
    }
    
private:
    int traversal(vector<int> &nums, vector<int> &path_len, int cur_idx){
        stack<int> visited;
        int cur = cur_idx;
        while(path_len[cur] == 0){
            path_len[cur]++;
            visited.push(cur);
            cur = nums[cur];
        }

        int prev_len = path_len[cur] == 1 ? 0 : path_len[cur];
    
        while(!visited.empty()){
            cur = visited.top(); visited.pop();
            path_len[cur] += prev_len;
            prev_len = path_len[cur];
        }

        return path_len[cur_idx];
    }
};

#endif