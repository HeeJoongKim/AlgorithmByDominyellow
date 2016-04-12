#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int s[1111];

int d[1111];

//idx수열을 시작으로하는 LIS의 길이
int solve(int idx){
	if(idx == N){
		return 0;
	}
	int &ret = d[idx];
	if(ret != -1){
		return ret;
	}

	ret=1;

	for(int i=idx+1; i<=N; i++){
		if(s[idx] < s[i]){
			ret = max(ret, 1+solve(i));
		}
	}

	return ret;
}

int main(void){

	memset(d, -1, sizeof(int) * 1111);

	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &s[i]);
	}

	int res = 0;
	for(int i=0; i<N; i++){
		res = max(res, solve(i));
	}

	printf("%d\n", res);

	return 0;
}
