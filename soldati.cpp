# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
vector <int> v[100005];
queue <int> q;
int i,j,n,m,x,y,start,ap[100005],maxx,maxim[100005];
void DFS (int k, int niv)
{
    int i;
    ap[k]=niv;
    for (i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i]]==0) DFS(v[k][i],niv+1);
        maxim[k]=max(maxim[k], maxim[v[k][i]]+1);

        maxx=max(maxx, maxim[k]);
    }
    if (v[k].size()==0) maxim[k]=1;
}
int main ()
{
    freopen ("soldati.in", "r", stdin);
    freopen ("soldati.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
    }
    for (i=1; i<=n; ++i)
        if (ap[i]==0) DFS(i,1);

    printf ("%d\n", maxx);
    return 0;
}
