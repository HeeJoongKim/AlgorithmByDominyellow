#include <stdio.h>
 
int move_x = 1;
int move_y = 1;
 
int main(void){
    int P, Q;
    int x, y;
    int T;
     
    scanf("%d %d", &P, &Q);
    scanf("%d %d", &x, &y);
    scanf("%d", &T);
     
    for(int i=0; i<T; i++){
        x += move_x;
        y += move_y;
         
        if(x == P || x == 0){
            move_x *= -1;
        }
        if(y == Q || y == 0){
            move_y *= -1;
        }
    }
     
    printf("%d %d\n", x, y);
    return 0;
}
