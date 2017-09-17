# include <fstream>
# include <vector>
# include <queue>
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
struct elem
{
    int e,i;
}X;
vector <elem> v[100005];
vector <int> q;
int i,j,n,m,x,y,ok,var,k;
int ap[100005],viz[500005];
void DFS (int k)
{
    int i;
    ap[k]=1; ++var;
    for (i=0; i<v[k].size(); ++i)
        if (!ap[v[k][i].e]) DFS(v[k][i].e);
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
    q.push_back(1);
    while (!q.empty())
    {
        k=q.back();
        while (v[k].size() && viz[v[k][v[k].size()-1].i]==1)
            v[k].pop_back();
        if (v[k].size()==0)
        {
            q.pop_back();
            g<<k<<" ";
            continue;
        }
        q.push_back(v[k][v[k].size()-1].e);

        viz[v[k][v[k].size()-1].i]=1;
        v[k].pop_back();
    }
    return 0;
}
