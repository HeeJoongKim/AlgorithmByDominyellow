#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

//s1[i], s2[j]로 끝나는 최장 공통 부분 문자열의 길이
int d[4141][4141];
char s1[4141], s2[4141];
int main(void){
	scanf("%s", s1);
	scanf("%s", s2);

	int len1= strlen(s1);
	int len2 = strlen(s2);

	int res = 0;
	for(int i=0; i<len1; i++){
		for(int j=0; j<len2; j++){
			if(s1[i] == s2[j]){
				d[i+1][j+1] = d[i][j]+1;
			}
			res = max(res,  d[i+1][j+1]);
		}
	}

	printf("%d\n", res);

	return 0;
}
