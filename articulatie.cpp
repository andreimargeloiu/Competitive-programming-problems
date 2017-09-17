# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("articulatie.in");
ofstream g("articulatie.out");
vector <int> v[1000];
int low[1000],fii[1000],niv[1000],ap[1000];
int i,j,n,m,x,y,ok;
void DFS(int k, int nivel, int parinte)
{
    ap[k]=1; niv[k]=nivel; low[k]=nivel;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i]]==0)
        {
            ++fii[k];
            DFS(v[k][i], nivel+1, k);
        }
        if (v[k][i]!=parinte) low[k]=min(low[k], low[v[k][i]]);
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
    DFS(1,1,0);
    if (fii[1]>1) g<<"1\n";
    for (i=2; i<=n; ++i)
    {
        ok=1;
        for (j=0; j<v[i].size(); ++j)
            if (low[v[i][j]]>=niv[i]) ok=0;
        if (!ok) g<<i<<"\n";
    }
    return 0;
}
