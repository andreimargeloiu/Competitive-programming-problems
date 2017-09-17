# include <cstdio>
# define inf 1000000000
using namespace std;
int a[10005],v[150005],ap[100005];
int i,j,n,k,trb,poz,minn,maxx;
int main ()
{
    freopen ("punctfix.in", "r", stdin);
    freopen ("punctfix.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);

    scanf ("%d", &k);
    minn=inf; maxx=inf;
    for (i=1; i<=k; ++i)
    {
        scanf ("%d", &v[i]);
        if (v[i]<minn) minn=v[i];
        if (v[i]>maxx) maxx=v[i];
    }
    for (i=1; i<=n; ++i)
    {
        trb=i-a[i];
        if (trb>=minn && trb<=maxx)
        {
            ++ap[trb-minn];
        }
    }

    for (i=1; i<=k; ++i)
        printf ("%d\n", ap[v[i]-minn]);
    return 0;
}
