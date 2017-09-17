# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
struct elem
{
    int y, cost;
}E;
vector <elem> v[NR];
vector <int> B[NR];
int i,j,n,m,x,y,S,O;
long long minn, Intrare, DRUM, I[NR];
int P[NR], C[NR];
void citire ()
{
    int i;
    scanf ("%d%d", &n, &m);
    for (i=1; i<n; ++i)
    {
        scanf ("%d%d%d", &x, &y, &E.cost);
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    for (i=1; i<=n; ++i)
        scanf ("%d", &C[i]);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d", &x);
        P[x]=1;
    }
    S=x;
}
void DFS (int k, int tata)
{
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i].y!=tata)
        {
            DFS (v[k][i].y, k);
            if (P[v[k][i].y])
            {
                P[k]=1;
                DRUM+=(2*v[k][i].cost);
            }
        }
}
int main ()
{
    freopen ("posta2.in", "r", stdin);
    freopen ("posta2.out", "w", stdout);
    citire ();

    DFS (S, 0);

    for (i=1; i<=n; ++i)
    {
        if (P[i])
        {
            for (j=0; j<v[i].size(); ++j)
                if (P[v[i][j].y]) ++I[i];
            --I[i];
            DRUM+=(I[i]*C[i]);
        }
    }

    minn=(1LL<<62);
    for (i=1; i<=n; ++i)
        if (P[i])
        {
            minn=min(minn, Intrare-C[i]*I[i]);
        }

    printf ("%lld\n", minn+DRUM);
    return 0;
}
