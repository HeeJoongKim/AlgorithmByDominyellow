#include <stdio.h>
 
int seq[1111];
int sum_seq[1111];
 
int main(void){
 
    int count=0;
    int num = 1;
    sum_seq[0] = 0;
    for(int i=1; i<=1000; i++){
        seq[i] = num;
        sum_seq[i] = sum_seq[i-1] + num;
        count += 1;
        if(count == num){
            count = 0;
            num += 1;
        }
    }
 
    int f, t;
    scanf("%d %d", &f, &t);
 
    printf("%d\n", sum_seq[t] - sum_seq[f-1]);
 
    return 0;
}
