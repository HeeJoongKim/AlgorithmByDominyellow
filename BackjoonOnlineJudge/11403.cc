#include <stdio.h>
 
int N;
int graph[123][123];
bool visited[123][123];
 
void dfs(int s, int here){
    for(int i=1; i<=N; i++){
        if(graph[here][i] == 1 && !visited[s][i]){
            visited[s][i] = true;
            dfs(s, i);
        }
    }
}
 
int main(void){
     
    scanf("%d", &N);
 
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &graph[i][j]);
        }
    }
     
    for(int i=1; i<=N; i++){
        dfs(i, i);
    }
 
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}
