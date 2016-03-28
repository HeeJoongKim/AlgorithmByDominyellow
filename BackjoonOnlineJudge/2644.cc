#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int F, T;

bool graph[123][123]; //인접 배열 그래프
bool visited[123];
int ans;

void dfs(int idx, int count){
	if(idx == T){
		ans = min(ans, count); //현재 저장된 최단거리 보다 적은 거리의 탐색이 됬을 때 답을 갱신
		return;
	}

	visited[idx] = true;

	for(int i=1; i<=N; i++){
		if(graph[idx][i] && !visited[i]){
			visited[i] = true;//백트랙킹
			dfs(i, count+1);
			visited[i] = false;//백트랙킹
		}
	}
}

int main(void){
	scanf("%d", &N);
	scanf("%d %d", &F, &T);

	int m;
	scanf("%d", &m);
	int f, t;

	for(int i=0; i<m; i++){
		scanf("%d %d", &f, &t);
		graph[f][t] = graph[t][f] = true;
	}
	ans = 123123123;

	dfs(F, 0);
	//탐색을 했음에도 불구하고 초기화된 값이 답이면 탐색에 실패했음을 의미 -> -1 출력
	if(ans == 123123123){
		ans = -1;
	}
	printf("%d\n", ans);

	return 0;
}
