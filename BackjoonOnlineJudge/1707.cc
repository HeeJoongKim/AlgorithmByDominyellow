#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int V, E;
vector<vector<int> > graph;

int bi[21212]; // -1아직 노방문, 0 파란색, 1빨간색

bool bfs(int s){

	bi[s] = 0; //파란색으로 초기화
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int n = q.front();
		q.pop();
		int dir = bi[n]; //현재 노드의 색
		int ndir = !dir; //현재 노드의 색이 0이면 연결된 노드는 1, 현재 노드의 색이 1이면 연결된 노드의 색은 0

		int len = graph[n].size();
		for(int i=0; i<len; i++){
			//연결된 노드가 방문한 적이 없다면
			if(bi[graph[n][i]] == -1){
				bi[graph[n][i]] = ndir; //자기 자신과 반대 색을 입히고 탐색을 계속 진행
				q.push(graph[n][i]);
			}
			//연결된 노드가 이미 방문한 상태임과 동시에 자기 자신과 같은색이면 더 볼 것도 없이 이분 그래프다 아니다.
			else if(bi[graph[n][i]] == dir){
				return false;
			}
		}
	}

	return true;
}

int main(void){
	int testcase;
	scanf("%d", &testcase);

	while(testcase--){

		scanf("%d %d", &V, &E);
		graph.clear();
		graph.resize(V+1);
		for(int i=1; i<=V; i++){
			graph[i].clear();
		}

		int f, t;
		for(int i=0; i<E; i++){
			scanf("%d %d", &f, &t);
			graph[f].push_back(t);
			graph[t].push_back(f);
		}

		memset(bi, -1, (V+1)*sizeof(int));
		bool res = true;
		//1 ~ V 까지 모든 노드를 출발점으로 이분그래프인지 확인하는 탐색을 진행한다. (모든 연결 요소에 대해 탐색한다.)
		for(int i=1; i<=V; i++){
			if(bi[i] == -1){
				res &= bfs(i); // res와 &(and 연산)을 한다. 한번이라도 false가 나오면 이분그래프다 아니다.
				// (한개의 연결소요라도 이분 그래프가 아닐 땐 전체가 이분 그래프가 아니다.)
			}
		}

		if(res){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}
