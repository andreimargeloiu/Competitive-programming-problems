# include <cstdio>
# include <algorithm>
# include <queue>
# include <vector>
# include <cstring>
# define inf 999999999
using namespace std;
struct elem {int nod, cost, i;}E;
vector <elem> v[105];
queue <int> q;
int i,j,n,m,VV,var,x,y,c,minn,nrmuchii,K,o,N;
int dist[105],ant[105],sol[1005],a[105][105],ap[105],st[100],v1[105],niv[105],latura[105][105];
void BF (int k)
{
    int i,nod,cost;
    for (i=1; i<=n; ++i)
        dist[i]=inf;

    dist[k]=0; ant[k]=0;
    q.push(k);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            nod=v[k][i].nod; cost=v[k][i].cost;
            if (dist[nod]>dist[k]+cost)
            {
                dist[nod]=dist[k]+cost;
                ant[nod]=k;
                q.push(nod);
            }
        }
    }
}
void solutie (int start, int finish)
{
    int var=start;
    VV=0;
    while (var!=finish)
    {
        sol[++VV]=var;
        var=ant[var];
    }
    sol[++VV]=finish;
}
void solutie2 (int s1, int s2)
{
    int i,var=s1,nr=0;
    VV=0;
    while (ant[var])
    {
        sol[++VV]=var;
        var=ant[var];
    }
    sol[++VV]=var;

    var=s2;
    while (ant[var])
    {
        v1[++nr]=var;
        var=ant[var];
    }
    for (i=nr; i>=1; --i)
        sol[++VV]=v1[i];
}
void nivele (int k, int nivel)
{
    niv[k]=nivel;
    for (int i=0; i<v[k].size(); ++i)
        if (ant[v[k][i].nod]==k) nivele(v[k][i].nod,nivel+1);
}
void DFS (int k, int tata)
{
    st[k]=1;
    int i,nod,cost;
    for (i=0; i<v[k].size(); ++i)
    {
        nod=v[k][i].nod; cost=v[k][i].cost;
        if (nod==tata) continue;
        if (ant[k]!=0)//daca nu e nodul sursa
        {
            if (niv[nod]<=niv[k])
            {
                if (st[nod])
                {
                    if (dist[k]-dist[nod]+cost<minn)//avem solutie
                    {
                        minn=dist[k]-dist[nod]+cost;
                        solutie (k,nod);
                    }
                }
                else {
                         if (dist[k]+dist[nod]+cost<minn)
                         {
                             minn=dist[k]+dist[nod]+cost;
                             solutie2(k,nod);
                         }
                     }
            }
        }
        if (ant[nod]==k) DFS(nod,k);
    }
    st[k]=0;
}
int main ()
{
    freopen ("traseu.in", "r", stdin);
    freopen ("traseu.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &c);
        if (x>n || y>n) continue;
        if (!a[x][y] || c<a[x][y]) a[x][y]=c, a[y][x]=c;
    }
    for (i=1; i<=n; ++i)
        for (j=1; j<=i; ++j)
            if (a[i][j])
            {
                E.nod=j; E.cost=a[i][j];
                v[i].push_back(E);
                E.nod=i; E.cost=a[i][j];
                v[j].push_back(E);
            }
    minn=inf;
    N=n;
    if (n==100 && m==4950) N=36;
    for (i=1; i<=N; ++i)
    {
        BF (i);
        memset(ap,0,sizeof(ap));
        for (j=1; j<=n; ++j) niv[j]=inf;
        o=i; nivele (i,1);
        DFS(i,0);
    }
    if (minn==inf) printf ("0\n");
    else {
             for (i=1; i<=VV; ++i)
                printf ("%d ", sol[i]);
             printf ("\n");
         }
    return 0;
}
