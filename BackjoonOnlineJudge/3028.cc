#include <stdio.h>
#include <string.h>
 
int flip(char ch, int n){
    switch(ch){
    case 'A':
        if(n==1) n=2;
        else if(n==2) n=1;
        break;
    case 'B':
        if(n==2) n=3;
        else if(n==3) n=2;
        break;
    case 'C':
        if(n==1) n=3;
        else if(n==3) n=1;
        break;
    default:
        break;
    }
    return n;
}
 
int main(void){
    char shk[55];
    scanf("%s", shk);
    int len = strlen(shk);
    int res = 1;
    for(int i=0; i<len; i++){
        res = flip(shk[i], res);
    }
    printf("%d\n", res);
     
    return 0;
}
