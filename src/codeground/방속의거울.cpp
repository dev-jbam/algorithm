#if 0

#include <cstdio>
#include <cstring>

#define size 1111
#define E 0
#define W 1
#define S 2
#define N 3

char map[size][size];

bool visited[size][size];

//동서남북 다음 좌표값을 위한 배열
int dirX[4] = { 1, -1, 0, 0 };
int dirY[4] = { 0, 0, 1, -1 };

/*방의 타입에 따른  현재방에
  레이저가 들어오면 나가는 방향 1.동, 2.서, 3.남, 4.북*/
int in_out[3][4] = {
	{ W, E, N, S }, 
	{ S, N, E, W }, // / 거울
	{ N, S, W, E }  // \ 거울
};

int room_counter; //지나간 방의 개수
int direction; //빛이 들어가는 방향
int tcase, n;

/*
현재 방에서 나가는 빛은 다음 방에 들어오는 방향의 반대
빛 방향을 바꿔서 리턴
*/
int reverseDirection(int dir){

	if (dir == E) return W;
	if (dir == W) return E;
	if (dir == S) return N;
	if (dir == N) return S;
}

int main(void){


	setbuf(stdout, NULL);
	
	scanf("%d", &tcase);

	for (int t = 1; t <= tcase; t++){
	
		memset(map, -1, sizeof(map));
		memset(visited, 0, sizeof(visited));

		scanf("%d", &n);

		for (int y = 1; y <= n; y++){
			for (int x = 1; x <= n; x++){
				scanf("%1d", &map[y][x]);
			}
		}

		int cx = 1, cy = 1; //제일 위 왼쪽 끝
		room_counter = 0; 
		direction = W; //서쪽에서 들어옴

		while (map[cy][cx] != -1){

			int roomtype = map[cy][cx];
			int outDirection = in_out[roomtype][direction];

			int nextX = cx + dirX[outDirection];
			int nextY = cy + dirY[outDirection];

			
			if ( !visited[cy][cx] && roomtype) {
				visited[cy][cx] = true;
				room_counter++;
			}

			cy = nextY;
			cx = nextX;
			direction = reverseDirection(outDirection); //다음 방은 들어가는 빛의 반대

		}

		printf("Case #%d\n", t);
		printf("%d\n",room_counter);

	}



	return 0;
}

#endif