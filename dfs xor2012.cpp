# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
vector <int> v[1005];
int ap[1005],drum[1005],mat[1005][1005];
int i,j,n,m,x,y,D,muchii,var;
void DFS (int k)
{
    ap[k]=1; drum[++D]=k;
    for (int i=0; i<v[k].size(); ++i)
        if (ap[v[k][i]]==0) DFS(v[k][i]);
}
void DFS2 (int k)
{
    ap[k]=1;
    for (int i=1; i<=n; ++i)
    {
        if (mat[k][i]==1 && ap[i]==0)
        {
            if (drum[var]==i) ++var,DFS2(i);
                else --muchii,mat[k][i]=0,mat[i][k]=0;
        }
    }
}
int main ()
{
    freopen ("dfs.in", "r", stdin);
    freopen ("dfs.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        sort(v[i].begin(), v[i].end());
    DFS(1);
    //etapa 2
    for (i=1; i<=n; ++i)
        ap[i]=0;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            if (i!=j) mat[i][j]=1;
    muchii=(n-1)*n/2; var=2;
    DFS2(1);

    printf ("%d\n", muchii-m);
    return 0;
}
