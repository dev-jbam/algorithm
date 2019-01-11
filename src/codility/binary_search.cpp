#if 0

#include <vector>
#include <math.h>
#include <time.h>
#include <algorithm>

using namespace std;
int binary_search(vector<int>& A, int target) {
    int N = A.size();
    if (N == 0) {
        return -1;
    }
    int l = 0;
    int r = N - 1;
    while (l < r) {
        int m = (l + r) / 2;

        if( A[m] == target) return m;
        
        if (A[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (A[l] == target) {
        return l;
    }
    
    return -1;
}
int main(){

    srand(time(NULL));
    int size = 100;
    vector<int> vi;
    for(int i =0; i< size; ++i){
        vi.push_back(rand()%50);
    }

    sort( vi.begin(), vi.end());
    for(int i =0; i< size; ++i){
        int ret = binary_search(vi, vi[i]);
        if( vi[ret] != vi[i] ){
            break;
        }    
    }

    return 0;
}


#endif