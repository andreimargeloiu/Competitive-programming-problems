# include <fstream>
# include <vector>
# include <algorithm>
# define NR 100
using namespace std;
ifstream f("gripa.in");
ofstream g("gripa.out");
vector <int> v[NR];
int i,j,n,m,VV,x,y,k,Q,nr,nrsol,NOT;
int ap[NR], a[NR][NR];
void DFS (int k)
{
    ap[k]=VV; ++nr;
    for (int i=0; i<v[k].size(); ++i)
        if (ap[v[k][i]]!=VV && a[k][v[k][i]]!=NOT) DFS(v[k][i]);
}
int main ()
{
    f>>n;
    while (f>>x)
    {
        f>>y; ++Q;
        a[x][y]=Q; a[y][x]=Q;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
            if (a[i][j])
            {
                NOT=a[i][j]; ++VV; nr=0;
                DFS(i);
                if (nr!=n) ++nrsol;
            }

    g<<nrsol<<"\n";

    return 0;
}
