#if 0

#include <cstdio>
#include <iostream>
#include <queue>

#define MAX 202
#define vvi vector <vector < int > >
using namespace std;

int n,l;

int main(int argc, char** argv) {

    //freopen("sample_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    int T;
    int test_case;

    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.


        scanf("%d",&n);

        vvi arr(n+1);
        vector<int> visit(n+1, -1);

        scanf("%d",&l);

        int from, to ;
        for(int i=0;i<l;i++){
            scanf("%d %d", &from, &to);
            arr[from].push_back(to);
            arr[to].push_back(from);
        }

        queue<int> node_queue;
        node_queue.push(1);
        visit[1] = 1;
        bool ans=true;

        while( !node_queue.empty() && ans){
            int cur = node_queue.front();node_queue.pop();
            int size = arr[cur].size();

            for(int i=0;i < size; i++){
                int next = arr[cur][i];

                if(visit[next] == -1){
                    visit[next] =  3 - visit[cur];
                    node_queue.push(next);
                }

                if( visit[next] == visit[cur] ){
                    ans=false;
                }
            }
        }

        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n%d\n", test_case,ans);


    }

    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

#endif