#include <stdio.h>
 
int N, S;
int s[22];
 
int solve(int idx, int sum){
    if(idx == N){
        if(sum == S){
            return 1;
        }
        return 0;
    }
 
    int ret = solve(idx+1, sum+s[idx]) + solve(idx+1, sum);
 
    return ret;
}
 
int main(void){
 
    scanf("%d %d", &N, &S);
 
    for(int i=0; i<N; i++){
        scanf("%d", &s[i]);
    }
     
    printf("%d\n", solve(0, 0) - (S==0));
 
    return 0;
}
