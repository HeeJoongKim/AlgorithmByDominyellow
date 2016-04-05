#include <stdio.h>
#include <queue>
#include <algorithm>
  
using namespace std;
  
int N, M;
  
int field[1111][1111];
  
int xm[4] = {1, 0, -1, 0};
int ym[4] = {0, 1, 0, -1};
  
int main(void){
  
    scanf("%d %d", &M, &N);
  
    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=M+1; j++){
            field[i][j] = -1;
        }
    }
  
    queue<pair<pair<int, int>, int> > q; // < <x, y>, time>
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &field[i][j]);
            if(field[i][j] == 1){
                q.push(make_pair(make_pair(i, j), 0));
            }
        }
    }
  
    int x, y, t;
    int ans = 0;
    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        t = q.front().second;
          
        ans = max(ans, t);
  
        q.pop();
        int tx, ty, tt;
        for(int i=0; i<4; i++){
            tx = x+xm[i];
            ty = y+ym[i];
            tt = t+1;
              
            if(field[tx][ty] == 0){
                q.push(make_pair(make_pair(tx, ty), tt));
                field[tx][ty] = tt;
            }
        }
    }
  
    /*
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    */
  
    //printf("push_count : %d\n", push_count);
    bool finish = true;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(field[i][j] == 0){
                finish = false;
                break;
            }
        }
        if(!finish){
            break;
        }
    }
    if(finish){
        printf("%d\n", ans);
    }
    else{
        printf("-1\n");
    }
  
    return 0;
}
