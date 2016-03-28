#include <stdio.h>
#include <string.h>
 
int N;
 
char strs[55][55];
 
int main(void){
 
    scanf("%d", &N);
 
    for(int i=0; i<N; i++){
        scanf("%s", strs[i]);
    }
 
    for(int i=0; i<strlen(strs[0]); i++){
        for(int j=1; j<N; j++){
            if(strs[0][i] != strs[j][i]){
                strs[0][i] = '?';
                break;
            }
        }
    }
 
    printf("%s\n", strs[0]);
 
    return 0;
}
