#include <stdio.h>
#include <algorithm>

using namespace std;

//i행 j열이 도착점일 때 합의 최대값
int d[543][543];

int main(void){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			scanf("%d", &d[i][j]);
			d[i][j] = max(d[i-1][j-1], d[i-1][j]) + d[i][j];
		}
	}

	int res = 0;
	for(int i=1; i<=n; i++){
		res = max(res, d[n][i]);
	}
	printf("%d\n", res);

	return 0;
}
