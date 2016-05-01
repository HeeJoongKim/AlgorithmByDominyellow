#include <stdio.h>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
char str1[1111];
char str2[1111];
 
int L1, L2;
 
int d[1111][1111];
//idx1, idx2로시작하는 lcs
int solve(int idx1, int idx2){
    if(idx1 >= L1 || idx2 >= L2){
        return 0;
    }
 
    int &ret = d[idx1][idx2];
    if(ret != -1){
        return ret;
    }
 
    if(str1[idx1] == str2[idx2]){
        ret = max(ret, 1 + solve(idx1+1, idx2+1));
    }
 
    ret = max(ret, solve(idx1+1, idx2));
    ret = max(ret, solve(idx1, idx2+1));
 
    return ret;
}
 
 
int main(void){
    memset(d, -1, sizeof(d));
    scanf("%s", str1);
    scanf("%s", str2);
 
    L1 = strlen(str1);
    L2 = strlen(str2);
 
    printf("%d\n", solve(0, 0));
 
    return 0;
}
