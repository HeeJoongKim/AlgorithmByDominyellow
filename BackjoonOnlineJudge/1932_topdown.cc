#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;

int s[543][543];
int d[543][543];

//i행 j열이 도착점일 때 합의 최대값
int solve(int r, int c){
	if(r > n){
		return 0;
	}
	int &ret = d[r][c];
	if(ret != -1){
		return ret;
	}

	ret = max(solve(r+1, c), solve(r+1, c+1)) + s[r][c];

	return ret;
}

int main(void){
	memset(d, -1, sizeof d);

	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			scanf("%d", &s[i][j]);
		}
	}

	printf("%d\n", solve(1, 1));

	return 0;
}
