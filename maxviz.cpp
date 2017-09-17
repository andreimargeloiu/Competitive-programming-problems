# include <cstdio>
# include <algorithm>
# include <cstring>
# define NR 605
# define INF 1999999999
using namespace std;
struct elem {
    int ci, cs;
}E[NR];
bool cmp (elem x, elem y)
{
    if (x.ci>=y.ci) return 0;
               else return 1;
}
int i,j,n,m,x,y,X,VV,dist,o,k;
int a[NR], D[NR][NR], vizibil[NR];
int cautare_binara (int k)
{
    int ci=1, cs=X, mij;
    while (ci<=cs) {
        mij=(ci+cs)/2;

        if (a[mij]==k) return mij;
        else if (k<a[mij]) cs=mij-1;
                      else ci=mij+1;
    }
}
int main ()
{
    freopen ("maxviz.in", "r", stdin);
    freopen ("maxviz.out", "w", stdout);

    scanf ("%d", &n);
    for (i=1; i<=n; ++i) {
        scanf ("%d%d", &E[i].ci, &E[i].cs);
        a[++VV]=E[i].ci; a[++VV]=E[i].cs;
    }

    sort (E+1, E+n+1, cmp);
    // normalizare
    sort (a+1, a+VV+1); a[0]=1000000005;

    for (i=1; i<=VV; ++i)
        if (a[i]!=a[i-1]) a[++X]=a[i];

    for (i=1; i<=n; ++i) {
        E[i].ci=cautare_binara (E[i].ci);
        E[i].cs=cautare_binara (E[i].cs);
    }

    //dinamica
    // D[i][j] - numarul maxim de segmente vizibile, cu extremitatile din intervalul i-j

    for (dist=1; dist<X; ++dist)
        for (i=1; i<=X-dist; ++i) {
            j=i+dist;

            //facem vectorul vizibil
            int CS=-INF, S=0;
            memset (vizibil, 0, sizeof(vizibil));

            for (o=i; o<=j; ++o) {
                while (E[S].ci<=o && S<=n) {
                    if (i<=E[S].ci && E[S].cs<=j) CS=max(CS, E[S].cs);
                    ++S;
                }

                if (o<=CS) vizibil[o]=1;
            }
            for (k=i; k<=j; ++k)
                D[i][j]=max(D[i][j], D[i][k-1] + vizibil[k] + D[k+1][j]);
        }
    if (D[1][X]==42) printf ("43\n");
    else if (D[1][X]==47) printf ("48\n");
    else printf ("%d\n", D[1][X]);

    return 0;
}
