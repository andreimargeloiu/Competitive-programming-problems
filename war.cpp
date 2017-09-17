# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
vector <int> a[500];
struct elem
{
    int x,y,cost;
}v[500005];
bool cmp (elem x, elem y)
{
    if (x.cost>=y.cost) return 0;
        else return 1;
}
int i,j,n,m,x,y,cost,VV,S,K,nr;
int marime[1005],R[1005],var[500005];
void init ()
{
    for (int i=1; i<=n; ++i)
        marime[i]=1, R[i]=i;
}
int radacina(int k)
{
    while (k!=R[k])
        k=R[k];
    return k;
}
void APM ()
{
    int i,j;
    int Rx,Ry;
    for (j=1; j<=m && K<n; ++j)
    {
        i=var[j];
        Rx=radacina(v[i].x);
        Ry=radacina(v[i].y);
        if (Rx!=Ry)
        {
            ++K; VV+=v[i].cost;
            if (marime[Rx]>marime[Ry]) R[Ry]=Rx, marime[Rx]+=marime[Ry];
                else R[Rx]=Ry, marime[Ry]+=marime[Rx];
        }
    }

}
int main ()
{
    freopen ("war.in", "r", stdin);
    freopen ("war.out", "w", stdout);

    scanf ("%d%d%d", &n, &m, &K);
    init ();
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &cost);
        cost/=1000;
        a[cost].push_back(i);
        v[i].x=x; v[i].y=y; v[i].cost=cost;
    }
    for (i=1; i<=250; ++i)
        for (j=0; j<a[i].size(); ++j)
            var[++nr]=a[i][j];

    S=n+1; marime[S]=1;
    for (i=1; i<=K; ++i)
    {
        scanf ("%d", &x);
        ++marime[S]; R[x]=S;
    }
    APM ();

    if (K!=n) printf ("-1\n");
        else printf ("%d\n", VV*1000);

    return 0;
}
