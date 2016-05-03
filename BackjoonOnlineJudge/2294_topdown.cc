#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
int N, K;
int s[111];
 
int d[111][11111];
int solve(int idx, int sum){
    if(sum == K){
        return 0;
    }
    if(sum > K || idx == N){
        return 99999;
    }
 
    int &ret = d[idx][sum];
    if(ret != -1){
        return ret;
    }
 
    ret = min(solve(idx+1, sum), 1 + solve(idx, sum + s[idx]));
 
    return ret;
}
 
int main(void){
    memset(d, -1, sizeof(d));
 
    scanf("%d %d", &N, &K);
 
    for(int i=0; i<N; i++){
        scanf("%d", &s[i]);
    }
 
    printf("%d\n", solve(0, 0));
 
    return 0;
}
