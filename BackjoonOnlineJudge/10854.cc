#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
 
using namespace std;
 
int main(void){
 
    int N;
    scanf("%d", &N);
 
    queue<int> q;
    string str;
    while(N--){
        cin >> str;
        int num;
        if(str == "push"){
            scanf("%d", &num);
            q.push(num);
        }
        else if(str == "pop"){
            if(q.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if(str == "size"){
            printf("%d\n", q.size());
        }
        else if(str == "empty"){
            printf("%d\n", q.empty());
        }
        else if(str == "front"){
            if(q.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", q.front());
            }
        }
        else if(str == "back"){
            if(q.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", q.back());
            }
        }
    }
    return 0;
}
