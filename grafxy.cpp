# include <cstdio>
# include <queue>
using namespace std;
vector <int> v[100005];
queue <int> q;
int i,j,n,m,X,Y,x,y;
int var[100005],ap[100005],a[100005];
void BFS ()
{
    int i,x;
    while (! q.empty())
    {
        x=q.front(); q.pop();
        for (i=0; i<v[x].size(); ++i)
        {
            if (ap[v[x][i]]>ap[x]+1)
            {
                ap[v[x][i]]=ap[x]+1;
                q.push(v[x][i]);
            }
        }
    }
}
int main ()
{
    freopen ("grafxy.in", "r", stdin);
    freopen ("grafxy.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; ++i)
        ap[i]=999999;
    for (i=1; i<=m; ++i)
    {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf ("%d", &X);
    for (i=1; i<=X; ++i)
        scanf ("%d", &a[i]);
    scanf ("%d", &Y);
    for (i=1; i<=Y; ++i)
    {
        scanf ("%d", &var[i]);
        ap[var[i]]=0;
        q.push(var[i]);
    }
    BFS ();
    for (i=1; i<=X; ++i)
        printf ("%d\n", ap[a[i]]);

    return 0;
}
