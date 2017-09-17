# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;
ifstream f("camionas.in");
ofstream g("camionas.out");
struct elem
{
    int nod, cost;
}E;
struct unu
{
    int x, y;
}unu[100005];
vector <elem> v[50005];
vector <int> c[50005];
queue <int> q;
int i,j,n,m,G,x,y,cost,VV,conexe;
int dist[50005],comp[50005];
bool ap[50005];
void DFS (int k)
{
    ap[k]=1; comp[k]=conexe;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (! ap[v[k][i].nod] && v[k][i].cost==0)
        {
            DFS (v[k][i].nod);
        }
    }
}
void BFS ()
{
    int i,k;
    q.push(1);
    dist[1]=0;
    while (! q.empty())
    {
        k=q.front (); q.pop();
        for (i=0; i<c[k].size(); ++i)
        {
            if (dist[c[k][i]]>dist[k]+1)
            {
                dist[c[k][i]]=dist[k]+1;
                q.push(c[k][i]);
            }
        }
    }
}
int main ()
{
    f>>n>>m>>G;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>cost;
        if (cost<G) E.cost=1;
            else E.cost=0;
        if (E.cost==1)
        {
            unu[++VV].x=x;
            unu[VV].y=y;
        }
        E.nod=y;
        v[x].push_back(E);
        E.nod=x;
        v[y].push_back(E);
    }
    for (i=1; i<=n; ++i)
    {
        if (! ap[i])
        {
            ++conexe;
            DFS (i);
        }
    }
    for (i=1; i<=VV; ++i)
    {
        c[comp[unu[i].x]].push_back(comp[unu[i].y]);
        c[comp[unu[i].y]].push_back(comp[unu[i].x]);
    }
    for (i=1; i<=conexe; ++i)
        dist[i]=999999;
    BFS ();
    g<<dist[comp[n]]<<"\n";
    return 0;
}
