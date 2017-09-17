# include <cstdio>
using namespace std;
int n, m, k, D, VV;
bool a[2*1505][2*1505];
int nr[2*1505][2*1505];
int main()
{
    freopen ("pseudobil.in", "r", stdin);
    freopen ("pseudobil.out", "w", stdout);
    int i,j,x,y,T,v1,v2;
    scanf ("%d%d%d%d", &T, &n, &k, &D);
    for (i=1; i<=k; ++i)
    {
        scanf ("%d%d", &x, &y);
        a[x+y-1][n-x+y] = 1;
    }
    for (i=1; i<=2*n-1; ++i)
        for (j=1; j<=2*n-1; ++j)
            nr[i][j]=a[i][j]+nr[i-1][j]+nr[i][j-1]-nr[i-1][j-1];
    if (T==1) {x=D/2-1; printf ("%d\n", 2*x*x+D-1);}
    else
    {
        scanf ("%d", &m);
        for (i=1; i<=m; ++i)
        {
            scanf ("%d%d", &x, &y);
            v1=x+y-1; v2=n-x+y;
            VV=nr[v1+D][v2]-nr[v1+D][v2-D-1]-nr[v1-1][v2]+nr[v1-1][v2-D-1];
            printf ("%d\n", VV);
        }
    }
    return 0;
}
