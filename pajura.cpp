# include <cstdio>
using namespace std;
int i,j,n,m,ok,a[1005][1005],intors[1005];
char s[1005];
int main ()
{
    freopen ("pajura.in", "r", stdin);
    freopen ("pajura.out", "w", stdout);
    while (scanf ("%d%d", &n, &m) && (n!=0 && m!=0))
    {
        ok=1;
        for (i=1; i<=n; ++i)
        {
            scanf ("%s", &s);
            for (j=1; j<=m; ++j)
            {
                if (s[j-1]=='C') a[i][j]=1;
                   else a[i][j]=-1;
            }
        }
        for (i=1; i<=n; ++i)
        {
            if (a[i][1]==-1) intors[i]=-1;
                else intors[i]=1;
        }
        for (j=2; j<=m && ok; ++j)
        {
            for (i=1; i<=n && ok; ++i)
            {
                a[i][j]*=intors[i];
                if (i!=1 && a[i][j]!=a[i-1][j]) ok=0;
            }
        }
        if (ok) printf ("1\n");
            else printf ("0\n");
    }

    return 0;
}
