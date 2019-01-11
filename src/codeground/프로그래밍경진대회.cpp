#if 0

#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

#define size 2000022


int arr[size];

bool cmp(int i, int j) {
	return i > j ? true : false;
}

int n;

int counter;

int difSum[size];

//nlogN바이너리서치

int winCheck(int cur, int num){


	for (int i = 1; i < cur; i++){
		if (arr[i] + i > num) return 0;	
	}
	return 1;
}
bool visited[size];
//[first, last]
int doBiSearch(int first, int last){
	int mid = (first + last) / 2;

	
	//나의 바로 오른쪽 것 까지 본 후 안된것이다.
	if (last < first){
	}

	if (first > last){
	}// 나의 바로 왼쪽이나 나자신을 봤지만 안된것

	if (visited[mid]) return 1;
	

	//방문한 지점이 된다면 나보다 작은 수들을 확인한다.
	if (winCheck(mid, arr[mid] + n)){
		memset(visited + 1 , true, sizeof(bool)*mid);
		doBiSearch(mid + 1, last);
		
	}
	//방문한 지점이 안된다면 나보다 큰 수를 확인한다.
	else{
		doBiSearch(first, mid - 1);
	}
}

using namespace std;

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
    
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
        scanf("%d", &n);
	
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

        std::sort(&arr[1], arr + n + 1,cmp);
    
        for (int i = 1; i <= n; i++) arr[i] -= arr[n];
    
        memset(visited, 0, size);
    	counter= 0;
        doBiSearch(1, n);
        
        for (int i = 1; i <= n; i++) 
            if (visited[i])	
                counter++;
        
        
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%d\n", counter);
        
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

#endif