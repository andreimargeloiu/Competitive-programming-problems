# include <cstdio>
# include <vector>
# include <algorithm>
# include <cstring>
# define NR 100005
using namespace std;
vector <pair <int, int> >v[NR];
vector <pair <int, pair<int, int> > >d[NR];
struct elem
{
    int x, y, cost;
}a[NR];
struct solutie
{
    int x, y;
}sol[NR];
bool cmp2 (solutie x, solutie y)
{
    if (x.x>y.x) return 0;
    else if (x.x==y.x && x.y>=y.y) return 0;
    else return 1;
}
bool cmp (elem x, elem y)
{
    if (x.cost>=y.cost) return 0;
                   else return 1;
}

int i,j,n,m,x,y,VV,nrsol;
int val[NR], R[NR], H[NR], ap[NR], niv[NR], minn[NR], stiva[NR];

void normalizare ()
{
    int i;
    sort (val+1, val+m+1);
    for (i=1; i<=m; ++i)
        if (val[i]!=val[i-1]) val[++VV]=val[i];

    for (i=1; i<=m; ++i)
        a[i].cost=lower_bound(val+1, val+VV+1, a[i].cost) - val;

    for (i=1; i<=m; ++i)
        v[a[i].cost].push_back(make_pair(a[i].x, a[i].y));
}
int radacina (int k)
{
    while (k!=R[k])
        k=R[k];
    return k;
}
void DFS (int k, int nivel, int tata)
{
    int ok=0;
    ap[k]=1; niv[k]=nivel; minn[k]=nivel;
    for (int i=0; i<d[k].size(); ++i)
    {
        if (d[k][i].first!=tata || (d[k][i].first==tata && ok))
        {
            int urm=d[k][i].first;
            if (! ap[urm])
            {
                DFS (urm, nivel+1, k);
                if (minn[urm]>nivel)
                {
                    sol[++nrsol].x=d[k][i].second.first;
                    sol[nrsol].y=d[k][i].second.second;
                }
                minn[k]=min(minn[k], minn[urm]);
            }
            else minn[k]=min(minn[k], niv[urm]);
        }
        if (d[k][i].first==tata) ok=1;
    }
}
void curata (int k)
{
    ap[k]=0; niv[k]=0; minn[k]=0;
    for (int i=0; i<d[k].size(); ++i)
        if (ap[d[k][i].first]) curata (d[k][i].first);
    d[k].clear();
}
void Kruskal ()
{
    int i,j,K,Rx,Ry;
    for (i=1; i<=n; ++i)
        R[i]=i; H[i]=1;

    for (i=1; i<=VV; ++i) //fiecare cost de muchie
    {
        K=0;
        for (j=0; j<v[i].size(); ++j)
        {
            Rx=radacina(v[i][j].first);
            Ry=radacina(v[i][j].second);
            //facem legaturile in graful imaginar
            if (Rx!=Ry)
            {
                stiva[++K]=Rx;
                d[Rx].push_back(make_pair (Ry, make_pair(v[i][j].first, v[i][j].second)));
                d[Ry].push_back(make_pair (Rx, make_pair(v[i][j].first, v[i][j].second)));
            }
        }
        for (j=1; j<=K; ++j)
            if (! ap[stiva[j]]) DFS (stiva[j], 0, 0);
        for (j=1; j<=K; ++j)
            if (ap[stiva[j]]) curata (stiva[j]);

        for (j=0; j<v[i].size(); ++j) //legam componentele conexe
        {
            Rx=radacina(v[i][j].first);
            Ry=radacina(v[i][j].second);
            if (Rx!=Ry)
            {
                 if (H[Rx]>H[Ry]) H[Rx]+=H[Ry], R[Ry]=Rx;
                             else H[Ry]+=H[Rx], R[Rx]=Ry;
            }
        }

    }
}
int main ()
{
    freopen ("vitale.in", "r", stdin);
    freopen ("vitale.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].cost);
        val[i]=a[i].cost;
    }
    normalizare ();

    Kruskal ();

    printf ("%d\n", nrsol);
    for (i=1; i<=nrsol; ++i)
        if (sol[i].x>sol[i].y) swap(sol[i].x, sol[i].y);

    sort (sol+1, sol+nrsol+1, cmp2);

    for (i=1; i<=nrsol; ++i)
        printf ("%d %d\n", sol[i].x, sol[i].y);

    return 0;
}
