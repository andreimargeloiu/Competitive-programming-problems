# include <cstdio>
# include <algorithm>
using namespace std;
struct elem
{
    int energ, init;
}v[105];
bool cmp (elem x, elem y)
{
    if (x.energ>=y.energ) return 0;
        else return 1;
}
int i,j,n,m,x,y,c,t,minn,maxx,ok,sol1,sol2;
int nou[105],a[105][105],cost[105][105],vechi[105];
void RF (int s)
{
    int i,j,k;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            a[i][j]=cost[i][j];

    for (k=s; k<=n && ok; ++k)
    {
        for (i=s; i<=n; ++i)
            for (j=s; j<=n; ++j)
                if (i!=j && a[i][k] && a[k][j] && (a[i][k]+a[k][j]<a[i][j] || ! a[i][j]))
                    a[i][j]=a[i][k]+a[k][j];
        for (i=s; i<=k && ok; ++i)
            for (j=s; j<=k && ok; ++j)
                if (a[i][j]==t)
                {
                    ok=0;
                    printf ("%d %d %d %d\n", vechi[i], vechi[j], v[s].energ, v[k].energ);
                }
    }
}
int main ()
{
    freopen ("coach.in", "r", stdin);
    freopen ("coach.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &t);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &v[i].energ);
        v[i].init=i;
    }
    sort (v+1, v+n+1, cmp);
    for (i=1; i<=n; ++i)
    {
        nou[v[i].init]=i;
        vechi[i]=v[i].init;
    }
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &c);
        cost[nou[x]][nou[y]]=c;
        cost[nou[y]][nou[x]]=c;
    }
    ok=1;
    for (i=1; i<=n && ok; ++i)
        RF (i);

    return 0;
}
