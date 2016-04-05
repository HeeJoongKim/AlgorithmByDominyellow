#include <stdio.h>
 
int main(void){
    int testcase;
    scanf("%d", &testcase);
 
    while(testcase--){
        int s[20];
        int N;
        scanf("%d", &N);
 
        int sum=0;
        int _max=-1;
        for(int i=1; i<=N; i++){
            scanf("%d", &s[i]);
            sum += s[i];
            _max = _max > s[i] ? _max : s[i];
        }
 
        int idx;
        int max_cnt=0;
        for(int i=1; i<=N; i++){
            if(_max == s[i]){
                idx = i;
                max_cnt += 1;
            }
        }
 
        if(max_cnt != 1){
            printf("no winner\n");
        }
        else{
            if(_max > sum/2){
                printf("majority winner %d\n", idx);
            }
            else{
                printf("minority winner %d\n", idx);
            }
        }
    }
 
    return 0;
}
