# include <cstdio>
# include <algorithm>
# define MOD 10007
# define NR 2005
using namespace std;
int i,j,n,m;
int a[NR][NR], nr[NR];
int main ()
{
    freopen ("pviz.in", "r", stdin);
    freopen ("pviz.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
        scanf ("%d", &nr[i]);

    a[1][1]=1;

    for (i=1; i<=n; ++i)
        for (j=1; j<=min(i,m); ++j)
        {
            a[i][j]+=a[i-1][j-1]; //adaug un nou element vizibil
            a[i][j]+=(nr[j]-i+1)*a[i-1][j]; //adaug un element "invizibil"

            if (a[i][j]>=MOD) a[i][j]%=MOD;
        }


    printf ("%d\n", a[n][m]);

    return 0;
}
