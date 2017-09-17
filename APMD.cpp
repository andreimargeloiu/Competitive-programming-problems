# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
# define inf 999999999
using namespace std;
ifstream f("apdm.in");
ofstream g("apdm.out");
queue <int> q;
vector <int> v[155];
int i,j,n,m,x,y,o,maxx,minn,maxim,S;
int tata[155],ap[155],dist[155];
void BF (int k)
{
    int i;
    dist[k]=0; tata[k]=0; maxx=0;
    q.push(k);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        if (dist[k]>maxx) maxx=dist[k], S=k;
        for (i=0; i<v[k].size(); ++i)
        {
            if (dist[k]+1<dist[v[k][i]])
            {
                dist[v[k][i]]=dist[k]+1;
                tata[v[k][i]]=k;
                q.push(v[k][i]);
            }
        }
    }
}
void DFS (int k, int niv)
{
    if (niv>maxim) maxim=niv;
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (!ap[v[k][i]] && (tata[v[k][i]]==k || v[k][i]==tata[k]))
        {
            DFS (v[k][i], niv+1);
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    minn=inf;
    for (o=1; o<=n; ++o)
    {
        for (j=1; j<=n; ++j)
            dist[j]=inf,ap[j]=0;
        BF (o);

        maxim=0;
        DFS (S,0);
        if (maxim<minn) minn=maxim;
    }
    g<<minn<<"\n";

    return 0;
}
