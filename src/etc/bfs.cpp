#if 0
#include <vector>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

struct point{
    int x;
    int y;
    int diretion; // 물이 흘러들어오는 방향 ( <- 동쪽에서부터 온다. 서쪽에서부터 온다 ->)
};

int get_direction(int curDir, int pipetype){
    if(curDir == NORTH){
        if(pipetype==2){
           return EAST;
        }
        if(pipetype == 3){
            return WEST;
        }
        if( pipetype ==5 || pipetype ==7){
            return NORTH;
        }
    }

    else if(curDir == EAST){
        if( pipetype == 3){
           return SOUTH;
        }
        if(pipetype == 4){
            return NORTH;
        }
        if( pipetype ==6 || pipetype ==7){
            return EAST;
        }
    }

    else if(curDir == SOUTH){
        if( pipetype == 1){
           return EAST;
        }
        if(pipetype == 4){
            return WEST;
        }
        if( pipetype ==5 || pipetype ==7){
            return SOUTH;
        }
    }

    else if(curDir == WEST){
        if( pipetype == 1){
           return NORTH;
        }
        if(pipetype == 2){
            return SOUTH;
        }
        if( pipetype ==6 || pipetype ==7){
            return WEST;
        }
    }

    // imposibble
    return -1;
}

int find_max_path(point cur, vector< vector < int > > &map, int depth){

    int next_idx = (cur.diretion+2) % 4;
    
    point next_point = point( cur.x + dx[next_idx], cur.y + dy[next_idx], 0);
    int next_dir = get_direction( cur.diretion, map[ next_point.y ][ next_point.x ] );
    if(next_dir == -1) return depth;

    return find_max_path(next_point, map, depth +1);
}


pair<int, int> find_start(vector<vector<int>> map ){
    for(int i=0;i < map.size(); ++i){
        for(int j=0; j< map[i].size(); ++j){
            if(map[i][j] > 7){
                return pair<int,int>(i,j);
            }
        }
    }
}
#endif
