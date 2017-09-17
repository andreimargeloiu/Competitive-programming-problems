#include<cstdio>
#define INF 1e18+1
using namespace std;
unsigned long long x,y;
int k;
long long xmin,ymin;
long long Min=INF;
void verifmin(long long a,int b)
{
    if (a+b<Min) {Min=a+b;xmin=a;ymin=b;}
}
void gen(long long lim)
{
    long long p=1;k=0;
    while (p<=lim)
    {
        long long cat=y/p;
        if (cat*p>=x) verifmin(cat,k);

        cat=x/p;
        while (cat*p<x)
        {
            ++cat;
        }
        if (cat*p>=x && cat*p<=y) verifmin(cat,k);
        p=p*2;
        ++k;
    }
}
int main()
{
    freopen("taste.in", "r", stdin);
    freopen("taste.out", "w", stdout);
    scanf("%lld%lld",&x,&y);
    gen(y);
    printf("%lld %lld\n",xmin,ymin);
    return 0;
}
