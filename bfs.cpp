# include <fstream>
# include <vector>
# include <queue>
# include <cstring>
using namespace std;
ifstream f("bfs.in");
ofstream g("bfs.out");
vector <int> a[100010];
queue <int> q;
int i,j,n,m,x,y,start,cost[100010];
void bfs (int start)
{
    int i;
    memset(cost,-1,sizeof(cost));

    cost[start]=0;
    q.push(start);

    while (! q.empty())
    {
        x=q.front (); q.pop ();
        for (i=0; i<a[x].size(); ++i)
        {
            if (cost[a[x][i]]==-1)
            {
                cost[a[x][i]]=cost[x]+1;
                q.push(a[x][i]);
            }
        }
    }
}
int main ()
{
    f>>n>>m>>start;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        a[x].push_back(y);
    }

    bfs(start);

    for (i=1; i<=n; ++i)
        g<<cost[i]<<" ";
    g<<"\n";
    return 0;
}
