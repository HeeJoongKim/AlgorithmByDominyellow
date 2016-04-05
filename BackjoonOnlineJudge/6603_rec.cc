#include <stdio.h>
 
int K;
int s[15];
int sel[6];
 
void solve(int idx, int cnt){
    if(cnt == 6){
        for(int i=0; i<6; i++){
            printf("%d ", sel[i]);
        }
        printf("\n");
        return;
    }
    if(idx == K){
        return;
    }
 
    sel[cnt] = s[idx];
    solve(idx+1, cnt+1);
    solve(idx+1, cnt);
 
}
 
int main(void){
    while(scanf("%d", &K)){
        if(K == 0){
            break;
        }
        for(int i=0; i<K; i++){
            scanf("%d", &s[i]);
        }
 
        solve(0, 0);
        printf("\n");
    }
    return 0;
}
