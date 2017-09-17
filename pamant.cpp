# include <cstdio>
# include <vector>
# include <algorithm>
# define inf 999999999
using namespace std;
vector <int> v[100005];
int i,j,n,m,x,y,VV,C,fii,o;
int critic[100005],comp[100005],ap[100005],nivel[100005],minn[100005];
void DFS (int k, int tata, int niv)
{
    int ok=0;
    ap[k]=1; nivel[k]=niv; minn[k]=niv;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (v[k][i]!=tata)
        {
            if (! ap[v[k][i]])
            {
                if (k==o) ++fii;
                DFS (v[k][i], k, niv+1);
                minn[k]=min(minn[k], minn[v[k][i]]);

                if (niv!=1 && minn[v[k][i]]>=niv) ok=1;
            }
            else minn[k]=min(minn[k], nivel[v[k][i]]);
        }
    }
    if (ok) critic[++C]=k;
}
int main ()
{
    freopen ("pamant.in", "r", stdin);
    freopen ("pamant.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (o=1; o<=n; ++o)
    {
        if (! ap[o])
        {
            fii=0;
            DFS (o,0,1);
            if (fii>1) critic[++C]=o;
            comp[++VV]=o;
        }
    }
    printf ("%d\n", VV);
    for (i=1; i<=VV; ++i)
        printf ("%d ", comp[i]);

    printf ("\n%d\n", C);
    sort (critic+1, critic+C+1);
    for (i=1; i<=C; ++i)
        printf ("%d ", critic[i]);
    return 0;
}
