# include <fstream>
# include <vector>
using namespace std;
ifstream f("cristal.in");
ofstream g("cristal.out");
vector <int> v[55];
int i,j,n,m,x,y,ok,NR,VV;
int ap[100],sol[100];
void dfs (int k)
{
    int i;
    ap[k]=ok; ++NR;
    for (i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i]]!=ok) dfs(v[k][i]);
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
        ap[i]=i; ok=i; NR=0;
        if (i==1) dfs (2);
            else dfs(1);
        if (NR==n-1) sol[++VV]=i;
    }
    for (i=1; i<=VV; ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
