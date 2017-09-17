# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 205
# define inf 999999999
using namespace std;
vector <int> v[5][NR];
int i,j,n,m,x,y;
int a[NR][2*NR], frate[NR];
void init ()
{
    for (int i=1; i<=n; ++i)
    {
        a[i][0]=0;
        for (int j=1; j<=2*n; ++j)
            a[i][j]=inf;
    }
}
bool cmp (int x, int y)
{
    for (int i=1; i<=max (a[x][0], a[y][0]); ++i)
        if (a[x][i] > a[y][i]) return 0;
        else if (a[x][i] < a[y][i]) return 1;

    return 0;
}
void DFS (int k, int arb)
{
    for (int i=0; i<v[arb][k].size(); ++i)
        DFS (v[arb][k][i], arb);

    sort (v[arb][k].begin(), v[arb][k].end(), cmp);

    a[k][++a[k][0]]=1;
    for (int i=0; i<v[arb][k].size(); ++i) {
        int urm=v[arb][k][i];
        for (int j=1; j<=a[urm][0]; ++j)
            a[k][++a[k][0]]=a[urm][j];
    }
    a[k][++a[k][0]]=2;
}
void unire (int k1, int k2)
{
    frate[k1]=k2;
    for (int i=0; i<v[1][k1].size(); ++i)
        unire (v[1][k1][i], v[2][k2][i]);
}
int main ()
{
    freopen ("izo.in", "r", stdin);
    freopen ("izo.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i) {
        scanf ("%d", &x);
        v[1][x].push_back(i);
    }
    for (i=1; i<=n; ++i) {
        scanf ("%d", &x);
        v[2][x].push_back(i);
    }
    init ();
    DFS (1, 1);
    init ();
    DFS (1, 2);

    //facem DFS sa-i unim
    unire (1, 1);
    for (i=1; i<=n; ++i)
        printf ("%d ", frate[i]);
    printf ("\n");


    return 0;
}
