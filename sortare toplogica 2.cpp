//varianta cu DFS
# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
vector <int> v[50005];
int sol[50005],ap[50005];
int i,j,n,m,x,y,nrsol;
void DFS (int k)
{
    int i;
    ap[k]=1;
    for (i=0; i<v[k].size(); ++i)
        if (ap[v[k][i]]==0) DFS(v[k][i]);
    sol[++nrsol]=k;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
    }
    for (i=1; i<=n; ++i)
        if (!ap[i]) DFS(i);
    for (i=n; i>=1; --i)
        g<<sol[i]<<" ";
    g<<"\n";
    return 0;
}
