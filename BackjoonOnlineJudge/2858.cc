#include <stdio.h>
 
int R, B;
 
int main(void){
 
    scanf("%d %d", &R, &B);
 
    int l, w;
    for(int i=1; i*i<=B; i++){
        if(i * (B/i) == B){
            l = (B/i)+2;
            w = i+2;
            if((l+w-2)*2 == R){
                printf("%d %d\n", l, w);
            }
        }
    }
 
    return 0;
}
