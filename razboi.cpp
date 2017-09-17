# include <cstdio>
# include <vector>
# include <algorithm>
# define inf 999999
using namespace std;
int i,j,n,m,x,y,cost,k,X,maxx,minn,var,I;
int a[505][505];
void rf()
{   int k, i, j;

    for(k=1; k<=n; ++k)
        for(i=1; i<=n; ++i)
            for(j=1; j<=n; ++j)
                if(a[i][k] && a[k][j] &&(a[i][j]>a[i][k]+a[k][j] || !a[i][j]) && i!=j) a[i][j]=a[i][k]+a[k][j];
}
int main ()
{
    freopen ("razboi.in", "r", stdin);
    freopen ("razboi.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &cost);
        a[x][y]=cost;
    }
    scanf ("%d", &X);
    rf();
    for (i=1; i<=n; ++i)
    {
        if (i!=X && a[i][X]==0) {maxx=0; break;}
        maxx=max(maxx,a[i][X]);
    }
    if (maxx==0) printf ("0\n");
       else printf ("%d\n", maxx);

    minn=inf;
    for (i=1; i<=n; ++i)
    {
        var=0;
        for (j=1; j<=n; ++j)
        {
            if (i!=j && a[j][i]==0) {var=0; break;}
            var=max(var,a[j][i]);
        }
        if (var==0) continue;
        else {
                 if (var<minn) minn=var, I=i;
             }
    }
    if (I) printf ("%d %d\n", I, minn);
        else printf ("0\n");
    /*for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
            g<<a[i][j]<<" ";
        g<<"\n";
    }*/

    return 0;
}
