# include <algorithm>
# include <cstdio>
# include <vector>
# define mp make_pair
# define f first
# define s second
# define NR 2005
using namespace std;
vector <pair <int, int> > v[NR];
int i,j,n,m,x,y,cost;
int a[NR][5], ap[NR]; //a[i][0] - suma maxima astfel incat i sa ramana liber
int maxx (int k, int i)
{
    return max(a[v[k][i].f][0], a[v[k][i].f][1]);
}
void DFS (int k, int tata)
{
    int S=0, Sprim, urm, I, J;
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i].f]) DFS (v[k][i].f, k);

    //a[k][0]
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i].f != tata) S+=maxx(k, i);
    Sprim=S;
    for (int i=0; i<v[k].size(); ++i) {
        urm=v[k][i].f; if (urm==tata) continue;
        if (a[k][0] < S-maxx(k, i)+a[urm][0]+v[k][i].s) {
            a[k][0]=S-maxx(k, i)+a[urm][0]+v[k][i].s;
            I=urm;
        }
    }
    //a[k][1]
    for (int i=0; i<v[k].size(); ++i) {
        urm=v[k][i].f; if (urm==tata) continue;
        if (urm==I) continue;
        if (a[k][1] < a[k][0]-maxx(k, i)+a[urm][0]+v[k][i].s) {
            a[k][1]=a[k][0]-maxx(k, i)+a[urm][0]+v[k][i].s;
        }
    }
    //a[k][0]
    a[k][0]=max(a[k][0], Sprim);
}
int main ()
{
    freopen ("tgv.in", "r", stdin);
    freopen ("tgv.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<n; ++i) {
        scanf ("%d%d%d", &x, &y, &cost);
        v[x].push_back(mp (y, cost));
        v[y].push_back(mp (x, cost));
    }

    DFS (1, 0);

    printf ("%d\n", max(a[1][0], a[1][1]));

    return 0;
}
