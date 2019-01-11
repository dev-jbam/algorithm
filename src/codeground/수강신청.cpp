#if 0


#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 5001
#define MAX_M 10001

using namespace std;
bool credits[MAX_M];
int main(int argc, char** argv) {
	//freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	int test_case;
   
	scanf("%d",&T);
	for(test_case = 1; test_case <= T; test_case++) {
        
		int n,m;

		scanf("%d %d",&n, &m);
		vector<int> arr(n+1);

		credits[0]=true;
		for(int j=1;j<=n;j++){
			scanf("%d", &arr[j]);
			for(int  i=arr[j]; i<=m; i++){
				credits[i] = credits[i] + credits[i-arr[j]];
			}
		}

		int ans =0;
		for(int i=m;i>0;i--){ 
			if(credits[i]){
				ans = i; break;
			}
		}
		printf("Case #%d\n%d\n", test_case,ans);
        
	}

	return 0;	
}

#endif