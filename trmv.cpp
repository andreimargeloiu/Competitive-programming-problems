# include <cstdio>
# include <vector>
# include <queue>
# define inf 999999999
# define mil 1000005
using namespace std;
struct elem
{
    int y, cost;
}E;
vector <elem> v[mil];
queue <int> q;
int i,j,l,n,m,k,S,ci,cs,t,x;
int ap[mil],stiva[mil];
void BF ()
{
    int i,k;
    for (i=1; i<=n; ++i)
        ap[i]=inf;
    ap[S]=0;
    q.push(S);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        stiva[k]=0;
        for (i=0; i<v[k].size(); ++i)
        {
            if (ap[k]+v[k][i].cost<ap[v[k][i].y])
            {
                ap[v[k][i].y]=ap[k]+v[k][i].cost;
                if (! stiva[v[k][i].y]) q.push(v[k][i].y), stiva[v[k][i].y]=1;

            }
        }
    }
}
int main ()
{
    freopen ("trmv.in", "r", stdin);
    freopen ("trmv.out", "w", stdout);
   int i,j;
   scanf ("%d%d%d%d", &n, &m, &S, &k);
   for (i=1; i<=m; ++i)
   {
       scanf ("%d%d", &l, &ci);
       for (j=2; j<=l; ++j)
       {
           scanf ("%d%d", &t, &cs);
           E.y=cs; E.cost=t;
           v[ci].push_back(E);
           E.y=ci; E.cost=t;
           v[cs].push_back(E);
           ci=cs;
       }
   }
   BF();
   for (i=1; i<=k; ++i)
   {
       scanf ("%d", &x);
       if (ap[x]==inf) printf ("-1 ");
          else printf ("%d ", ap[x]);
   }
   printf ("\n");
   return 0;
}
