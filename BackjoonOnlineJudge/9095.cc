#include <stdio.h>
 
int N;
int ans;
 
void dfs(int sum){
    if(sum == N){
        ans += 1;
        return;
    }
 
    for(int i=1; i<=3; i++){
        if(sum + i <= N){
            dfs(sum + i);
        }
    }
}
 
int main(void){
 
    int testcase;
    scanf("%d", &testcase);
 
    while(testcase--){
        ans = 0;
        scanf("%d", &N);
 
        dfs(0);
 
        printf("%d\n", ans);
    }
 
    return 0;
}
