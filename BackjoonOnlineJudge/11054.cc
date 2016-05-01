#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int N;
int seq[1234];
int lis[1234]; //i번째를 끝으로 하는 LIS의 길이
int lds[1234]; //i번째를 시작으로 하는 LDS의 길이
 
int main(void){
     
    scanf("%d", &N);
     
    int res = -1;
     
    for(int i=0; i<N; i++){
        scanf("%d", &seq[i]);
    }
     
    for(int i=0; i<N; i++){
        int _max = 0;
        for(int j=0; j<i; j++){
            if(seq[i] > seq[j]){
                _max = max(_max, lis[j]);
            }
        }
        lis[i] = _max+1;
    }
     
    for(int i=N-1; i>=0; i--){
        int _max = 0;
        for(int j=N-1; j>i; j--){
            if(seq[i] > seq[j]){
                _max = max(_max, lds[j]);
            }
        }
        lds[i] = _max+1;
    }
    for(int i=0; i<N; i++){
        res = max(res, lis[i]+lds[i]-1);
    }
     
    printf("%d\n", res);
     
    return 0;
}
