/*
https://programmers.co.kr/learn/courses/30/lessons/49191

그래프
순위
도움말
컴파일 옵션
순위
문제 설명
n명의 권투선수가 권투 대회에 참여했고 각각 1번부터 n번까지 번호를 받았습니다. 권투 경기는 1대1 방식으로 진행이 되고, 만약 A 선수가 B 선수보다 실력이 좋다면 A 선수는 B 선수를 항상 이깁니다. 심판은 주어진 경기 결과를 가지고 선수들의 순위를 매기려 합니다. 하지만 몇몇 경기 결과를 분실하여 정확하게 순위를 매길 수 없습니다.

선수의 수 n, 경기 결과를 담은 2차원 배열 results가 매개변수로 주어질 때 정확하게 순위를 매길 수 있는 선수의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
선수의 수는 1명 이상 100명 이하입니다.
경기 결과는 1개 이상 4,500개 이하입니다.
results 배열 각 행 [A, B]는 A 선수가 B 선수를 이겼다는 의미입니다.
모든 경기 결과에는 모순이 없습니다.
입출력 예
n	results	return
5	[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]	2
입출력 예 설명
2번 선수는 [1, 3, 4] 선수에게 패배했고 5번 선수에게 승리했기 때문에 4위입니다.
5번 선수는 4위인 2번 선수에게 패배했기 때문에 5위입니다.

*/

#if 0


#include <string>
#include <vector>
#include <queue>

using namespace std;

struct player {
    int No;
    int win;
    int lose;
};

void find_relative_matches(vector<bool> &visited, const vector<vector<int > > &graph,  vector<player> &players, int start){
    queue<player> player_queue;
    player_queue.push(players[start]);
    visited[start]= true;

    while(!player_queue.empty()){
        player cur = player_queue.front(); player_queue.pop();

        for(int i =0; i<graph[cur.No].size(); ++i){
            int next_idx = graph[cur.No][i];
            if(visited[next_idx] == false){
                visited[next_idx]= true;
                player &next = players[next_idx];
                next.lose += cur.lose;
                player_queue.push(next); 
            }
        }        
    }
}

int solution(int n, vector<vector<int>> results) {

    vector<vector< int > > graph(n + 1);
    vector<player> players(n+1);
    vector<bool> visited(n+1,false);

    for(int i =0;i<= n;++i){
        players[i].No =i;
    }

    int size = results.size();
    for( int i = 0; i < size; ++i){
        int winner = results[i][0];
        int loser = results[i][1];
        graph[winner].push_back(loser);
        players[winner].win++;
        players[loser].lose++;
    }

    int answer = 0;
    size = graph.size();
    for(int i = 0; i <= n ; ++i ){
        if(!visited[i] && graph[i].size() != 0){
            find_relative_matches(visited, graph, players, i);
        }
    }
    for(int i =0; i<=n; ++i){
        if (players[i].win + players[i].lose == n -1) answer++;
    }

    return answer;
}
int main(){

    vector<vector<int > > input(5);
    int i =0;
    input[i].push_back(4);
    input[i++].push_back(3);
    input[i].push_back(4);
    input[i++].push_back(2);
    input[i].push_back(3);
    input[i++].push_back(2);
    input[i].push_back(2);
    input[i++].push_back(5);
    input[i].push_back(1);
    input[i++].push_back(2);

    int answer = solution(5, input);
    return 0;
}
#endif