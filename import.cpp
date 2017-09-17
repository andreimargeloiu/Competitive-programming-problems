# include <vector>
# include <algorithm>
# include <cstdio>
# include <queue>
# define NR 300
using namespace std;
vector <pair <int, int> > VV[NR];
vector <int> v[NR];
queue <int> q;
int x,y,T,K,dist[NR],sol[NR],i,j,n,m,urm,cost;
void DFS (int k, int tata) {
    if (k>K && tata==1) sol[k]=dist[k];
	else if (k!=1) sol[k]=dist[k]-dist[tata];

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata) DFS (v[k][i], k);
}
int main ()
{
    freopen ("import.in", "r", stdin);
    freopen ("import.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &K);
    for (i=1; i<n; ++i) { scanf ("%d%d", &x, &y); v[x].push_back(y); v[y].push_back(x); }

    for (i=1; i<=m; ++i) {
        scanf ("%d%d%d%d", &x, &y, &cost, &T);
        if (T==0) VV[y].push_back(make_pair(x, -cost));
             else VV[x].push_back(make_pair(y, cost-1));
    }

    // facem bellman ford
    for (i=1; i<=n; ++i) q.push(i);
    while (! q.empty()) {
        int k=q.front(); q.pop();
        for (int i=0; i<VV[k].size(); ++i) {
             urm=VV[k][i].first;
            cost=VV[k][i].second;

            if (dist[urm] > dist[k] + cost) {
                dist[urm] = dist[k] + cost;
                q.push(urm);
            }
        }
    }
    for (i=K+1; i<=n; ++i) dist[i]=-dist[i];
    sol[1]=dist[1]; DFS (1, 0);

    for (i=1; i<=n; ++i)
        printf ("%d ", sol[i]);

    return 0;
}
