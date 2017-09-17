# include <fstream>
# include <vector>
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
struct elem
{
    int e,i;
}X;
vector <elem> v[100005];
int i,j,n,m,x,y,ok,var,k;
int ap[100005],tip[500005],viz[500005],var[100005];
void DFS (int k)
{
    int i;
    ap[k]=1; ++var;
    for (i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i].e]==0) {
                                 tip[v[k][i].i]=1;//de inaintare
                                 DFS(v[k][i].e);
                              }
           else if (tip[v[k][i].i]==0) tip[v[k][i].i]=2;//de intoarcere
    }
}
void DFS2 (int k)
{
    int i;
    //aleg mai intai muchiile de intoarcere
    for (i=0; i<v[k].size(); ++i)
        if (viz[v[k][i].i]==0)
            if (tip[v[k][i].i]==2)
            {
                g<<k<<" "; viz[v[k][i].i]=1;
                DFS2(v[k][i].e);
            }

    for (i=0; i<v[k].size(); ++i)
        if (viz[v[k][i].i]==0)
            if (tip[v[k][i].i]==1)
            {
                g<<k<<" "; viz[v[k][i].i]=1;
                DFS2(v[k][i].e);
            }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        X.e=y; X.i=i;
        v[x].push_back(X);
        X.e=x; X.i=i;
        v[y].push_back(X);
    }
    ok=1; DFS(1);
    for (i=1; i<=n; ++i)
        if (v[i].size()%2==1) ok=0;
    if (var!=n) ok=0;
    if (!ok)
    {
        g<<"-1\n";
        return 0;
    }
    DFS2(1);
    g<<"1\n";

    return 0;
}
