# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
vector <int> v[20000];
int i,j,n,x,y,maxx;
int val[20005], ap[20005];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (!ap[v[k][i]])
        {
            DFS(v[k][i]);
            if (val[v[k][i]]+val[k]>val[k]) val[k]+=val[v[k][i]];
        }
    }
    maxx=max(maxx, val[k]);
}
int main ()
{
    freopen ("asmax.in", "r", stdin);
    freopen ("asmax.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &val[i]);
    maxx=val[1];
    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1);
    printf ("%d\n", maxx);
    return 0;
}
