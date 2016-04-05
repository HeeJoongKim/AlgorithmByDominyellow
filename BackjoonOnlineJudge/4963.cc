#include <stdio.h>
 
int field[52][52];
int x_move[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int y_move[8] = {0, 0, 1, -1, 1, -1, 1, -1};
 
void dfs(int x, int y) {
    field[x][y] = 0;
 
    for (int i = 0; i < 8; i++)
        if (field[x + x_move[i]][y + y_move[i]]){
            dfs(x + x_move[i], y + y_move[i]);
        }
}
 
int main() {
     
 
    while (true) {
        int r, c;
        scanf("%d %d", &c, &r);
        if (!r && !c){
            break;
        }
 
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf("%d", &field[i][j]);
 
        int cnt = 0;
 
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (field[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
 
        printf("%d\n", cnt);
    }
}
