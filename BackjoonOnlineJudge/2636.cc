#include <cstdio>
 
int x_move[] = {-1, 1, 0, 0};
int y_move[] = {0, 0, -1, 1};
 
bool visited[111][111]; 
int field[111][111];
int n, m;
 
int day;
int last_cheese;
int chk;
 
void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=0 ; i<4 ; i++){
        int nx = x + x_move[i];
        int ny = y + y_move[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]){
            if(field[nx][ny] == 1){
                field[nx][ny] = 0;
                visited[nx][ny] = true;
            }
            else{
                dfs(nx, ny);
            }
        }
    }
}
 
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d", &field[i][j]);
        }
    }
 
    while(true){
 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                visited[i][j] = false;
            }
        }
 
 
        last_cheese = n*m - chk;
        chk = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(field[i][j] == 0) {
                    chk++;
                }
            }
        }
        if(chk == n*m){
            break;
        }
 
 
        dfs(0, 0);
        day++;
    }
    printf("%d\n%d\n", day, last_cheese);
 
    return 0;
}
