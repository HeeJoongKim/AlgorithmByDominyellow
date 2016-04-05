#include <stdio.h>
#include <queue>
 
using namespace std;
 
int M, N, H;
 
int field[102][102][102];
 
int h_move[6] = {0, 0, 1, 0, 0, -1};
int x_move[6] = {1, 0, 0, -1, 0, 0};
int y_move[6] = {0, 1, 0, 0, -1, 0};
 
typedef struct{
    int h;
    int x;
    int y;
    int d;
}POINT;
 
bool is_fisnshed(){
    for(int i=1; i<=H; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=M; k++){
                if(field[i][j][k] == 0){
                    return false;
                }
            }
        }
    }
    return true;
}
 
int main(void){
 
    scanf("%d %d %d", &M, &N, &H);
 
    for(int i=0; i<=H+1; i++){
        for(int j=0; j<=N+1; j++){
            for(int k=0; k<=M+1; k++){
                field[i][j][k] = -1;
            }
        }
    }
 
    queue<POINT> q;
 
    for(int i=1; i<=H; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=M; k++){
                scanf("%d", &field[i][j][k]);
                if(field[i][j][k] == 1){
                    POINT p = {i, j, k, 0};
                    q.push(p);
                }
            }
        }
    }
 
    int ans = 0;
 
    POINT p;
    while(!q.empty()){
        p = q.front();
        q.pop();
 
        ans = p.d > ans ? p.d : ans;
 
        for(int i=0; i<6; i++){
            if(field[p.h+h_move[i]][p.x+x_move[i]][p.y+y_move[i]] == 0){
                POINT tp = {p.h+h_move[i], p.x+x_move[i], p.y+y_move[i], p.d+1};
                field[tp.h][tp.x][tp.y] = tp.d;
                q.push(tp);
            }
        }
    }
 
    if(is_fisnshed()){
        printf("%d\n", ans);
    }   
    else{
        printf("-1\n");
    }
 
 
    return 0;
}
