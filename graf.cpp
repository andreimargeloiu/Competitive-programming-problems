# include <cstdio>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;
vector <int> v[7505],nr[7505];
queue <int> q;
int i,j,n,m,X,Y,x,y,k,VV;
int dist[7505],sol[7505],ap[7505];
void BF ()
{
    q.push(X); dist[X]=1;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
            if (dist[v[k][i]]==0)
            {
                dist[v[k][i]]=dist[k]+1;
                q.push(v[k][i]);
            }
    }
}
void NUMARA ()
{
    q.push(Y);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (dist[v[k][i]]==dist[k]-1 && !ap[v[k][i]])
            {
                ap[v[k][i]]=1;
                nr[dist[v[k][i]]].push_back(v[k][i]);
                q.push(v[k][i]);
            }
        }
    }
}
int main ()
{
    freopen ("graf.in", "r", stdin);
    freopen ("graf.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &m, &X, &Y);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BF ();
    NUMARA ();

    nr[dist[Y]].push_back(Y);
    for (i=1; i<=n; ++i)
        if (nr[i].size()==1) sol[++VV]=nr[i].front();
    sort (sol+1, sol+VV+1);
    printf ("%d\n", VV);
    for (i=1; i<=VV; ++i)
        printf ("%d ", sol[i]);
    printf ("\n");

    return 0;
}
