#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define SIZE 1001

int N, M;

int graph[SIZE][SIZE]; //graph를 인접배열로 표현
//visited 배열 가장 중요!! 방문한 정점은 true로 방문하지 않은 정점은 false로. 방문했던 노드를 재방문 하지 않기 위함이다. 
//재방문에 의한 overhead는 상상할 수 없을정도로 크다. 문제가 절대 풀리지 않는다.
bool visited[SIZE]; 

void dfs(int n){

	visited[n] = true;
	printf("%d ", n);

	for(int i=1; i<=N; i++){
		//i번 정점을 방문한 적이 없고 n->i로의 간선이 존재하면 스택에 i를 넣는다. (재귀)
		if(!visited[i] && graph[n][i] == 1){
			dfs(i);
		}
	}
}

void bfs(int root){
	visited[root] = true;

	queue<int> q; //bfs는 큐가 필요하다.
	q.push(root); //큐에 처음 방문해야할 정점을 push한다.

	//bfs의 기본! 큐가 빌 때 까지 탐색을 한다.
	while(!q.empty()){
		int here = q.front(); //큐의 front 원소를 참조한다.
		q.pop(); //큐의 front 원소를 pop 한다.
		printf("%d ", here);

		//현재 정점에서 간선이 연결된 모든 정점을 찾는다!!
		for(int i=1; i<=N; i++){
			//i번 노드를 방문한 적이 없고, here -> i를 연결하는 간선이 존재하면 큐에 i를 넣는다.
			if(!visited[i] && graph[here][i] == 1){
				visited[i] = true;
				q.push(i);
			}
		}
	}
	printf("\n");
}

int main(void){
	int start;

	scanf("%d %d %d", &N, &M, &start);

	int f, t;

	for(int i=0; i<M; i++){
		scanf("%d %d", &f, &t);
		graph[f][t] = 1;
		graph[t][f] = 1;
	}

	memset(visited, false, SIZE); //visited배열 초기화
	dfs(start);
	printf("\n");

	memset(visited, false, SIZE); //visited배열 초기화
	bfs(start);
	return 0;
}
