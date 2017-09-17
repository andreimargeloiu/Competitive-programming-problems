# include <cstdio>
# include <algorithm>
# include <vector>
# define mp make_pair
# define f first
# define s second
# define NR 100005
# define INF 999999999
using namespace std;
vector <pair <int, int> > v[NR];
int i,j,n,m,x,y,VV,VV1,maxx,maxim,Q,LG;
int viz[NR], ap[5*NR], var[NR], lg[NR], a[NR][20], sol[NR];
void DFS (int k) {
    viz[k]=1; var[++VV]=k;

    for (int i=0; i<v[k].size(); ++i) {
        int urm=v[k][i].f, M=v[k][i].s;

        if (! ap[M]) {//daca nu am vizitat muchia asta
            ap[M]=1;
            x=k; y=urm;
            if (x>y) swap(x, y);
            LG=lg[y-x+1];

            Q=min(a[x][LG], a[y-(1<<LG)+1][LG]);

            maxx=max(maxx, Q);
        }

        if (! viz[urm]) DFS (urm);
    }
}
int main ()
{
    freopen ("wg.in", "r", stdin);
    freopen ("wg.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i][0]);

    //facem logaitmul
    for (i=2; i<=n; ++i)
        lg[i]=lg[i/2] + 1;

    // facem RMQ-ul
    for (j=1; j<=lg[n]; ++j)
        for (i=1; i<=n - (1<<j) + 1; ++i)
            a[i][j]=min(a[i][j-1], a[i+(1<<(j-1))][j-1]);

    scanf ("%d", &m);
    for (i=1; i<=m; ++i) {
        scanf ("%d%d", &x, &y);
        v[x].push_back(mp (y, i));
        v[y].push_back(mp (x, i));
    }
    maxim=0;
    for (i=1; i<=n; ++i) {
        if (! viz[i]) {//daca nu l-am vizitat
            maxx=0; VV=0;
            DFS (i);
            if (maxx>maxim) {
                maxim=maxx;
                VV1=VV;

                for (j=1; j<=VV; ++j) {
                    sol[j]=var[j];
                }
            }
        }
    }
    sort (sol+1, sol+VV1+1);
    printf ("%d\n%d\n", maxim, VV1);
    for (i=1; i<=VV1; ++i)
        printf ("%d\n", sol[i]);


    return 0;
}
