#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, K; //수빈이 위치, 동생의 위치

int bfs(){
	queue<pair<int, int> > q; //위치, 시간
	bool visited[123123] = {}; //false로 초기화

	visited[N] = true;
	q.push(make_pair(N, 0));


	int p, t;
	while(true){
		p = q.front().first; //위치
		t = q.front().second; //시간
		q.pop();

		//탐색이 완료되면 시간 t를 리턴!
		if(p == K){
			return t;
		}

		if(p-1 >= 0 && !visited[p-1]){
			visited[p-1] = true;
			q.push(make_pair(p-1, t+1));
		}
		if(p+1 <= 100000 && !visited[p+1]){
			visited[p+1] = true;
			q.push(make_pair(p+1, t+1));
		}
		if(p*2 <= 100000 && !visited[p*2]){
			visited[p*2] = true;
			q.push(make_pair(p*2, t+1));
		}
	}

	//큐가 빌 때 까지 탐색에 실패하면 -1을 리턴
	return -1;
}

int main(void){

	scanf("%d %d", &N, &K);

	printf("%d\n", bfs());

	return 0;
}
