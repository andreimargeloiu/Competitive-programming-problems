# include <cstdio>
using namespace std;
int i,j,n,p,k,maxx,nr,x,y,q,var;
int a[1005][1005];
int main ()
{
    freopen ("gradina.in", "r", stdin);
    freopen ("gradina.out", "w", stdout);

    scanf ("%d%d%d", &n, &p, &k);
    for (i=1; i<=p; ++i)
    {
        scanf ("%d%d", &x, &y);
        a[x][y]=1;
    }
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];

    for (i=k; i<=n; ++i)
        for (j=k; j<=n; ++j)
        {
            var=a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k];
            if (var>maxx) maxx=var, nr=1;
               else if (var==maxx) ++nr;
        }
    printf ("%d\n%d\n", maxx, nr);
    return 0;
}
