# include <cstdio>
# include <vector>
# include <algorithm>
# include <queue>
# define inf 999999999
using namespace std;
struct elem{int nod, cost;}E;
vector <elem> v[2005];
queue <int> q;
int i,j,n,m,x,y,k,c,K,minn,o,nr;
int dist[20][20],d[20][1<<15],loc[20],D[2005];
void BF (int nr){int x,i; for (i=1; i<=n; ++i)D[i]=inf;D[loc[nr]]=0;q.push(loc[nr]);while (! q.empty()){x=q.front (); q.pop();for (i=0; i<v[x].size(); ++i)if (D[v[x][i].nod]>D[x]+v[x][i].cost)
    {D[v[x][i].nod]=D[x]+v[x][i].cost;q.push(v[x][i].nod);
            }
    }for (i=0; i<=k+1; ++i)dist[nr][i]=D[loc[i]];
}
int main ()
{
    freopen ("ubuntzei.in", "r", stdin);
    freopen ("ubuntzei.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &k);loc[0]=1;for (i=1; i<=k; ++i)scanf ("%d", &loc[i]);loc[k+1]=n;for (i=1; i<=m; ++i){scanf ("%d%d%d", &x, &y, &c);E.nod=y; E.cost=c;v[x].push_back(E);E.nod=x; E.cost=c;
        v[y].push_back(E);}for (i=0; i<=k+1; ++i)BF (i);if (k==0){printf ("%d\n", dist[0][k+1]);}else{K=1<<(k); minn=inf;for (i=0; i<=k+1; ++i)for (j=0; j<K; ++j)d[i][j]=inf;d[0][0]=0;for (i=0; i<K; ++i)for (j=0; j<=k; ++j)if (d[j][i]!=inf)for (o=1; o<=k; ++o)if ((i & (1<<(o-1)))==0)d[o][(1<<(o-1))|i]=min(d[o][(1<<(o-1))|i], d[j][i]+dist[j][o]);for (i=1; i<=k; ++i)minn=min(minn, d[i][K-1]+dist[i][k+1]);printf ("%d\n", minn);}return 0;
}
