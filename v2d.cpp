# include <cstdio>
# include <algorithm>
# define NR 505
using namespace std;
int i,j,n,m,x,y,T,Q,S,o;
int P[NR][NR], Pmax[NR][NR], amax[NR][NR];
void init ()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            amax[i][j]=0;
}
void parcurgere (int iStart, int iStop, int I, int jStart, int jStop, int J)
{
    init ();
    for (int i=iStart; i!=iStop; i+=I)
        for (int j=jStart; j!=jStop; j+=J) {

            amax[i][j]=max(amax[i-I][j]-1, amax[i][j-J]-1);
            amax[i][j]=max(amax[i][j], max(P[i-I][j]-1, P[i][j-J]-1));

            Pmax[i][j]=max(Pmax[i][j], amax[i][j]);
        }
}
int main ()
{
    freopen ("v2d.in", "r", stdin);
    freopen ("v2d.out", "w", stdout);
    scanf ("%d%d%d", &n, &T, &Q);

    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            scanf ("%d", &P[i][j]);

    for (o=1; o<=T; ++o) { //fiecare etapa

        parcurgere (1, n+1, 1, 1, n+1, 1);  //coltul 1
        parcurgere (1, n+1, 1, n, 0, -1);  //coltul 2
        parcurgere (n, 0, -1, 1, n+1, 1);  //coltul 3
        parcurgere (n, 0, -1, n, 0, -1);  //coltul 4

        //PA = P(z, i, j) - dist(i, j, p, q). dist(i, j, p, q)
        //calculezi P pentru ziua viitoare
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j) {
                P[i][j]=o + 1 + (P[i][j] +o*Pmax[i][j])%Q;
                Pmax[i][j]=0;
            }

        //P(z + 1, i, j) = z + 1 + ((P(z, i, j) + z * Pmax(z, i, j)) modulo Q).
    }

    S=0;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            S=(S+P[i][j])%Q;
    printf ("%d\n", S);

    return 0;
}
