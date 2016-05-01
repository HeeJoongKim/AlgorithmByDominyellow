#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
int d[1212][1212];
char s1[1212], s2[1212];
int main(void){
    scanf("%s", s1);
    scanf("%s", s2);
 
    int len1= strlen(s1);
    int len2 = strlen(s2);
 
    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            if(s1[i] == s2[j]){
                d[i+1][j+1] = d[i][j]+1;
            }
            else{
                d[i+1][j+1] = max(d[i][j+1], d[i+1][j]);
            }
        }
    }
 
    printf("%d\n", d[len1][len2]);
 
    return 0;
}
