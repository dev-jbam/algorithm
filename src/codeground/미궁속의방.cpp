#if 0

#include <cstdio>
#include <cstring>

#define size 300333


int n, k;
char input[size];
int tcase;

int x, y;

int getX(int curX, char dir){
	int nx = curX;
	if (dir == 'D' || dir== 'U')
		return nx;
	else if (dir == 'L') return nx - 1;
	else return nx + 1;
}

int getY(int curY, char dir){
	if (dir == 'L' || dir == 'R')
		return curY;
	else if (dir == 'U') return curY - 1;
	else return curY + 1;
}


long long getNumber(long long llnum){
	
	return llnum * (llnum + 1) / 2;
}

long long getPosition(int x, int y){ 
	
	long long tmp = (long long)x + (long long)y - 1; // tmp는 현재 순행

	if (tmp <= n){
		long long r = getNumber(tmp - 1);

		//좌표 짝수는  위 -> 아래 (y), 홀수는 아래 -> 위 x
		if ((tmp) % 2){
			r = (r + (long long)x);
		}
		else r = (r + (long long)y);


		return r;
	}
	
	//n 순행보다 큰 경우 숫자는 감소한다. 몇개 감소한지 확인
	else{
		long long r = getNumber(n);
				
		long long  margin = tmp - n; 
	
		long long tmpSum = getNumber(n - 1);
		tmpSum = tmpSum - getNumber(n - margin );

		r += tmpSum;
		// 1일 때 2, 3일때 4, 5일때 6
		if (tmp % 2) r =  r + x - margin;
		else r = r + y - margin;
				
		return r;

	}

}


long long lln, llk, llx, lly, lltotal;


int main(void){

//	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);



	scanf("%d", &tcase);


	for (int t = 1; t <= tcase; t++)
	{

		scanf("%d %d", &n, &k);
		scanf("%s", input);

		lln = 1;
		x = 1; y = 1;
		for (int i = 0; i < k; i++){
			char dir = input[i];
			
			x = getX(x, dir);
			y = getY(y, dir);
			
			lln = lln +  getPosition(x, y);
			//printf("--%lld\n", lln);
		}
		
		printf("Case #%d\n", t);
		printf("%lld\n", lln);
	}


	return 0;
}


#endif