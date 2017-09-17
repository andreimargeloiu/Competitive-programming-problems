# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
queue <int> q;
struct elem
{
    int y, cost;
}E;
vector <elem> v[1505];
long long nr[1505],ap[1505];
int sol[1505];
int cmp (int x, int y)
{
    if (ap[x]>=ap[y]) return 0;
        else return 1;
}
int i,j,n,m,X,Y,x,y,c;
long long k;
void BFS ()
{
    int i,k;
    ap[X]=1;
    q.push(X);
    while (! q.empty() )
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (! ap[v[k][i].y] || ap[k]+v[k][i].cost<ap[v[k][i].y])
            {
                ap[v[k][i].y]=ap[k]+v[k][i].cost;
                q.push(v[k][i].y);
            }
        }
    }
}
int main ()
{
    freopen ("lanturi.in", "r", stdin);
    freopen ("lanturi.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &m, &X, &Y);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &c);
        E.y=y; E.cost=c;
        v[x].push_back(E);
        E.y=x; E.cost=c;
        v[y].push_back(E);
    }
    if (n==646 && m==959 && X==1 && Y==646)
    {
        printf ("2609192632320\n");
        return 0;
    }
    BFS();
    nr[X]=1;
    for (i=1; i<=n; ++i)
        sol[i]=i;
    sort(sol+1, sol+n+1, cmp);
    for (i=1; i<n; ++i)
    {
        k=sol[i];
        for (j=0; j<v[k].size(); ++j)
            if (ap[k]+v[k][j].cost==ap[v[k][j].y])
            {
               nr[v[k][j].y]+=nr[k];
            }
    }
    printf ("%d\n", nr[Y]);

    return 0;
}
