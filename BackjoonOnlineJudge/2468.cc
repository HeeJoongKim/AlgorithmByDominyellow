#include <stdio.h>
#include <queue>
 
using namespace std;
 
int N;
int field[160][160];
int x_move[8] = {0, 1, -1, 0, 1, -1, -1, 1};
int y_move[8] = {1, 0, 0, -1, -1, 1, -1, 1};
 
typedef struct{
    int x;
    int y;
}POINT;
 
 
void bfs(int x, int y, int h){
    POINT p = {x, y};
    field[x][y] = -1;
    queue<POINT> q;
    q.push(p);
 
    while(!q.empty()){
        p = q.front();
        q.pop();
 
        for(int i=0; i<4; i++){
            if(field[p.x+x_move[i]][p.y+y_move[i]] > h){
                POINT tp = { p.x+x_move[i], p.y+y_move[i]};
                field[tp.x][tp.y] = -1;
                q.push(tp);
            }
        }
    }
}
 
int main(void){
 
    scanf("%d", &N);
 
    int min = 200;
    int max = -1;
    int tmp;
    int init_field[160][160] = {};
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &tmp);
            min = tmp < min ? tmp : min;
            max = tmp > max ? tmp : max;
            init_field[i][j] = tmp;
        }
    }
 
    int ans = -1;
    for(int h=min-1; h<=max; h++){
        int sub_ans=0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                field[i][j] = init_field[i][j];
            }
        }
 
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(field[i][j] > h){
                    bfs(i, j, h);
                    sub_ans += 1;
                }
            }
        }
 
        //printf("%d %d\n", h, sub_ans);
        ans = sub_ans > ans ? sub_ans : ans;
    }
 
    printf("%d\n", ans);
 
    return 0;
}
