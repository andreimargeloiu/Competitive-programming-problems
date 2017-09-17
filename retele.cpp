# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
ifstream f("retele.in");
ofstream g("retele.out");
vector <int> v[50005],T[50005],sol[50005];
int i,j,n,m,x,y,VV,nr;
int ap[50005],ord[50005],grupa[50005];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
    ord[++nr]=k;
}
void DFSt (int k)
{
    ap[k]=0;
    for (int i=0; i<T[k].size(); ++i)
        if (ap[T[k][i]]) DFSt (T[k][i]);
    sol[VV].push_back(k);
    grupa[k]=VV;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        T[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS (i);
    for (i=n; i>=1; --i)
    {
        if (ap[ord[i]])
        {
            ++VV;
            DFSt (ord[i]);
        }
    }
    g<<VV<<"\n";
    for (i=1; i<=n; ++i)
    {
        if (sol[grupa[i]].size())
        {
            g<<sol[grupa[i]].size()<<" ";
            sort (sol[grupa[i]].begin(), sol[grupa[i]].end());
            for (j=0; j<sol[grupa[i]].size(); ++j)
                g<<sol[grupa[i]][j]<<" ";
            g<<"\n";
            sol[grupa[i]].clear();
        }
    }

    return 0;
}
