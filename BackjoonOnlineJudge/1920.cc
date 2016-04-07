#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;
int A[111111];

int main(void){

	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}

	sort(A, A+N);

	scanf("%d", &M);
	int s;
	for(int i=0; i<M; i++){
		scanf("%d", &s);

		int low=0, high=N-1, mid;
		bool res = false;
		while(low <= high){
			mid = (low + high)/2;

			if(A[mid] == s){
				//탐색 성공
				res = true;
				break;
			}
			else if(A[mid] < s){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		printf("%d\n", res);

	}

	return 0;
}
