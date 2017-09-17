# include <cstdio>
# define mod 666013
# define nmax 3001
using namespace std;
int i,j,n,k;
int a[nmax],b[nmax];
int main()
{
    freopen("perm4.in","r",stdin);
    freopen("perm4.out","w",stdout);
    scanf("%d%d", &n, &k);

    a[0]=1;
    for (i=2; i<=n; ++i)
    {
        for (j=0; j<i; ++j)
        {
            b[j]=a[j+1]*(j+1)%mod + a[j]*(i-j-1)%mod;
            if (j>0) b[j]=b[j]+a[j-1];

            while (b[j]>=mod) b[j]-=mod;
        }

        for (j=0; j<i; ++j)
        {
            a[j]=b[j];
            b[j]=0;
        }
    }

    printf("%d\n", a[k]);
    return 0;
}
