# include <cstdio>
# include <algorithm>
# include <cstring>
# include <deque>
# define NR 1005
# define mod 666013
# define inf 999999999
using namespace std;
deque <int> d;
int i,j,n,m,A,B,minn;
int a[NR][NR], maxx[NR][NR];

void solve (int x, int y)
{
    int i,j;

    //preprocesam
    for (j=1; j<=m; ++j)
    {
        d.clear();
        for (i=1; i<=n; ++i)
        {
            while (! d.empty() && a[i][j]>=a[d.back()][j])
                d.pop_back();

            d.push_back(i);

            if (i>=y) //daca ajunge la pozitii valide
            {
                if (d.front() == i-y) d.pop_front();
                maxx[i][j]=a[d.front()][j];
            }
        }
    }

    for (i=1; i<=n-y+1; ++i)
    {
        d.clear();
        for (j=1; j<=m; ++j)
        {
            while (! d.empty() && maxx[i+y-1][j] > maxx[i+y-1][d.back()])
                d.pop_back();

            d.push_back(j);

            if (j>=x)
            {
                if (d.front() == j-x) d.pop_front();
                minn=min(minn, maxx[i+y-1][d.front()]);
            }
        }
    }
}
int main ()
{
    freopen ("platforma.in", "r", stdin);
    freopen ("platforma.out", "w", stdout);

    scanf ("%d%d%d%d", &n, &m, &A, &B);
    for (i=1; i<=m; ++i)
        scanf ("%d", &a[1][i]);

    for (i=2; i<=n; ++i)
        for (j=1; j<=m; ++j)
            a[i][j]=(1LL*a[i-1][j]*i)%mod;

    minn=inf;
    solve (B, A);

    printf ("%d\n", minn);

    return 0;
}

