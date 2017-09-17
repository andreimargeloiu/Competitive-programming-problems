# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
# define inf 999999999
# define NR 50000
using namespace std;
ifstream f("catun.in");
ofstream g("catun.out");
struct elem
{
    int y, cost;
}E;
vector <elem> v[NR];
queue <int> q;
int i,j,n,m,x,y,K,cost;
int dist[NR], come[NR];
bool fort[NR];
void BF ()
{
    int i,urm,cost,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i].y; cost=v[k][i].cost;
            if (dist[urm]>dist[k]+cost || (dist[urm]==dist[k]+cost && come[k]<come[urm]))
            {
                dist[urm]=dist[k]+cost;
                come[urm]=come[k];
                q.push (urm);
            }
        }
    }
}
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<=K; ++i)
        {f>>x; fort[x]=1; q.push(x);}
    for (i=1; i<=n; ++i)
        if (! fort[i])
        {
            dist[i]=inf;
            come[i]=inf;
        }
        else come[i]=i;

    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>cost;
        E.y=y; E.cost=cost; v[x].push_back(E);
        E.y=x; E.cost=cost; v[y].push_back(E);
    }
    BF ();
    for (i=1; i<=n; ++i)
    {
        if (come[i]==i || come[i]==inf) g<<"0 ";
        else g<<come[i]<<" ";
    }
    g<<"\n";

    return 0;
}
