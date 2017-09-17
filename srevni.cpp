# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("srevni.in");
ofstream g("srevni.out");
vector <int> v[NR];
struct elem
{
    int nr, cost;
}a[NR];
bool cmp (elem x, elem y)
{
    if (x.cost>=y.cost) return 0;
        return 1;
}
int i,j,n,m,x,y;
int sol[NR];
void DFS (int k, int val)
{
    sol[k]=val;
    for (int i=0; i<v[k].size(); ++i)
        if (! sol[v[k][i]]) DFS (v[k][i], val);
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
    { f>>a[i].cost; a[i].nr=i; }

    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[y].push_back(x);
    }

    sort (a+1, a+n+1, cmp);

    for (i=1; i<=n; ++i)
    {
        if (! sol[a[i].nr]) DFS (a[i].nr, a[i].cost);
    }

    for (i=1; i<=n; ++i)
    {
        g<<sol[i]<<" ";
    }
    g<<"\n";

    return 0;
}
