#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int N;
int s[1111];

//i번째 원소를 마지막으로 하는 LIS의 길이
int d[1111];
 
int main(void){
 
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &s[i]);
    }
 
    for(int i=0; i<N; i++){
        d[i] = 1;
        for(int j=0; j<i; j++){
            if(s[i] > s[j]){
                d[i] = max(d[i], d[j]+1);
            }
        }
    }
 
    int res = 0;
    for(int i=0; i<N; i++){
        res = max(res, d[i]);
    }
    printf("%d\n", res);
 
    return 0;
}
