#include <stdio.h>
 
int N, S;
 
int seq[22];
 
int solve(int idx, int sum){
    if(idx == N){
        if(sum == S){
            return 1;
        }
        return 0;
    }
 
    //현재 idx의 숫자를 선택하는 경우 + 선택하지 않는 경우
    int ret = solve(idx+1, sum + seq[idx]) + solve(idx+1, sum);
 
    return ret;
}
 
int main(void){
    scanf("%d %d", &N, &S);
 
    for(int i=0; i<N; i++){
        scanf("%d", &seq[i]);
    }
 
    printf("%d\n", solve(0, 0) - (S==0));
 
    return 0;
}
