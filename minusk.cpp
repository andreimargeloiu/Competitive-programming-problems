# include <cstdio>
using namespace std;
int i,j,n,k;
int p[1000005],m[1000005];
int main ()
{
    freopen ("minusk.in", "r", stdin);
    freopen ("minusk.out", "w", stdout);
    scanf ("%d%d", &n, &k);
    p[1]=1; m[1]=1;
    p[0]=1; m[0]=1;
    for (i=2; i<=n; ++i)
    {
        p[i]=p[i-1]+m[i-1];
        m[i]=2011+p[i-1]+m[i-1];
        if (i>=k) m[i]-=p[i-k];
        p[i]%=2011; m[i]%=2011;
    }
    printf ("%d\n", (p[n]+m[n])%2011);
    return 0;
}
