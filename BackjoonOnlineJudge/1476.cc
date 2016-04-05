#include <stdio.h>
 
int main(void){
 
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
 
    int e=1, s=1, m=1;
    int year = 1;
    while(true){
        if(e == E && s == S && m == M){
            printf("%d\n", year);
            break;
        }
        e += 1;
        s += 1;
        m += 1;
 
        if(e == 16){
            e = 1;
        }
        if(s == 29){
            s = 1;
        }
        if(m == 20){
            m = 1;
        }
        year += 1;
    }
 
    return 0;
}
