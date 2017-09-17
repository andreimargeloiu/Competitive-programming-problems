# include <cstdio>
# include <vector>
# include <cstring>
# include <algorithm>
# include <queue>
# define inf 999999999
# define NR 100005
using namespace std;
vector <int> v[NR];
queue <int> q;
int i,j,n,m,x,y,sol,ci,cs,mij,I,minn,maxx;
int ap[NR], d[NR], var[NR];
bool verif (int H)
{
    int i,ELIM=0,k;

    for (i=1; i<=n; ++i)
    {
        var[i]=d[i], ap[i]=0;
        if (var[i]<=H)
        {
            ap[i]=1; ++ELIM;
            q.push(i);
        }
    }

    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
            if (! ap[v[k][i]])
            {
                --var[v[k][i]];
                if (var[v[k][i]]<=H)
                {
                    ++ELIM;
                    ap[v[k][i]]=1;
                    q.push(v[k][i]);
                }
            }
    }

    if (ELIM==n) return 1;
            else return 0;
}
int main ()
{
    freopen ("dag.in", "r", stdin);
    freopen ("dag.out", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);

        ++d[x]; ++d[y];
    }
    minn=inf;
    for (i=1; i<=n; ++i)
    {
        if (d[i]<minn) minn=d[i], I=i;
        maxx = max(maxx, d[i]);
    }
    ci=minn; cs=maxx;

    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (verif(mij)) sol=mij, cs=mij-1;
                   else ci=mij+1;
    }

    printf ("%d\n", sol);

    return 0;
}
