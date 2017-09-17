# include <cstdio>
# include <vector>
using namespace std;
vector <int> v[10005];
int i,j,n,m,x,y,VV,max1,max2,v1,v2;
int ap[10005],nrelem[10005];
void DFS (int k)
{
    ap[k]=VV; ++nrelem[VV];
    for (int i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i]]==0) DFS(v[k][i]);
    }
}
int main ()
{
    freopen ("turn1.in", "r", stdin);
    freopen ("turn1.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        if (x==y) continue;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
    {
        if (ap[i]==0)
        {
            ++VV;
            DFS(i);
        }
    }
    for (i=1; i<=VV; ++i)
        if (nrelem[i]>max1)
        {
            if (max1>max2) max2=max1,v2=v1;
            max1=nrelem[i]; v1=i;
        }
        else if (nrelem[i]>max2) max2=nrelem[i],v2=i;
    if (max1==n)
    {
        printf ("1 1\n");
        return 0;
    }
    for (i=1; i<=n; ++i)
        if (ap[i]==v1) {
                           printf ("%d ", i);
                           break;
                       }
    for (i=1; i<=n; ++i)
        if (ap[i]==v2) {
                           printf ("%d\n", i);
                           break;
                       }
    return 0;
}
