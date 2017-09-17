# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
vector <int> v[350];
int ap[35000];
int i,j,n,m,x,y,nrfii,M,N;
void DFS (short k)
{
    short i;
    ap[k]=1;
    for (i=0; i<v[k].size(); ++i)
        if (ap[v[k][i]]==0) DFS(v[k][i]);
}
int main ()
{
    freopen ("teme.in", "r", stdin);
    freopen ("teme.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
    {
        if (!ap[i])
        {
            ++M;;
            DFS(i);
        }
    }
    printf ("%d\n", M);
    return 0;
}
