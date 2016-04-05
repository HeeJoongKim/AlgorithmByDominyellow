#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
    int a[1109];
    int minus;
}p,q;
char buf[1009];
A make(char *b)
{
    A x;
    int i, j, k;
    if(b[0] == '-')
    {
        x.minus = 1;
        for(i=1;b[i];i++)
            b[i-1] = b[i];
        b[i-1] = 0;
    }
    else
        x.minus = 0;
    for(i=0;i<1009;i++)
        x.a[i] = 0;
    for(i=0;b[i];i++)
        x.a[i] = b[i]-'0';
    j=i;
    for(i=0;i<j/2;i++)
        x.a[i] ^= x.a[j-i-1] ^= x.a[i] ^= x.a[j-i-1];
    return x;
}
A plus(A p, A q, int minus)
{
    A r;
    r.minus = 0;
    int i, j, k;
    if(p.minus ^ q.minus ^ minus)
    {
        //minus
        for(i=0;i<1009;i++)
        {
            r.a[i] = p.a[i];
        }
        for(i=0;i<1008;i++)
        {
            r.a[i] -= q.a[i];
            while(r.a[i] < 0)
            {
                r.a[i] += 10;
                r.a[i+1]--;
            }
        }
        if(r.a[1008] < 0)
        {
            r.minus = 1;
            for(i=0;i<1009;i++)
                r.a[i] = 9 - r.a[i];
            r.a[0]++;
            for(i=0;;i++)
            {
                if(r.a[i] > 9)
                {
                    r.a[i+1] += r.a[i]/10;
                    r.a[i] %= 10;
                }
                else
                    break;
            }
        }
        r.minus ^= p.minus;
    }
    else
    {
        for(i=0;i<1009;i++)
            r.a[i] = 0;
        for(i=0;i<1008;i++)
        {
            r.a[i] += p.a[i] + q.a[i];
            if(r.a[i] > 9)
            {
                r.a[i+1] += r.a[i] / 10;
                r.a[i] %= 10;
            }
        }
        r.minus = p.minus;
    }
    return r;
}
void print(A x)
{
    int i, j;
    for(i=1003;i>=0;i--)
        if(x.a[i])
            break;
    if(i<0)
        printf("0");
    else
    {
    if(x.minus)printf("-");
        for(;i>=0;i--)
            printf("%d",x.a[i]);
    }
    printf("\n");
}
int y[5000];
void process()
{
    int i, j;
    for(i=0;i<1009;i++)
    {
        for(j=0;j<1009;j++)
        {
            y[i+j] += p.a[i] * q.a[j];
        }
        for(j=0;j<1009;j++)
        {
            if(y[i+j]>9)
            {
                y[i+j+1] += y[i+j]/10;
                y[i+j] %= 10;
            }
        }
    }
    for(i=3000;i>=0;i--)
        if(y[i])
            break;
    if(i<0)
        printf("0\n");
    else
    {
        if(p.minus ^ q.minus) printf("-");
        for(;i>=0;i--)
            printf("%d",y[i]);
        printf("\n");
    }
}
int main()
{
    gets(buf);
    p = make(buf);
    gets(buf);
    q = make(buf);
    A r;
 
    r = plus(p,q,0);
    print(r);
    r = plus(p,q,1);
    print(r);
    process();
}
