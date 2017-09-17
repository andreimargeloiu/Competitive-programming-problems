# include <cstdio>
using namespace std;
int i,j,n,VV,var,N;
int a[30005],sol[20][30005],nr[20];
int main ()
{
    freopen ("stive.in", "r", stdin);
    freopen ("stive.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        a[i]=i;
    N=n;
    while (N)
    {
        var=(N+1)/2; ++VV; nr[VV]=var;
        for (i=1; i<=n; ++i)
            if (a[i]>=var) a[i]-=var,sol[VV][++sol[VV][0]]=i;
        N=N-var;
    }
    printf ("%d\n", VV);
    for (i=1; i<=VV; ++i)
    {
        printf ("%d ", sol[i][0]);
        for (j=1; j<=sol[i][0]; ++j)
            printf ("%d ", sol[i][j]);
        printf ("%d\n", nr[i]);
    }

    return 0;
}
