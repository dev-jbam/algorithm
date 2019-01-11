#if 0
#include <cstdio>
#include <cstring>

#define BILLION 1000000011

bool point[BILLION];

int jump_count, destination, current;

int main(void) {

	setbuf(stdout, NULL);

	//freopen("sample_input.txt", "r", stdin);

	int TC;
	int test_case;
	int n, k;
	scanf("%d", &TC);

	for (test_case = 1; test_case <= TC; test_case++) {
		
		scanf("%d", &n);
		int loc = 0;

		memset(point, 0, sizeof(point));
		for (int i = 1; i <= n; i++){
			scanf("%d", &loc);
			point[loc] = true;
		}
		scanf("%d", &k);


		point[0] = true;
		destination = loc;
		loc = 0;
		int checker = 0;
		jump_count = 0;

		while (loc != destination){
			if (loc + k > destination){
				jump_count++;
				break;
			}
				
			for (checker = k; checker > 0; checker--){
				if (point[checker + loc]){ 
					loc += checker; 
					jump_count++; 
					break; 
				}
			}
			
			if (checker == 0){
				jump_count = -1;
				break;
			}
		}



		printf("Case #%d\n", test_case);
		printf("%d\n", jump_count);		
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
#endif