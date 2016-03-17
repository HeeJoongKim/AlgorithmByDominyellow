#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int main(void){
    int N;
    scanf("%d", &N);
 
    stack<int> st;
    string str;
 
    while(N--){
        cin >> str;
 
        if(str == "push"){
            int num;
            scanf("%d", &num);
            st.push(num);
        }
        else if(str == "pop"){
            if(st.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", st.top());
                st.pop();
            }
        }
        else if(str == "size"){
            printf("%d\n", st.size());
        }
        else if(str == "empty"){
            printf("%d\n", st.empty());
        }
        else if(str == "top"){
            if(st.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", st.top());
            }
        }
    }
 
    return 0;
}
