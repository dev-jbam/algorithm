#if 0

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
//O(V+E)


int main() {

    freopen("/home/joon/sources/algorithm/build/input.txt", "r", stdin);
    int n, from, to;
    cin >> n;

    vector<vector<int> > graph(n);
    vector<int>  visited(n, 0);

    while(cin >> from >> to){
        graph[from].push_back(to);    
    }
    bool hasCycle = false;
    for(int i = 0; i < n && !hasCycle; ++i ){
        queue<int> node_queue;

        if(!visited[i]){
            node_queue.push(i);
        }
        
        while( !node_queue.empty() && !hasCycle){
            int cur = node_queue.front(); node_queue.pop();
        
            visited[cur] = true;
            
            for(int to_idx = 0; to_idx < graph[cur].size(); ++to_idx){
                int next = graph[cur][to_idx];
                if(visited[next]){
                    hasCycle = true;
                    break;
                }
            }
        }
    }

    string answer = hasCycle ? "true\n" : "false\n";

    cout << answer;    
    
    return 0;
}

#endif