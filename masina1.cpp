# include <cstdio>
# include <vector>
# include <algorithm>
# include <queue>
# define NR 205
# define inf 9999999
using namespace std;
struct elem
{
    int y, cost;
}E;
vector <elem> v[NR];
queue <int> q;
struct elem2
{
    int i, t;
}E2;
queue <elem2> q2;
int i,j,n,m,x,y,S,timp,X,Y,I,T,VV,urm,cost;
int distX[NR], distY[NR], a[NR][NR], sol[NR];
void BFS (int k, int dist[])
{
    int i,urm,cost;
    for (i=1; i<=n; ++i)
        dist[i]=inf;

    dist[k]=0; q.push(k);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i].y; cost=v[k][i].cost;
            if (dist[k]+cost<dist[urm])
            {
                dist[urm]=dist[k]+cost;
                q.push(urm);
            }
        }
    }
}
void solve (int k)
{
    int i,urm,tact,cost;
    E2.i=k; E2.t=0; a[S][0]=1;
    q2.push(E2);
    while (! q2.empty())
    {
        E2=q2.front(); q2.pop();
        k=E2.i; tact=E2.t;
        if (tact>T) I=k, T=tact;

        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i].y; cost=v[k][i].cost;
            if (! a[urm][tact+cost] && tact+cost+max(distX[urm], distY[urm])<=timp)
            {
                a[urm][tact+cost]=1;
                E2.i=urm; E2.t=tact+cost;
                q2.push(E2);
            }
        }
    }
}
int main ()
{
    freopen ("masina1.in", "r", stdin);
    freopen ("masina1.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    scanf ("%d%d", &S, &timp);
    scanf ("%d%d", &X, &Y);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &E.cost);
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    BFS (X, distX);
    BFS (Y, distY);

    solve (S);
    //afisam
    printf ("%d\n", T);
    while (1)
    {
        sol[++VV]=I;
        if (T==0) break;
        for (i=0; i<v[I].size(); ++i)
        {
            urm=v[I][i].y; cost=v[I][i].cost;
            if (a[urm][T-cost])
            {
                I=urm; T=T-cost;
                break;
            }
        }
    }

    for (i=VV; i>=1; --i)
        printf ("%d ", sol[i]);

    return 0;
}
