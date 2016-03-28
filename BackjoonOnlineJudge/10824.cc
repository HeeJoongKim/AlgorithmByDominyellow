#include <stdio.h>
#define ll long long
  
ll A, B, C, D;
  
int main(void){
    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
  
    ll tmp = B;
    while(tmp > 0){
        A *= 10;
        tmp /= 10;
    }
    A = A + B;
  
    tmp = D;
    while(tmp > 0){
        C *= 10;
        tmp /= 10;
    }
  
    C = C + D;
      
    printf("%lld\n", A+C);
  
    return 0;
}
