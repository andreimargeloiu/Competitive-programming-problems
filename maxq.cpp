# include <cstdio>
# include <algorithm>
# include <cstring>
# define NR 200005
# define inf 999999999
using namespace std;
struct elem {
    long long fata, spate, suma, total;
}ARB[4*NR], var[NR];

int i,j,n,m,x,y,VV,tip;
long long maxx;
int a[NR];

long long maxim () {
    int i;
    long long maxx=0, ant=0;
    for (i=1; i<=VV; ++i) {
        maxx=max(maxx, var[i].total);

        maxx=max(maxx, max(ant + var[i].fata, var[i].spate));

        ant=max(0LL, max(ant+var[i].suma, var[i].spate));
    }
    return maxx;
}
void make_arb (int nod, int ci, int cs) {
    if (ci==cs) ARB[nod].fata = ARB[nod].spate = ARB[nod].suma = ARB[nod].total = a[ci];
    else {
        int mij=(ci + cs)/2;
        make_arb(2*nod, ci, mij);
        make_arb(2*nod+1, mij+1, cs);

        ARB[nod].suma=ARB[2*nod].suma + ARB[2*nod+1].suma;
        ARB[nod].fata=max(ARB[2*nod].fata, ARB[2*nod].suma + ARB[2*nod+1].fata);
        ARB[nod].spate=max(ARB[2*nod+1].spate, ARB[2*nod+1].suma + ARB[2*nod].spate);

        VV=0; var[++VV]=ARB[2*nod]; var[++VV]=ARB[2*nod+1];
        ARB[nod].total = maxim ();
    }
}
void update (int nod, int ci, int cs, int poz, int val) {
    if (ci==cs) {a[ci]=val; ARB[nod].fata = ARB[nod].spate = ARB[nod].suma = ARB[nod].total = a[ci];}
    else {
        int mij=(ci + cs)/2;
        if (poz<=mij) update(2*nod, ci, mij, poz, val);
                 else update(2*nod+1, mij+1, cs, poz, val);

        ARB[nod].suma=ARB[2*nod].suma + ARB[2*nod+1].suma;
        ARB[nod].fata=max(ARB[2*nod].fata, ARB[2*nod].suma + ARB[2*nod+1].fata);
        ARB[nod].spate=max(ARB[2*nod+1].spate, ARB[2*nod+1].suma + ARB[2*nod].spate);

        VV=0; var[++VV]=ARB[2*nod]; var[++VV]=ARB[2*nod+1];
        ARB[nod].total = maxim ();
    }
}
void query (int nod, int ci, int cs, int CI, int CS) {
    if (CI<=ci && cs<=CS) var[++VV]=ARB[nod];
    else {
        int mij=(ci+cs)/2;
        if (CI<=mij) query (2*nod, ci, mij, CI, CS);
        if (mij<CS) query (2*nod+1, mij+1, cs, CI, CS);
    }
}
int main ()
{
    freopen ("maxq.in", "r", stdin);
    freopen ("maxq.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);

    make_arb (1, 1, n);

    scanf ("%d", &m);
    for (i=1; i<=m; ++i) {
        scanf ("%d%d%d", &tip, &x, &y);
        if (tip==0) {++x; update (1, 1, n, x, y);}
               else {   maxx=0; VV=0; ++x; ++y;
                        query (1, 1, n, x, y);
                        printf ("%lld\n", maxim());
                    }
    }

    return 0;
}
