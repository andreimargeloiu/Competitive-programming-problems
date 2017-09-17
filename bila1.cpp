# include <fstream>
# include <vector>
using namespace std;
ifstream f("bile1.in");
ofstream g("bile1.out");
vector <int> v[305],q[305];
int i,j,n,m,x,y,nrelem;
int mic[305],mare[305],sol[305],var[305][305],ap[305],ap2[305];
void DFS (int k, int ver)
{
    int i;
    ++mic[ver]; ap[k]=ver;
    for (i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i]]!=ver) DFS(v[k][i],ver);
    }
}
void DFS2 (int k, int ver)
{
    int i;
    ++mare[ver]; ap2[k]=ver;
    for (i=0; i<q[k].size(); ++i)
    {
        if (ap2[q[k][i]]!=ver) DFS2(q[k][i],ver);
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        if (var[x][y]==1) continue;
        var[x][y]=1;
        v[x].push_back(y);
        q[y].push_back(x);
    }
    //cate sunt mai mici
    for (i=1; i<=n; ++i)
        DFS(i,i);
    for (i=1; i<=n; ++i)
        if (mic[i]-1>=(n+1)/2) sol[i]=1;
    //cate sunt mai mari
    for (i=1; i<=n; ++i)
        DFS2(i,i);
    for (i=1; i<=n; ++i)
        if (mare[i]-1>=(n+1)/2) sol[i]=1;
    for (i=1; i<=n; ++i)
        nrelem+=sol[i];
    g<<nrelem<<"\n";
    return 0;
}
