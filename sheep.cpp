# include <bits/stdc++.h>
using namespace std;
long long n,x;
int test,i,COUNT,VV,u,k,j;
int used[20];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&test);k=0;
    while(test>0) {
        --test;++k;
        scanf("%lld",&n);
        if(n == 0) {printf("CASE #%d: INSOMNIA\n",k);continue;}
        memset(used,0,sizeof(used));
        VV=0; i=1; COUNT=0;
        while(VV == 0) {
            x=i * n;
            while(x > 0) {
                u= x % 10;
                if(used[u] == 0) {++COUNT;used[u]=1;}
                x/=10;
            }
            if(COUNT == 10) break;
            ++i;
        }
        printf("CASE #%d: %lld\n",k,n*i);
    }
    return 0;
}
