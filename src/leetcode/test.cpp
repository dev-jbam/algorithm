#if 0

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class solution {

public:
    int solve(int v, vector<vector<int > > &bridges){
        vector< vector< int > > map(v+1);    
        vector<bool> visited(v+1, false);
        int size = bridges.size();
        for(int i= 0;i<size; ++i){
            int from = bridges[i][0];
            int to = bridges[i][1];
            map[from].push_back(to);
            map[to].push_back(from);
        }

        int island_count=0;
        for(int i = 1; i <= v; ++i){
            if(!visited[i]){
                island_count++;
                visit_bfs(map, visited, i);
            }
        }
        return island_count-1;
    }
private:
    void visit_bfs(vector<vector<int> >& map, vector<bool>& visited, int start){
        visited[start]= true;

        queue<int> island_queue;
        island_queue.push(start);

        while(!island_queue.empty()){
            int cur = island_queue.front(); island_queue.pop();

            for(int i=0; i< map[cur].size(); i++){
                int next = map[cur][i];
                if(!visited[next]){
                    visited[next]= true;
                    island_queue.push(next);
                }
            }
        }
    }
};

int main(){
    vector<vector<int> > input(3);
    int i =0;
    input[i].push_back(1);
    input[i++].push_back(2);
    input[i].push_back(2);
    input[i++].push_back(3);
    input[i].push_back(4);
    input[i++].push_back(5);

    solution s;

    cout << "test out : " << s.solve(6,input);
    
    return 0;
}


#endif