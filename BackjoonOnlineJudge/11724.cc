#include <stdio.h>
#include <queue>
#include <vector>
 
using namespace std;
 
int N, M;
vector<vector<int> > graph;
 
bool visited[1234];
 
int main(void){
 
    scanf("%d %d", &N, &M);
    graph.resize(N+1);
 
    int f, t;
    for(int i=0; i<M; i++){
        scanf("%d %d", &f, &t);
        graph[f].push_back(t);
        graph[t].push_back(f);
    }
 
    int res = 0;
    int v_cnt = 0; //현재까지 탐색을 완료한 노드의 개수
 
    while(true){
		
		//탐색한 정점의 개수가 정점의 총 개수와 같아지면 while문을 종료한다.
        if(v_cnt == N){
            break;
        }
 
        int n; //탐색의 시작 정점을 찾는다.
        for(n=1; n<=N; n++){
			//1 ~ N 까지 반복문을 돌려서 visited배열에서 false가 처음 나오는 번호를 찾는다.
            if(!visited[n]){
                break;
            }
        }
 
        visited[n] = true; //찾아진 정점을 시작정점으로 하여 bfs 탐색을 시작한다.
        res += 1; //연결요소의 개수 +1
        v_cnt += 1; //전체 탐색된 정점의 개수 +1

		//BFS 시작
        queue<int> q;
        q.push(n);
 
        while(!q.empty()){
            int node = q.front();
            q.pop();
 
            int len = graph[node].size();
 
            for(int i=0; i<len; i++){
                if(!visited[graph[node][i]]){
                    visited[graph[node][i]] = true;
                    v_cnt += 1; //BFS 탐색에서도 방문한 정점의 개수를 +1 한다.
                    q.push(graph[node][i]);
                }
            }
        }
    }
 
    printf("%d\n", res);
 
    return 0;
}
