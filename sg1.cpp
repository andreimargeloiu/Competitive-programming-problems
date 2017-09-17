# include <cstdio>
# include <algorithm>
# define NR 101
using namespace std;
int i,j,n,m,d1,d2,k,o;
int a[NR][NR][31], l[NR][NR];
void aduna (int i1, int j1, int i2, int j2)
{
    int i,t=0;
    l[i1][j1]=max(l[i1][j1], l[i2][j2]);
    for (i=1; i<=l[i1][j1]; ++i)
    {
        t=t+a[i1][j1][i]+a[i2][j2][i];
        a[i1][j1][i]=t%10;
        t=t/10;
    }

    while (t) a[i1][j1][++l[i1][j1]]=t%10, t=t/10;
}
int main ()
{
    freopen ("sg1.in", "r", stdin);
    freopen ("sg1.out", "w", stdout);

    scanf ("%d%d%d%d", &n, &k, &d1, &d2);

    // a[i][j] - numarul de pisibilatati de a forma cu i de 1 un numar de j cifre

    for (i=1; i<=n; ++i)
        a[1][i][1]=1, l[1][i]=1;

    for (i=2; i<=k; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            for (o=j-d1-1; o>=j-d2-1 && o>=1; --o)
            {
                aduna (i,j,i-1,o);
            }
        }
    }
    for (i=1; i<=n; ++i)
        aduna(0,0,k,i);

    if (l[0][0])
    {
        for (i=l[0][0]; i>=1; --i)
            printf ("%d", a[0][0][i]);
        printf ("\n");
    }
    else printf ("0\n");

    return 0;
}
