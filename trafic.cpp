# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 105
# define inf 999999999
using namespace std;
ifstream f("trafic.in");
ofstream g("trafic.out");
struct elem
{
    int y, minute;
}E;
vector <elem> v[NR], vt[NR];
vector <int> sol[NR*NR];
struct copie
{
    int x, y, minute, v;
}a[NR*NR];
queue <int> q;
int i,j,n,x,y,VV,minn,nrsol,S,va,vn,m;


int ap[NR], D[NR], stiva[NR], st[NR*NR];
void BF (int k)
{
    int i,j,urm, dist;
    for (i=1; i<=n; ++i)
        D[i]=inf;

    D[k]=0; q.push(k);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i].y; dist=v[k][i].minute;
            if (D[urm] > D[k] + dist)
            {
                D[urm]=D[k]+dist;
                q.push(urm);
            }
        }
    }
    minn=D[y];
}
void DFS (int k)
{
    if (k==x)
    {
        ++nrsol; sol[nrsol].clear(); sol[nrsol].push_back(x);
        for (int i=S; i>=1; --i)
            sol[nrsol].push_back(stiva[i]);
    }
    else {
             stiva[++S]=k;
             for (int i=0; i<vt[k].size(); ++i)
             {
                 int urm=vt[k][i].y, dist=vt[k][i].minute;

                 if (D[k]-dist==D[urm]) DFS (urm);
             }
             stiva[S]=0; --S;
         }
}
int main ()
{
    f>>n>>m>>va>>vn;
    // D=(va-v)/3

    for (i=1; i<=m; ++i)
    {
        f>>a[i].x>>a[i].y>>a[i].minute>>a[i].v; x=a[i].x; y=a[i].y;

        if (a[i].v>=va) st[++VV]=i; //nu se poate practica drumul
        else {
                 if (a[i].v>vn)
                 {
                     st[++VV]=i;
                     a[i].minute+=((va-a[i].v)/3);
                 }
                 E.y=y; E.minute=a[i].minute;
                 v[x].push_back(E);

                 E.y=x; vt[y].push_back(E);
             }
    }
    for (i=1; i<=VV; ++i)
    {
        x=a[st[i]].x; y=a[st[i]].y;
        BF (x);


        if (minn==inf)
        {
            g<<x<<" "<<y<<" "<<"0 -1\n";
        }
        else {
                nrsol=0; S=0;
                DFS (y);

                g<<x<<" "<<y<<" "<<nrsol<<" "<<D[y]<<"\n";

                for (j=1; j<=nrsol; ++j)
                {
                    for (int o=0; o<sol[j].size(); ++o)
                        g<<sol[j][o]<<" ";
                    g<<"\n";
                }
             }
    }



    return 0;
}
