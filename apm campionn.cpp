# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
struct elem
{
    int nod, cost;
}E;
vector <elem> v[500];
struct drumuri
{
    int x, y, cost;
}D[100005];
bool cmp (drumuri x, drumuri y)
{
    if (x.cost>=y.cost) return 0;
        else return 1;
}
bool cmp2 (int x, int y)
{
    if (x<=y) return 0;
        else return 1;
}
int i,j,n,mx,y,VV,nr,o,x,ok;
int cit[100005],ap[100005],unit[300][300];
void DFS (int k, int dist)
{
    ap[k]=o;
    D[++VV].x=o; D[VV].y=k; D[VV].cost=dist;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i].nod]!=o) DFS (v[k][i].nod, max(dist, v[k][i].cost));
    }
}
int main ()
{
    f>>n;
    for (i=1; i<n; ++i)
    {
        f>>x>>y>>E.cost;
        unit[x][y]=1;
        unit[y][x]=1;
        E.nod=y;
        v[x].push_back(E);
        E.nod=x;
        v[y].push_back(E);
    }
    for (o=1; o<=n; ++o)
        DFS (o,0);
    while (f>>x)
    {
        cit[++nr]=x;
    }
    sort (D+1, D+VV+1, cmp);
    sort (cit+1, cit+nr+1, cmp2);
    for (i=1; i<=nr; ++i)
    {
        while (VV && D[VV].cost>cit[i] || unit[D[VV].x][D[VV].y]) --VV;
        if (VV>n && D[VV].cost<=cit[i])
        {
            ok=1;
            g<<D[VV].x<<" "<<D[VV].y<<" "<<cit[i]<<"\n";
            unit[D[VV].x][D[VV].y]=1;
            unit[D[VV].y][D[VV].x]=1;
            --VV;
        }
    }
    if (!ok) g<<"0\n";
    return 0;
}
