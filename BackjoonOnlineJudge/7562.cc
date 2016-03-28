#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
int L;
 
//8방향 이동
int x_move[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int y_move[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool visited[333][333];
 
typedef struct POINT{
    int x;
    int y;
    int t;
};
 
int bfs(int sx, int sy, int ex, int ey){
    POINT p = {sx, sy, 0};
    visited[sx][sy] = true;
    queue<POINT> q;
    q.push(p);
 
    while(!q.empty()){
        POINT p = q.front();
        int x = p.x, y = p.y, t = p.t;
        q.pop();
 
        if(x == ex && y == ey){
            return t;
        }
 
        int nx, ny;
        for(int i=0; i<8; i++){
            nx = x + x_move[i];
            ny = y + y_move[i];

			//체스 판을 벗어나지 않았는지 판단 && 방문한 적이 없는지 판단
            if(0 <= nx && nx < L && 0 <= ny && ny < L && !visited[nx][ny]){
                POINT p = {nx, ny, t+1};
                visited[nx][ny] = true;
                q.push(p);
            }
        }
    }
    return -1;
}
 
int main(void){
 
    int testcase;
    scanf("%d", &testcase);
 
    while(testcase--){
        scanf("%d", &L);
        memset(visited, false, 333*333);
        int sx, sy;
        int ex, ey;
        scanf("%d %d", &sx, &sy);//출발점
        scanf("%d %d", &ex, &ey);//도착점
 
        printf("%d\n", bfs(sx, sy, ex, ey));
    }
 
    return 0;
}
