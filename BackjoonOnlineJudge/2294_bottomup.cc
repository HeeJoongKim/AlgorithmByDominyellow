#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
int s[123];
 
int d[12345]; //i를 만드는 동전의 최소 개수
 
int main(void){
 
    int n, k;
    scanf("%d %d", &n, &k);
    memset(d, -1, sizeof d);
    for(int i=0; i<n; i++){
        scanf("%d", &s[i]);
        if(s[i] <= k){
            d[s[i]] = 1;
        }
    }
 
    for(int i=1; i<=k; i++){
        if(d[i] != -1){
            for(int j=0; j<n; j++){
                if(i + s[j] <= k){
                    d[i+s[j]] = min(d[i+s[j]] == -1 ? 99999 : d[i+s[j]], d[i]+1);
                }
            }
        }
    }
 
    printf("%d\n", d[k]);
 
    return 0;
}
