# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define LB(p) ((-p)&p)
# define NR 100005
# define mod 1999999973
using namespace std;
vector <int> v[NR], vt[NR], sol[NR];
ifstream f("ctc.in");
ofstream g("ctc.out");
int i,j,n,m,x,y,nrsol,VV;
int ap[NR], st[NR];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
    st[++VV]=k;
}
void DFSt (int k)
{
    ap[k]=1; sol[nrsol].push_back(k);
    for (int i=0; i<vt[k].size(); ++i)
        if (! ap[vt[k][i]]) DFSt (vt[k][i]);
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        vt[y].push_back(x);
    }

    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS (i);
    memset (ap, 0, sizeof(ap));

    for (i=n; i>=1; --i)
        if (!ap[st[i]])
        {
            ++nrsol;
            DFSt (st[i]);
        }
    g<<nrsol<<"\n";
    for (i=1; i<=nrsol; ++i)
    {
        for (j=0; j<sol[i].size(); ++j)
            g<<sol[i][j]<<" ";
        g<<"\n";
    }

    return 0;
}
