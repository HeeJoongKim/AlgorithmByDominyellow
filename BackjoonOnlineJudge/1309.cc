#include <stdio.h>
#define MOD 9901

//d1 마지막줄 비어있을 때, d2 마지막줄이 비어있지 않을 때
//2*i칸 채우는 경우의 수
int d1[111111];
int d2[111111];

int main(void){

	int n;
	scanf("%d", &n);

	d1[1] = 1; 
	d2[1] = 2;
	for(int i=2; i<=n; i++){
		d1[i] = (d1[i-1] + d2[i-1])%MOD;
		d2[i] = (d1[i-1]*2 + d2[i-1])%MOD;
	}

	printf("%d\n", (d1[n] + d2[n])%MOD);

	return 0;
}
