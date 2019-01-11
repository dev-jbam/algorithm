
#if 0
#include <set>
#include <vector>

using namespace std;

class Solution{
public:
    int solution(vector<int> weights, vector<int> target_floors, int highest, int limit_people, int limit_weight) {
        int size = weights.size();
        set<int> floor_set;
        int answer = 0;
        for(int i =0; i < size; ){
            set<int> floor_set;
            int weight_sum = 0;
            int people_count = 0;
            while( i < size && people_count < limit_people && weight_sum + weights[i] <= limit_weight ){
                weight_sum+=weights[i];
                if( floor_set.find(target_floors[i]) == floor_set.end()){
                    floor_set.insert(target_floors[i]);
                }
                people_count++;
                i++;
            }
            answer += (floor_set.size() + 1); // include returned to ground 
        }
        return answer;
    }
};

int main(){
    int a[3] ={ 60,80,40 };
    int b[3] ={ 2,3,5 };
    vector<int> A(a, a + sizeof a / sizeof a[0]);
    vector<int> B(b, b + sizeof b / sizeof b[0]);

    Solution s;
    int ret = s.solution(A, B, 5, 2, 200);

    int c[5] = { 40,40,100,80,20  } ;
    int d[5] = { 3,3,2,2,3  };
    vector<int> C(c, c + sizeof c / sizeof c[0]);
    vector<int> D(d, d + sizeof d / sizeof d[0]);
    int ret2= s.solution(C,D,3,5,200);


    int e[10] = { 100,100,100,100,100,100,100,100,100,100  } ;
    int f[10] = { 1,2,3,4,5,6,7,8,9,10  };
    vector<int> E(e, e + sizeof  e/ sizeof e[0]);
    vector<int> F(f, f + sizeof  f/ sizeof f[0]);
    int ret3= s.solution(E,F,10,10,1000);


    return 0;
}


#endif