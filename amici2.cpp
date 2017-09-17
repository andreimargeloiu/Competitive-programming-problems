# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 21005
using namespace std;
ifstream f("amici2.in");
ofstream g("amici2.out");
vector <int> v[NR];
queue <int> q;
int i,j,n,m,x,y,maxx,t,o,put;
int dist[NR];
void initializare()
{
    for (int i=1; i<=n; ++i)
        {v[i].clear(); dist[i]=0;}
}
void BFS (int k)
{
    maxx=0;
    q.push(k); dist[k]=1;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (int i=0; i<v[k].size(); ++i)
            if (! dist[v[k][i]])
            {
                dist[v[k][i]]=dist[k]+1;
                q.push(v[k][i]);
                maxx=max(maxx, dist[v[k][i]]);
            }
    }
    --maxx;
}
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        initializare();
        f>>n>>m;
        for (i=1; i<=m; ++i)
        {
            f>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        BFS (1);

        put=0;
        while ((1<<put)<maxx) ++put;

        g<<put+1<<"\n";
    }


    return 0;
}
