# include <fstream>
# include <vector>
# include <queue>
# define inf 99999999;
using namespace std;
ifstream f("orient.in");
ofstream g("orient.out");
struct elem
{
    int x,y;
}muchie[3005];
vector <int> v[1005];
queue <int> q;
int i,j,n,m,x,y,tata,c,minn;
int cost[1005][1005];
int CC[1005];
void init ()
{
    for (int i=1; i<=n; ++i)
        CC[i]=inf;
}
void BF (int k, int x)
{
    int i,X=k,Y=x;
    CC[k]=0;
    q.push(k);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        if (CC[k]>CC[x]) continue;
        for (i=0; i<v[k].size(); ++i)
        {
            if (k==X && v[k][i]==x) continue;
            if (CC[k]+cost[k][v[k][i]]<CC[v[k][i]])
            {
                CC[v[k][i]]=CC[k]+cost[k][v[k][i]];
                q.push(v[k][i]);
            }
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>c;
        muchie[i].x=x; muchie[i].y=y;
        cost[x][y]=0; cost[y][x]=c;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    minn=inf;
    for (i=1; i<=m; ++i)
    {
        init ();
        BF (muchie[i].y, muchie[i].x);
        if (CC[muchie[i].x]+cost[x][y]<minn) minn=CC[muchie[i].x]+cost[x][y];
    }
    g<<minn<<"\n";
    return 0;
}
