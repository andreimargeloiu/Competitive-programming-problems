# include <cstdio>
# include <vector>
# include <cstring>
# include <algorithm>
# define NR 20005
using namespace std;
vector <int> v[NR];
int i,j,n,m,x,y,VV,cuplate,nrsol;
int ap[NR],M1[NR],M2[NR];
int match (int k)
{
    int i;
    if (ap[k]==VV) return 0;
    ap[k]=VV;
    for (i=0; i<v[k].size(); ++i)
        if (! M2[v[k][i]])
        {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    for (i=0; i<v[k].size(); ++i)
        if (match(M2[v[k][i]]))
        {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    return 0;
}
void DFS (int k)
{
    ap[k]=1;
    if (M1[k]!=0) DFS (M1[k]);
}
int main ()
{
    freopen ("site.in", "r", stdin);
    freopen ("site.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
    }

    cuplate=1;
    while (cuplate)
    {
        cuplate=0; ++VV;
        for (i=1; i<=n; ++i)
            if (! M1[i]) cuplate+=match(i);
    }
    memset (ap, 0, sizeof(ap));
    for (i=1; i<=n; ++i)
        if (M1[i]) ++nrsol;
    printf ("%d\n", n-nrsol);
    return 0;
}
