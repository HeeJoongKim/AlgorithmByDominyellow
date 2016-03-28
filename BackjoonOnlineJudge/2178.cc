#include <stdio.h>
#include <queue>

using namespace std;

typedef struct{
	int x;
	int y;
	int t;
}POINT;

int x_move[4] = {0, 1, 0, -1};
int y_move[4] = {1, 0, -1, 0};

int main(void){
	int N, M;
	char cgraph[123][123];
	int graph[123][123]={};

	scanf("%d %d", &N, &M);

	for(int i=1; i<=N; i++){
		scanf("%s", cgraph[i]+1);
	}

	//계산의 편의를 위해서 int형 2차원 배열로 옮긴다.
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			graph[i][j] = cgraph[i][j]-'0';
			//움직일 수 있는 칸이지만 아직 방문 안한 칸을 -1로
			if(graph[i][j] == 1){
				graph[i][j] = -1;
			}
		}
	}

	//BFS 시작
	queue<POINT> q;
	POINT p = {1, 1, 1};
	q.push(p);

	graph[1][1] = 1;
	int x, y, t;

	while(!q.empty()){
		p = q.front();
		q.pop();

		x = p.x;
		y = p.y;
		t = p.t;

		for(int i=0; i<4; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];

			if(graph[nx][ny] == -1){
				graph[nx][ny] = t+1;// 인접한 다음 칸에 현재 칸의 거리+1을 넣는다.
				POINT t_p = {nx, ny, t+1};
				q.push(t_p);
			}
		}
	}

	//목적지인 오른쪽 아래칸에 채워진 숫자를 출력하면 답이 된다.
	printf("%d\n", graph[N][M]);


	return 0;
}
