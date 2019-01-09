#if 1

#include <cstdio>
#include <iostream>
#include <functional>
#include <queue>
#include <vector>

#define INF 1010123456
#define MAX 100001


using namespace std;
/*
int weight,
int to,
int root
*/
struct node{
	int weight;
	int to;
	int root;

	node(int w, int t, int r) :weight(w), to(t), root(r){}
	node() : weight(0), to(0), root(0){}

	bool operator > (const struct node &rhs)const{
		return weight > rhs.weight;
	}

};

typedef struct node node;


int visit[MAX];// 대피소의 번호를 저장하고 있는다.
int dist[MAX]; // 가장 가까운 어떤 대피소 까지의 거리를 저장한다. 
bool isEvac[MAX];
int n, m, k;

// graph[i].first = to 노드
// graph[i].second = 간선 가중치
// pq 의 first는 가중치 second는 노드
int dijkstra(vector< vector< pair< int, int > > > &graph , priority_queue < node, vector<node>, greater<node> >  &pq ){
	
	while (pq.empty() == false){
		
		int cur = pq.top().to;
		int weight = pq.top().weight;
		int root = pq.top().root;
		pq.pop();


		for (int i = 0; i < graph[cur].size(); i++){
			int next = graph[cur][i].first;
			int nweight = graph[cur][i].second;

			if (dist[next] > dist[cur] + nweight){
				dist[next] = dist[cur] + nweight;
				visit[next] = root;
				node tmp(dist[next], next, root);
				pq.push(tmp);
			}
			
			if (dist[next] == dist[cur] + nweight ){
				if (visit[next] > root) visit[next] = root;
				node tmp(dist[next], next, visit[next]);
				pq.push(tmp);
			}
		}
	}

	long long int sum = 0;
	long long int nodeSum = 0;

	for (int i = 1; i <= n; i++){
		sum += dist[i];
		nodeSum += visit[i];
	}
	
	printf("%lld\n%lld\n", sum, nodeSum);

	return 0;
}

int main(int argc, char** argv) {
	
	//freopen("input.txt", "r", stdin);

	
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		
		scanf("%d %d %d", &n, &m, &k);

		for (int i = 1; i <= n; i++){
			dist[i] = INF;
			visit[i] = 0;
			isEvac[i] = 0;
		}
		
		vector< vector< pair< int, int > > > graph(n + 1); 

		int from, to, weight;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &from, &to, &weight);
			graph[from].push_back(make_pair(to, weight));
			graph[to].push_back(make_pair(from, weight));
		}

		// pq 의 first는 가중치 second는 노드
		priority_queue < node, vector<node>, greater<node> > pq;
		for (int i = 0; i < k; i++){
			scanf("%d", &from);
			isEvac[from] = true;
			dist[from] = 0;
			visit[from] = from;
			node tmp(0,from,from);

			pq.push(tmp);
		}
		
		printf("Case #%d\n", test_case);

		int ret = dijkstra(graph, pq);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

#endif