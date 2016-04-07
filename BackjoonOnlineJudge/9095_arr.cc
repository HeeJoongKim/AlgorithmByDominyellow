#include <stdio.h>
 
//수열 D
//Dn = Dn-3 + Dn-2 + Dn-1  (N >= 4);
//D1 = 1;
//D2 = 2;
//D3 = 4;
int d[11];
 
int main(void){
 
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4; i<=10; i++){
        d[i] = d[i-3] + d[i-2] + d[i-1];
    }
 
    int testcase;
    scanf("%d", &testcase);
 
    while(testcase--){
        int n;
        scanf("%d", &n);
 
        printf("%d\n", d[n]);
    }
 
    return 0;
}
