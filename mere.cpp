# include <fstream>
# include <vector>
# include <cmath>
using namespace std;
ifstream f("mere.in");
ofstream g("mere.out");
vector <int> v[202];
int ap[202],x[202],y[202],z[202],r[202];
int i,j,n,nr;
void dfs (int k)
{
    int i;
    ap[k]=1; ++nr;
    for (i=0; i<v[k].size(); ++i)
        if (!ap[v[k][i]]) dfs(v[k][i]);
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>x[i]>>y[i]>>z[i]>>r[i];

    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            if (z[i]>z[j])
               if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=(r[i]+r[j])*(r[i]+r[j])) v[i].push_back(j);
    dfs (1);
    g<<nr<<"\n";
    return 0;
}
