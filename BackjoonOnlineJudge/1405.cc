#include <stdio.h>
 
int K;
double E, W, S, N;
 
int field[55][55];
 
double dfs(int t, int x, int y, double p){
    if(field[x][y] == 1){
        return 0;
    }
    if(t == K){
        return p;
    }
 
    field[x][y] = 1;
    double ret = 0;
    ret += dfs(t+1, x+1, y, p*S);
    ret += dfs(t+1, x-1, y, p*N);
    ret += dfs(t+1, x, y+1, p*E);
    ret += dfs(t+1, x, y-1, p*W);
    field[x][y] = 0;
 
    return ret;
}
 
int main(void){
    scanf("%d %lf %lf %lf %lf", &K, &E, &W, &S, &N);
    E /= 100;
    W /= 100;
    S /= 100;
    N /= 100;
    printf("%.20lf\n", dfs(0, 25, 25, 1.0));
 
    return 0;
}
