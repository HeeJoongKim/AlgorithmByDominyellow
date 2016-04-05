#include <stdio.h>
 
int T[55];
 
bool solve(int n){
    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            for(int k=1; k<=50; k++){
                if(T[i] + T[j] + T[k] == n){
                    return true;
                }
            }
        }
    }
    return false;
}
 
int main(void){
 
    T[1] = 1;
    for(int i=2; i<=50; i++){
        T[i] = T[i-1] + i;
    }
 
    int testcase;
    scanf("%d", &testcase);
 
    while(testcase--){
        int n;
        scanf("%d", &n);
 
        printf("%d\n", solve(n));
 
    }
 
    return 0;
}
