# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
struct elem
{
    int x,y,cost;
}E,vect[400005];

int i,j,n,m,VV,p,drumuri,cost;
int R[10005], H[10005], sol[10005];
int radacina (int k)
{
    while (k!=R[k]) k=R[k];
    return k;
}
bool cmp (elem x, elem y)
{
    if (x.cost>=y.cost) return 0;
    else return 1;
}
void APM ()
{
    int Rx, Ry;
    sort (vect+1, vect+VV+1, cmp);
    for (int i=1; i<=n; ++i)
        R[i]=i, H[i]=1;

    for (int i=1; i<=VV; ++i)
    {
        Rx=radacina(vect[i].x);
        Ry=radacina(vect[i].y);
        if (Rx!=Ry)
        {
            cost+=vect[i].cost;
            if (vect[i].cost!=0) sol[++drumuri]=i;
            if (H[Rx]>H[Ry]) H[Rx]+=H[Ry], R[Ry]=Rx;
                        else H[Ry]+=H[Rx], R[Rx]=Ry;
        }
    }
}
int main ()
{
    freopen ("flood.in", "r", stdin);
    freopen ("flood.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &E.x, &E.y); E.cost=0;
        vect[++VV]=E;
    }
    scanf ("%d", &p);
    for (i=1; i<=p; ++i)
    {
        scanf ("%d%d%d", &E.x, &E.y, &E.cost);
        vect[++VV]=E;
    }

    APM ();

    printf ("%d\n%d\n", drumuri, cost);
    for (i=1; i<=drumuri; ++i)
        printf ("%d %d %d\n", vect[sol[i]].x, vect[sol[i]].y, vect[sol[i]].cost);

    return 0;
}


