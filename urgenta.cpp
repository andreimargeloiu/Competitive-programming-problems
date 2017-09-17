# include <cstdio>
# include <algorithm>
using namespace std;
struct elem
{
    int x,y,cost;
}v[35000],sol[35000];
int i,j,n,m,k,x,y,Rx,Ry,grupe,VV,cost;
int R[300], H[300];
bool cmp (elem x, elem y)
{
    if (x.cost>=y.cost) return 0;
        else return 1;
}
int radacina (int k)
{
    while (k!=R[k])
        k=R[k];
    return k;
}
void APM ()
{
    for (i=1; i<=n; ++i)
        R[i]=i, H[i]=1;
    sort (v+1, v+m+1, cmp);
    grupe=n;
    for (i=1; i<=m; ++i)
    {
        Rx=radacina(v[i].x);
        Ry=radacina(v[i].y);
        if (Rx!=Ry && grupe!=k)
        {
            --grupe;
            if (H[Rx]>H[Ry]) R[Ry]=Rx, H[Rx]+=H[Ry];
            else R[Rx]=Ry, H[Ry]+=H[Rx];
        }
        else {
                 cost+=v[i].cost;
                 sol[++VV]=v[i];
             }
    }
}
int main ()
{
    freopen ("urgenta.in", "r", stdin);
    freopen ("urgenta.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &k);
    for (i=1; i<=m; ++i)
        scanf ("%d%d%d", &v[i].x, &v[i].y, &v[i].cost);

    APM();

    printf ("%d\n%d\n", cost, VV);
    for (i=1; i<=VV; ++i)
        printf ("%d %d\n", sol[i].x, sol[i].y);

    return 0;
}
