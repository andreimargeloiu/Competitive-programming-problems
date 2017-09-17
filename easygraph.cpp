# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;
ifstream f("easygraph.in");
ofstream g("easygraph.out");
vector <int> v[15005];
queue <int> q;
int i,j,n,m,x,y,c,o,t;
int in[15005];
long long nod[15005],cost[15005],maxx;
void calc ()
{
    int i,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            --in[v[k][i]];
            if (in[v[k][i]]==0) q.push(v[k][i]);
            if (nod[v[k][i]]+cost[k]>cost[v[k][i]])
            {
                cost[v[k][i]]=nod[v[k][i]]+cost[k];
            }
        }
    }
}
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n>>m;
        for (i=1; i<=n; ++i)
        {
            f>>nod[i]; v[i].clear();
            in[i]=0; cost[i]=nod[i];
        }
        for (i=1; i<=m; ++i)
        {
            f>>x>>y;
            v[x].push_back(y);
            ++in[y];
        }
        for (i=1; i<=n; ++i)
            if (in[i]==0) q.push(i);

        calc();
        maxx=cost[1];
        for (i=1; i<=n; ++i)
            maxx=max(maxx,cost[i]);
        g<<maxx<<"\n";
    }
    return 0;
}
