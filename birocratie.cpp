# include <fstream>
# include <vector>
using namespace std;
ifstream f("birocratie.in");
ofstream g("birocratie.out");
vector <int> v[1005];
int i,j,n,m,k,ok,x,y,q,cam,K;
int ap[1005],nr[1005];
char ch[1005];
void DFS (int k)
{
    ap[k]=1; nr[k]=1;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (!ap[v[k][i]]) DFS(v[k][i]);
        nr[k]+=nr[v[k][i]]+1;
    }
}
void cauta (int k)
{
    if (!ok) return;
    if (K==1) ok=0, g<<ch[k]<<"\n";
       else --K;
    for (int i=0; i<v[k].size() && ok; ++i)
    {
        if (K-nr[v[k][i]]>0)
        {
            K=K-nr[v[k][i]];
            if (K==1) ok=0, g<<ch[k]<<"\n";
            --K;
        }
        else cauta (v[k][i]);
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
    {
        f>>ch[i]>>x;
        for (j=1; j<=x; ++j)
        {
            f>>y;
            v[i].push_back(y);
        }
    }
    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS(i);
    for (q=1; q<=m; ++q)
    {
        f>>cam>>K;
        ok=1;
        cauta(cam);
    }
    return 0;
}
