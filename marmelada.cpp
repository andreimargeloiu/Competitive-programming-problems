# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
# define inf 999999999
using namespace std;
ifstream f("marmelada.in");
ofstream g("marmelada.out");
struct elem
{
    int y, nr;
}E;
vector <elem> v[100005];
queue <int> q;
struct var
{
    int cost, nr;
}c[100005];
bool cmp (var x, var y)
{
    if (x.cost>=y.cost) return 0;
        else return 1;
}
int i,j,n,m,x,y,X,Y,VV,S;
int cost[100005],dist[100005];
void BF ()
{
    int k,i;
    dist[X]=1;
    q.push(X);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (dist[v[k][i].y]==0 || dist[v[k][i].y]>dist[k]+1)
            {
                dist[v[k][i].y]=dist[k]+1;
                q.push(v[k][i].y);
            }
        }
    }
}
int main ()
{
    f>>n>>m>>X>>Y;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y; E.nr=i;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    for (i=1; i<=m; ++i)
        {f>>c[i].cost; c[i].nr=i;}
    BF ();

    sort (c+1, c+m+1, cmp);
    S=Y;
    while (dist[S]!=1)
    {
        for (i=0; i<v[S].size(); ++i)
        {
            if (dist[v[S][i].y]==dist[S]-1)
            {
                cost[v[S][i].nr]=c[++VV].nr; c[VV].cost=inf;
                S=v[S][i].y;
                break;
            }
        }
    }
    sort (c+1, c+m+1, cmp); VV=0;
    for (i=1; i<=m; ++i)
    {
        if (cost[i]) g<<cost[i]<<"\n";
            else g<<c[++VV].nr<<"\n";
    }
    return 0;
}
