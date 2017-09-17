# include <cstdio>
# include <algorithm>
# define MOD 31607
using namespace std;
int a[251][251][251];//cate moduri sunt de a ajunge cu un cost sunt pana intr-un punct
int mat[251][251];//unde sunt jetoanele
int maxx[251][251]; //cate jetoane utem strange pana intr-un punct
int x,y,sol,n,m,k,l,dist;
int main ()
{
    freopen ("drumuri.in", "r", stdin);
    freopen ("drumuri.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &m, &k, &l);
    int i,j,q;
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        mat[x][y]=1;
    }
    if (mat[1][1]) a[1][1][1]=1,maxx[1][1]=1;
        else a[1][1][0]=1;
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            if (i==1 && j==1) continue;
            maxx[i][j]=max(maxx[i-1][j],maxx[i][j-1]);
            if (!mat[i][j])
            {
                for (q=0; q<=maxx[i][j]; ++q)
                {
                    a[i][j][q]=a[i-1][j][q]+a[i][j-1][q];
                    while (a[i][j][q]>=MOD) a[i][j][q]-=MOD;
                }
            }
            else
            {
                ++maxx[i][j];
                for (q=1; q<=maxx[i][j]; ++q)
                {
                    a[i][j][q]=a[i-1][j][q-1]+a[i][j-1][q-1];
                    while (a[i][j][q]>=MOD) a[i][j][q]-=MOD;
                }
            }
        }
    }
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
        {
            dist=i+j-1;
            if (dist==l) sol=(sol+a[i][j][k])%MOD;
        }
    printf ("%d\n", sol);
    return 0;
}
