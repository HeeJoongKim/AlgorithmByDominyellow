#include <stdio.h>

long long cache[100];

//길이가 n인 이친수의 경우의 수
long long solve(int n){
	if(n==1) {
		return 1;
	}
	if(n==2){
		return 1;
	}

	long long &ret = cache[n];

	if(ret != -1) {
		return ret;
	}

	ret = solve(n-1) + solve(n-2);
	return ret;
}

int main(void){
	int n; 
	scanf("%d", &n);
	for(int i=0; i<100; i++) {
		cache[i] = -1;
	}
	printf("%lld\n", solve(n));

	return 0;
}
