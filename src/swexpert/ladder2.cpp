#if 0
#include <cstdio>
  
#define OUT -1
#define WALL 0
#define LADDER 1
#define MAX 102
#define LEFT 0
#define RIGHT 1
#define UP 2
  
int map[MAX][MAX];
int dx[3] = { -1, 1, 0 };
int dy[3] = { 0, 0, -1 };
  
struct coordi{
    int x;
    int y;
};
  
struct answer{
    int x;
    int count;
};
  
  
int iimax(int a, int b){
    return a < b ? b : a;
}
  
coordi go_up(coordi cur, int dir){
    coordi next = cur;
    while (map[next.y + dy[dir]][next.x + dx[dir]] >= LADDER){
        next.x += dx[dir];
        next.y += dy[dir];
        map[next.y][next.x] = map[cur.y][cur.x] + LADDER;
        cur = next;
        if (map[next.y + dy[LEFT]][next.x + dx[LEFT]] >= LADDER
            || map[next.y + dy[RIGHT]][next.x + dx[RIGHT]] >= LADDER){
            return next;
        }
    }
  
    return next;
  
}
  
coordi go_side(coordi cur, int dir){
  
    coordi next = cur;
  
    while (map[next.y + dy[dir]][next.x + dx[dir]] >= LADDER){
        next.x += dx[dir];
        next.y += dy[dir];
        map[next.y][next.x] = map[cur.y][cur.x] + LADDER;
        cur = next;
    }
  
    return next;
}
  
int find_direction(coordi cur, int except){
  
    for (int i = 0; i < 3; i++){
        if (map[cur.y + dy[i]][cur.x + dx[i]] >= LADDER ){
            if (i == except){
                continue;
            }
            return i;
        }
    }
    return OUT;
}
  
  
int get_except_direction(int dir){
    return  dir == UP ? UP: dir == LEFT ? RIGHT : LEFT;
}
  
  
void find_route(coordi dst){
          
    int dir = 0;
    int except_dir = -1;
    while (true){
          
        if (dir == OUT){
            return;
        }
        if (dir == UP){
            dst = go_up(dst, UP);
        }
        else{
            dst = go_side(dst, dir);
        }
        except_dir = get_except_direction(dir);
        dir = find_direction(dst, except_dir);
    }
}
  
void solution(const int t){
    for (int i = 1; i < MAX - 1; i++){
        int end = MAX - 2;
        if (map[end][i] == 1){
            coordi tmp = { i, end};
            find_route(tmp);
        }
    }
    answer ans = { -1, MAX*MAX };
    for (int i = 1; i < MAX - 1; i++){
        if (map[1][i] > 1){
            if (ans.count >= map[1][i]){
                ans.count = map[1][i];
                ans.x = i;
            }
        }
    }
  
    printf("#%d %d\n", t, ans.x - 1);
  
}
  
void get_input(int &t){
    scanf("%d", &t);
    int cnt = 0;
    for (int i = 1; i < MAX - 1; i++){
        for (int k = 1; k < MAX - 1; k++){
            scanf("%d", &map[i][k]);
        }
    }
}
  
void init(){
  
    for (int i = 0; i < MAX; i++){
        map[0][i] = WALL;
        map[MAX - 1][i] = WALL;
        map[i][0] = WALL;
        map[i][MAX - 1] = WALL;
    }
}
  
int main(){
  
    init();
    for (int t = 1; t <= 10; t++){
        int ans = 0;
        get_input(t);
        solution(t);        
    }
  
    return 0;
}
  
  
#endif