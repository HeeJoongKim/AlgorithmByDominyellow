#include <stdio.h>
 
int K;
int s[22];
 
int main(void){
 
    while(scanf("%d", &K)){
        if(K == 0){
            break;
        }
         
        for(int i=0; i<K; i++){
            scanf("%d", &s[i]);
        }
 
        int a, b, c, d, e, f;
        for(a=0; a<K; a++){
            for(b=a+1; b<K; b++){
                for(c=b+1; c<K; c++){
                    for(d=c+1; d<K; d++){
                        for(e=d+1; e<K; e++){
                            for(f=e+1; f<K; f++){
                                printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }
 
    return 0;
}
