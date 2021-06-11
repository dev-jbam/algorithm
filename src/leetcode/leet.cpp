#if 0

#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    int findLatestStepWithNSquare(vector<int>& arr, int m) {
        int len = arr.size();
        if(m==len) return len;
        vector<int> cumulativeSum(len+1,0);
        for(int i=0; i<=len; ++i){
            cumulativeSum[i]=i;
        }

        for(int i=len-1; i>=0; --i){
            int idx = arr[i];
            cumulativeSum[idx] = 0;

            int k = idx+1;
            while(k<=len && cumulativeSum[k]){
                cumulativeSum[k] = (cumulativeSum[k-1]+1);
                ++k;
            }
  
            if(cumulativeSum[idx-1] == m || cumulativeSum[k-1] == m ){
                return i ;
            }
        }
        return -1;
    }

    int findLatestStepWithNSquare(vector<int>& arr, int m) {
        int len = arr.size();
        if(m==len) return len;
        vector<int> cumulativeSum(len+1,0);
        for(int i=0; i<=len; ++i){
            cumulativeSum[i]=i;
        }

        for(int i=len-1; i>=0; --i){
            int idx = arr[i];
            cumulativeSum[idx] = 0;

            int k = idx+1;
            while(k<=len && cumulativeSum[k]){
                cumulativeSum[k] = (cumulativeSum[k-1]+1);
                ++k;
            }
  
            if(cumulativeSum[idx-1] == m || cumulativeSum[k-1] == m ){
                return i ;
            }
        }
        return -1;
    }
};

int main(){

    int arr[]={3,5,1,2,4};
    vector<int> input(arr, arr + 5);
    
    Solution solution;
    cout << solution.findLatestStep(input,1) << '\n';

    return 0;

}

#endif