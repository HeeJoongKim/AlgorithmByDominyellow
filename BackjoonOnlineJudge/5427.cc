#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int x_move[4] = {0, 1, 0, -1};
int y_move[4] = {1, 0, -1, 0};

int R, C;

char field[1002][1002];
int fires[1002][1002]; //불이 번지는 시간을 저장한 배열

typedef struct POINT{
	int x;
	int y;
	int t;
};

queue<POINT> q;

//불이 번지는 시간을 저장하는 BFS
void fire_bfs(){
	while(!q.empty()){
		POINT p = q.front();
		int x, y, t;
		x = p.x;
		y = p.y;
		t = p.t;
		q.pop();

		int nx, ny;
		for(int i=0; i<4; i++){
			nx = x + x_move[i];
			ny = y + y_move[i];

			if((fires[nx][ny] == -1 || fires[nx][ny] > t+1) && (field[nx][ny] =='@' || field[nx][ny] =='.')){
				fires[nx][ny] = t+1;
				POINT np = {nx, ny, t+1};
				q.push(np);
			}
		}
	}
}

int bfs(int sx, int sy){
	q = queue<POINT>();
	POINT p = {sx, sy, 0};
	q.push(p);

	while(!q.empty()){
		POINT p = q.front();
		int x, y, t;
		x = p.x;
		y = p.y;
		t = p.t;
		q.pop();

		int nx, ny;
		for(int i=0; i<4; i++){
			nx = x + x_move[i];
			ny = y + y_move[i];

			if(nx == 0 || nx == R+1 || ny == 0 || ny == C+1){
				return t+1;
			}

			// 불이 번지는 시간보다 빨리 갈 수 있는 방으로만 탐색
			if((fires[nx][ny] == -1 || fires[nx][ny] > t+1) && field[nx][ny] !='#' && field[nx][ny] != '@'){
				field[nx][ny] = '@';
				POINT np = {nx, ny, t+1};
				q.push(np);
			}
		}
	}
	return -1;
}

int main(void){
	int testcase;
	scanf("%d", &testcase);

	while(testcase--){
		scanf("%d %d", &C, &R);

		q = queue<POINT>();
		int sx, sy;

		for(int i=1; i<=R; i++){
			scanf(" ");
			for(int j=1; j<=C; j++){
				scanf("%c", &field[i][j]);
				fires[i][j] = -1;
				//시작점 저장
				if(field[i][j] == '@'){
					sx = i;
					sy = j;
				}
				//불이 있는 곳은 모두 큐에 push
				if(field[i][j] == '*'){
					fires[i][j] = 0;
					POINT  p = {i, j, 0};
					q.push(p);
				}
			}
		}

		fire_bfs();

		int res = bfs(sx, sy);

		if(res == -1){
			printf("IMPOSSIBLE\n");
		}
		else{
			printf("%d\n", res);
		}

	}

	return 0;
}
