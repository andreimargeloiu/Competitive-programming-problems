# include <fstream>
# include <algorithm>
# include <vector>
# define NR 105
using namespace std;
ifstream f("agentia.in");
ofstream g("agentia.out");
vector <int> v[NR];
int i,j,n,m,x,VV;
bool ap[NR];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>m;
        for (j=1; j<=m; ++j)
        {
            f>>x;
            v[i].push_back(x);
            v[x].push_back(i);
        }
    }

    for (i=1; i<=n; ++i)
    {
        if (! ap[i])
        {
            ++VV;
            DFS (i);
        }
    }
    g<<VV<<"\n";

    return 0;
}
