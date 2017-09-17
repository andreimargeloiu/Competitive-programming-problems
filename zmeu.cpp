# include <cstdio>
# include <algorithm>
# include <vector>
# include <queue>
# define inf 1000000000
using namespace std;
struct elem
{
    int y,val;
}E;
vector <elem> v[1005];
queue <int> q;
int i,j,n,m,p,F,minim,nr,x,y,suma,ok;
int P[10],dist[1005][10],iesire[1005],fata[1005],minn[10];
void lee (int var)
{
    int i,k;
    for (i=1; i<=n; ++i)
        dist[i][var]=inf;
    dist[fata[var]][var]=0;
    q.push(fata[var]);
    while (! q.empty())
    {
        k=q.front (); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (dist[v[k][i].y][var]>dist[k][var]+v[k][i].val)
            {
                dist[v[k][i].y][var]=dist[k][var]+v[k][i].val;
                q.push(v[k][i].y);
            }
        }
    }
    minn[var]=inf;
    for (i=1; i<=p; ++i)
        minn[var]=min(minn[var], dist[iesire[i]][var]);
}
int main ()
{
    freopen ("zmeu.in", "r", stdin);
    freopen ("zmeu.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &p);
    scanf ("%d", &F);
    for (i=1; i<=5; ++i)
        scanf ("%d", &fata[i]);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &nr);
        E.y=y; E.val=nr;
        v[x].push_back(E);
        E.y=x; E.val=nr;
        v[y].push_back(E);
    }
    for (i=1; i<=p; ++i)
        scanf ("%d", &iesire[i]);
    for (i=1; i<=5; ++i)
        lee(i);
    P[1]=1; P[2]=2; P[3]=3; P[4]=4; P[5]=5;
    minim=inf;
    for (i=1; i<=120; ++i)
    {
        suma=dist[F][P[1]]; ok=0;
        for (j=1; j<=4; ++j)
        {
            suma+=dist[fata[P[j+1]]][P[j]];
            if (! dist[fata[P[j+1]]][P[j]]) ok=1;
        }
        if (ok)
        {
            next_permutation(P+1, P+5+1);
            continue;
        }
        suma+=minn[P[5]];
        if (suma<minim)
        {
            minim=suma;
        }
        next_permutation(P+1, P+5+1);
    }
    printf ("%d\n", minim);
    return 0;
}
