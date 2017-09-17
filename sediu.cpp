# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
vector <int> v[20000];
int i,j,n,m,x,y,var,minn,VV;
int ap[20000],sol[20000],fii[20000],copil[20000];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (! ap[v[k][i]])
        {
            DFS (v[k][i]);
            copil[k]=max(copil[k],fii[v[k][i]]);
            fii[k]+=fii[v[k][i]];
        }
    }
    ++fii[k];
}
int main ()
{
    freopen ("sediu.in", "r", stdin);
    freopen ("sediu.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1); minn=20000;
    for (i=1; i<=n; ++i)
    {
        var=max(copil[i],n-fii[i]);
        if (var<minn)
        {
            minn=var;
            VV=0; sol[++VV]=i;
        }
        else if (var==minn) sol[++VV]=i;
    }
    printf ("%d %d\n", minn, VV);
    for (i=1; i<=VV; ++i)
        printf ("%d ", sol[i]);
    return 0;
}
