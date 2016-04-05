#include <stdio.h>
#include <stack>
 
using namespace std;
 
int N;
 
int main(void){
    scanf("%d", &N);
 
    stack<pair<int, int> > st;
    int inp;
    for(int i=1; i<=N; i++){
        scanf("%d", &inp);
 
        int res = 0;
        while(!st.empty() && st.top().first < inp){
            st.pop();
        }
 
        if(!st.empty()){
            res = st.top().second;
        }
 
        st.push(make_pair(inp, i));
        printf("%d ", res);
    }
    printf("\n");
 
    return 0;
}
