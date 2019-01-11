#if 0

#include <cstdio>

#define MAX 101
#define INFI 99999

int arr[MAX][MAX];

int n,m,ticket;

int main(void) {

    setbuf(stdout, NULL);

    int T;
    int test_case;

    scanf("%d", &T);

    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

        scanf("%d %d %d", &n,&m,&ticket);

        int from, to, cost;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                arr[i][j] = INFI;
            }
            arr[i][i] = 0;
        }

        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&from, &to,&cost);
            arr[from][to]=cost;
            arr[to][from]=cost;
            
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if( arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
        
        int p;
        scanf("%d",&p);

        int ans=0;


        for(int x=0; x<p; x++){
            scanf("%d %d", &from, &to);
            if(arr[from][to]> ticket) ans++;
        }



        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%d\n", ans);

    }

    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

#endif