#include <stdio.h>
#include <stack>
#include <string.h>
 
using namespace std;
 
char str[1123123];
 
int main(void){
 
    int testcase;
    scanf("%d", &testcase);
 
    while(testcase--){
        scanf("%s", str);
 
        int len = strlen(str);
        stack<char> st1, st2;
 
        for(int i=0; i<len; i++){
            char ch = str[i];
 
            if(ch == '<'){
                if(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            else if(ch == '>'){
                if(!st2.empty()){
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else if(ch == '-'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(ch);
            }
        }
 
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
 
        while(!st2.empty()){
            printf("%c", st2.top());
            st2.pop();
        }
        printf("\n");
    }
    return 0;
}
