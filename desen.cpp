# include <cstdio>
# include <cmath>
# include <algorithm>
# include <iomanip>
using namespace std;
struct elem
{
    int x,y;
}a[1005];
struct elem2
{
    int x,y;
    double val;
}var[2005];
int i,j,n,m,VV,o;
int H[1005],R[1005];
int cmp (const elem2 &x, const elem2 &y)
{
    return x.val<y.val;
}
int radacina (int k)
{
    while (k!=R[k])
        k=R[k];
    return k;
}
void APM ()
{
    int i,Rx,Ry,vv=0,busy=0;
    double cost=0;
    sort (var+1, var+VV+1, cmp);
    for (i=1; i<=VV && busy<o-1; ++i)
    {
        Rx=radacina(var[i].x);
        Ry=radacina(var[i].y);
        if (Rx!=Ry)
        {
            ++busy;
            cost+=var[i].val;
            var[++vv].x=var[i].x; var[vv].y=var[i].y; var[vv].val=var[i].val;
            if (H[Rx]>H[Ry]) R[Ry]=Rx, H[Rx]+=H[Ry];
                else R[Rx]=Ry, H[Ry]+=H[Rx];
        }
    }
    VV=vv;
    printf ("%f\n", cost);
}
int main ()
{
    freopen ("desen.in", "r", stdin);
    freopen ("desen.out", "w", stdout);
    scanf ("%d", &n);
    for (o=1; o<=n; ++o)
    {
        scanf ("%d%d", &a[o].x, &a[o].y);
        for (i=1; i<o; ++i)//noile laturi
        {
            R[i]=i; H[i]=1;

            var[++VV].val=sqrt((double)((a[o].x-a[i].x)*(a[o].x-a[i].x)+(a[o].y-a[i].y)*(a[o].y-a[i].y)));
            var[VV].x=i; var[VV].y=o;
        }
        R[o]=o; H[o]=1;
        APM ();
    }

    return 0;
}
