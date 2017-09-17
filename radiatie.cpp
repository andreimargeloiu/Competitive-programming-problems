# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("radiatie.in");
ofstream g("radiatie.out");
struct elem
{
    int x,y,cost;
}E,v[30005];
bool cmp (elem x, elem y)
{
    if (x.cost>=y.cost) return 0;
        else return 1;
}
int i,j,n,m,x,y,c,VV,k,sol,X,Y,ok;
int R[15005], cost[15005], C[15005], level[15005];
int radacina (int k)
{
    while (k!=R[k])
        k=R[k];
    return k;
}
void APM ()
{
    int i,Rx,Ry;
    for (i=1; i<=n; ++i)
        R[i]=i;
    VV=1;
    for (i=1; i<=m; ++i)
    {
        Rx=radacina(v[i].x);
        Ry=radacina(v[i].y);
        if (Rx!=Ry)
        {
            R[Rx]=Ry;
            cost[Rx]=v[i].cost;
        }
    }
}
void lvl(int x)
{
    if(R[x]==x) return ;
    lvl(R[x]);
    level[x]=level[R[x]]+1;
}
int main ()
{
    f>>n>>m>>k;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>c;
        v[i].x=x; v[i].y=y; v[i].cost=c;
    }
    sort (v+1, v+m+1, cmp);
    APM();
    for(i=1; i<=n; ++i)
        if(!level[i]) lvl(i);
    for(i=1; i<=k; ++i)
    {
        f>>x>>y;
        sol=0;
        while(level[x]<level[y])
        {
            sol=max(sol, cost[y]);
            y=R[y];
        }
        while(level[x]>level[y])
        {
            sol=max(sol, cost[x]);
            x=R[x];
        }
        while(x!=y)
        {
            sol=max(sol,cost[x]);
            sol=max(sol,cost[y]);
            x=R[x];
            y=R[y];
        }
        g<<sol<<"\n";
    }
    return 0;
}
