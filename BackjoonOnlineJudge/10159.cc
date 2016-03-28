#include <stdio.h>

int graph[123][123];
int visited[123]; // 보다 가벼운 물건들은 true로
int r_visited[123]; // 보다 무거운 물건들은 true로

int N;

//가벼운 물건을 탐색하는 순 방향 dfs
void dfs(int n){
	visited[n] = true;
	for(int i=1; i<=N; i++){
		if(graph[n][i] == 1 && !visited[i]){
			dfs(i);
		}
	}
}

//무거운 물건을 탐색하는 역 방향 dfs
void rev_dfs(int n){
	r_visited[n] = true;
	for(int i=1; i<=N; i++){
		if(graph[i][n] == 1 && !r_visited[i]){
			rev_dfs(i);
		}
	}
}

int main(void){
	scanf("%d", &N);

	int E;
	scanf("%d", &E);

	int f, t;
	for(int i=0; i<E; i++){
		scanf("%d %d", &f, &t);
		graph[f][t] = 1;
	}

	for(int i=1; i<=N; i++){
		//초기화
		for(int j=1; j<=N; j++){
			visited[j] = false;
			r_visited[j] = false;
		}

		dfs(i);
		rev_dfs(i);

		int count = 0;
		for(int j=1; j<=N; j++){
			if(visited[j] || r_visited[j]){
				count += 1;
			}
		}
		printf("%d\n", N-count);
	}
	return 0;
}
