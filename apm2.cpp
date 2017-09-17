# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
ifstream f("apm2.in");
ofstream g("apm2.out");
struct elem
{
    int nod, cost;
}E;
struct elem2
{
    int x, y, cost;
}a[100005];
vector <elem> v[10005];
int i,j,n,m,q,x,y,VV,ok;
int R[10005],cost[10005],ap[10005],H[10005],maxx[10005];
bool cmp (elem2 x, elem2 y)
{
    if (x.cost>=y.cost) return 0;
        else return 1;
}
int radacina (int x)
{
    while (R[x]!=x)
        x=R[x];
    return x;
}
void APM ()
{
    int Rx, Ry;
    for (i=1; i<=m; ++i)
    {
        Rx=radacina(a[i].x);
        Ry=radacina(a[i].y);
        if (Rx!=Ry)
        {
            if (H[Rx]>H[Ry]) R[Ry]=Rx,H[Rx]+=H[Ry];
            else R[Rx]=Ry,H[Ry]+=H[Rx];

            //adaug muchia in graf
            E.nod=a[i].y; E.cost=a[i].cost;
            v[a[i].x].push_back(E);
            E.nod=a[i].x; E.cost=a[i].cost;
            v[a[i].y].push_back(E);
        }
    }
}
void DFS (int k, int o)
{
    ap[k]=o;
    if (k==y) ok=0;
    for (int i=0; i<v[k].size() && ok; ++i)
    {
        if (ap[v[k][i].nod]!=o)
        {
            maxx[v[k][i].nod]=max(maxx[k], v[k][i].cost);
            DFS (v[k][i].nod, o);
        }
    }
}
int main ()
{
    f>>n>>m>>q;
    //radacina inititala
    for (i=1; i<=n; ++i)
        R[i]=i,H[i]=1;
    for (i=1; i<=m; ++i)
        f>>a[i].x>>a[i].y>>a[i].cost;
    sort (a+1,a+m+1,cmp);
    APM ();
    for (i=1; i<=q; ++i)
    {
        f>>x>>y;
        maxx[x]=0; ok=1;
        DFS (x,i);
        g<<maxx[y]-1<<"\n";
    }
    return 0;
}
