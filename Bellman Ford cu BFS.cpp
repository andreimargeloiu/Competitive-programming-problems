# include <fstream>
# include <vector>
# include <queue>
# include <algorithm>
# define inf 1000000000
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
struct elem
{
    int y,val;
}X,Y;
vector <elem> v[50005];
queue <int> q;
int i,j,n,m,x,y;
int dist[50005];
void BFS ()
{
    int k,i;
    q.push(1);
    while (!q.empty())
    {
        k=q.front (); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (dist[v[k][i].y]>dist[k]+v[k][i].val)
            {
                dist[v[k][i].y]=dist[k]+v[k][i].val;
                q.push(v[k][i].y);
            }
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=2; i<=n; ++i)
        dist[i]=inf;
    for (i=1; i<=m; ++i)
    {
        f>>x>>X.y>>X.val;
        v[x].push_back(X);
    }
    BFS();
    for (i=2; i<=n; ++i)
    {
        if (dist[i]==inf) g<<"0 ";
        else g<<dist[i]<<" ";
    }

    return 0;
}
