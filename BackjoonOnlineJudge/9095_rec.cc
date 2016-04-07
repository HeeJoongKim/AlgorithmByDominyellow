#include <stdio.h>
 
//수열 D
//Dn = Dn-3 + Dn-2 + Dn-1  (N >= 4);
//D1 = 1;
//D2 = 2;
//D3 = 4;
int solve(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;
  
    return solve(n-3) + solve(n-2) + solve(n-1);
}
  
int main(void){
  
    int testcase;
    scanf("%d", &testcase);
  
    while(testcase--){
        int n;
        scanf("%d", &n);
  
        printf("%d\n", solve(n));
    }
  
    return 0;
}
