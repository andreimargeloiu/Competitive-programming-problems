# include <cstdio>
# include <algorithm>
# define NR 100005
using namespace std;
struct elem {
    int nod, H;
}ARB[4*NR];

int i,j,n,m,x,y,SOL,h,poz,tip,plop;
int H[NR];

void actualizare (int nod, int ci, int cs, int NOD)
{
    if (ci==cs) ARB[nod].nod=NOD, ARB[nod].H=H[NOD];
    else {
             int mij=(ci+cs)/2;
             if (NOD<=mij) actualizare (2*nod, ci, mij, NOD);
             if (mij<NOD)  actualizare (2*nod+1, mij+1, cs, NOD);

             if (ARB[2*nod].H > ARB[2*nod+1].H) ARB[nod]=ARB[2*nod];
                                           else ARB[nod]=ARB[2*nod+1];
         }
}
void query (int nod, int ci, int cs, int CI)
{
    if (ARB[nod].H < h) return;
    if (poz < ci) return;

    if (CI<=ci && h<=ARB[nod].H && ARB[nod].nod<poz) poz=ARB[nod].nod;

    if (ci!=cs) {
        int mij=(ci+cs)/2;
        if (CI<=mij) query (2*nod, ci, mij, CI);
        if (CI<=cs) query (2*nod+1, mij+1, cs, CI);
    }
}
int main ()
{
    freopen ("plopi.in", "r", stdin);
    freopen ("plopi.out", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; ++i) {
        scanf ("%d", &H[i]);
        actualizare (1, 1, n, i);
    }

    for (i=1; i<=m; ++i) {
        scanf ("%d%d%d", &tip, &plop, &h);
        if (tip==1) { // schimb inaltimea
            H[plop]=h;
            actualizare (1, 1, n, plop);
        }
        else { // query
                 poz=n+1; //pozitia solutiei

                 query (1, 1, n, plop);

                 if (poz==n+1) printf ("-1\n");
                          else printf ("%d\n", poz);
             }
    }


    return 0;
}
