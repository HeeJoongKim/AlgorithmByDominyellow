#include <stdio.h>
#include <string.h>
#include <queue>
 
using namespace std;
 
bool is_prime[11111];
bool visited[11111];
 
int F, T;
 
void erathos(){
    memset(is_prime, true, 11111);
 
    is_prime[0] = is_prime[1] = false;
 
    for(int i=2; i*i<11111; i++){
        for(int j=i+i; j<11111; j += i){
            if(is_prime[j]){
                is_prime[j] = false;
            }
        }
    }
    for(int i=0; i<1001; i++){
        is_prime[i] = false;
    }
}
 
int bfs(){
    queue<pair<int, int> > q; //num, depth
    q.push(make_pair(F, 0));
    visited[F] = true;
 
    if(F == T){
        return 0;
    }
 
    int n, t;
    while(!q.empty()){
        n = q.front().first;
        t = q.front().second;
        q.pop();
 
        int carry=1;
        for(int i=0; i<4; i++){
            int next;
            next = n-n/carry%10*carry;
 
            for(int j=0; j<10; j++){
                if(is_prime[next] && !visited[next]){
                    q.push(make_pair(next, t+1));
                    visited[next] = true;
                    if(next == T){
                        return t+1;
                    }
                }
                next += carry;
            }
            carry *= 10;
        }
    }
    return -1;
}
 
int main(void){
 
    erathos();
     
    int testcase;
    scanf("%d", &testcase);
     
    while(testcase--){
        scanf("%d %d", &F, &T);
 
        memset(visited, false, 11111);
        int ans = bfs();
        if(ans == -1){
            printf("Impossible\n");
        }
        else{
            printf("%d\n", ans);
        }
    }
 
 
    return 0;
}
