# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("jungla.in");
ofstream g("jungla.out");
vector <int> v[500005],sol;
int minn,i,j,n,m,x,y;
int ap[500005],niv[500005],P[500005];
void DFS (int k, int nivel, int parinte)
{
    ap[k]=1; P[k]=parinte; niv[k]=nivel;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (v[k][i]==parinte) continue;
        if (!ap[v[k][i]]) DFS(v[k][i], nivel+1, k);
        else {
                 int var=nivel-niv[v[k][i]];
                 if (var%2==1 && var>2 && var<minn)
                 {
                     minn=var+1; sol.clear();
                     int aux=k;
                     for (int j=1; j<=minn; ++j)
                     {
                         sol.push_back(aux);
                         aux=P[aux];
                     }
                 }
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
    minn=100000;
    for (i=1; i<=n; ++i)
    {
        if (!ap[i]) DFS (i,1,0);
    }
    g<<minn<<"\n";
    for (i=sol.size()-1; i>=0; --i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
