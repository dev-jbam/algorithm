
#if 0
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> count;
        multiset<int> num_set;
        for(int i =len -1; i>=0; --i){
            num_set.insert(nums[i]);
            auto iter = num_set.lower_bound(nums[i]);
            count.push_back(std::distance(num_set.begin(), iter));
        }
    }
    reverse(count.begin(), count.end());
};
int main(){
    Solution s;
    int input[6]={-1,-1,-2,-2,0,0};
    std::vector<int> v(input, input + sizeof input/sizeof input[0]);
    
    s.countSmaller(v);
    return 0;
}

#endif