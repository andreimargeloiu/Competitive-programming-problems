# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
ifstream f("dfs.in");
ofstream g("dfs.out");
vector <int>v[100005];
int ap[100005],L[100005];
int i,n,m,K,x,y;
void DFS (int k)
{
    int i;
    ap[k]=K;
    for (i=0; i<L[k]; ++i)
    {
        if (ap[v[k][i]]==0) DFS(v[k][i]);
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
    for (i=1; i<=n; ++i)
    {
        L[i]=v[i].size();
    }
    for (i=1; i<=n; ++i)
    {
        if (ap[i]==0)
        {
            ++K;
            DFS (i);
        }
    }
    g<<K<<"\n";
    return 0;
}
