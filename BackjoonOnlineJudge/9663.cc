#include <stdio.h>
#include <stdlib.h>
 
int field[16];
int N;
int ans=0;
 
bool is_available_queen(int index, int x){
    int i;
    if(field[index] != 0){
        //가로검사
        return false;
    }
    for(i=1; i<=N; i++){
        if(field[i] == x && field[i]!=0){
            //세로검사
            return false;
        }
    }
    for(i=1; i<=N; i++){
        if(field[i] != 0 && (abs(index-i)==abs(field[i]-x))){
            //대각선검사;
            return false;
        }
    }
    return true;
}
void nqueen(int q_count){
    int i,j;
    if(q_count == N){
        ans++;
        return;
    }
    for(i=1; i<=N; i++){
        if(is_available_queen(q_count+1,i)){
            field[q_count+1]=i;
            nqueen(q_count+1);
            field[q_count+1]=0;
        }
    }
}
 
int main(void){
    scanf("%d", &N);
         
    for(int i=1; i<=N; i++){
        field[i] = 0;
    }
 
    ans = 0;
    nqueen(0);
     
    printf("%d\n", ans);
}
