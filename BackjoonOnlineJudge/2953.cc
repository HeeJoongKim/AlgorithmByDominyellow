#include <stdio.h>
 
int main(void){
    int idx, res = -1;
    for(int i=1; i<=5; i++){
        int sum = 0;
        int tmp;
        for(int j=0; j<4; j++){
            scanf("%d", &tmp);
            sum += tmp;
        }
        if(sum > res){
            res = sum;
            idx = i;
        }
    }
    printf("%d %d\n", idx, res);
    return 0;
}
