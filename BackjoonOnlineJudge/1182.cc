#include <stdio.h>

int N, S;

int s[25];
bool selected[25];
int ans = 0;

void dfs(int idx, int sum){
	//기저 사례 : 합이 S가 됬을 때
	if(sum == S && idx != 0){
		ans += 1;
	}

	for(int i=idx+1; i<=N; i++){
		if(!selected[i]){
			selected[i] = true; //선택한다.
			dfs(i, sum + s[i]);
			selected[i] = false; //선택 해제 : Back Track!
		}
	}

}

int main(void){
	scanf("%d %d", &N, &S);

	for(int i=1; i<=N; i++){
		scanf("%d", &s[i]);
	}
	dfs(0, 0);
	printf("%d\n", ans);

	return 0;
}
