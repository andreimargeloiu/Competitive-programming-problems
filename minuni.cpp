# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("minuni.in");
ofstream g("minuni.out");
struct elem {
    int ci, cs, Sci, Scs;
}a[NR], E, ZERO, ARB[4*NR];

struct elem2 {
    int x, tip, i;
}var[2*NR];
bool cmp (elem2 x, elem2 y) {
    return x.x < y.x;
}

int i,j,n,m,poz,x,y,Mci,Mcs,K,M,A,B,tip;

void update (int nod, int ci, int cs, int NOD, int CI, int CS) {
    if (ci==NOD && NOD==cs) ARB[nod].ci=CI, ARB[nod].cs=CS;
    else {
        int mij=(ci+cs)/2;
        if (NOD<=mij) update (2*nod, ci, mij, NOD, CI, CS);
                else update (2*nod+1, mij+1, cs, NOD, CI, CS);

        if (ARB[2*nod].ci > ARB[2*nod+1].ci) ARB[nod]=ARB[2*nod];
                                        else ARB[nod]=ARB[2*nod+1];
    }
}
void query (int nod, int ci, int cs, int CI, int CS) {
    if (1<=ci && cs<=CS) {
        if (ARB[nod].ci > Mci) Mci=ARB[nod].ci, Mcs=ARB[nod].cs;
    }
    else {
        int mij=(ci+cs)/2;
        if (CI <= mij) query (2*nod, ci, mij, CI, CS);
        if (mij < CS) query (2*nod+1, mij+1, cs, CI, CS);
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>a[i].ci>>a[i].cs;

        ++M; var[M].x=a[i].ci; var[M].tip=0; var[M].i=i;
        ++M; var[M].x=a[i].cs; var[M].tip=1; var[M].i=i;
    }
    sort (var+1, var+M+1, cmp);

    for (i=1; i<=M; ++i) {
        tip=var[i].tip; x=var[i].x; K=var[i].i;

        if (tip==1) { //trebuie stearsa
            update (1, 1, m, K, 0, 0);
        }
        else {
            Mci=0; Mcs=0;
            query (1, 1, m, 1, K);
            a[K].Sci=Mci; a[K].Scs=Mcs;

            update (1, 1, m, K, a[K].ci, a[K].cs);
        }
    }

    for (i=1; i<=m; ++i) {
        A=a[i].Sci; B=a[i].Scs;
        x=a[i].ci; y=a[i].cs;

        if (B < a[i].ci) {// nu este inclus in niciun alt interval
            g<<1LL*x*(n-y+1)<<"\n";
        }
        else {
            g<<1LL*x*(B-y) + 1LL*(x-A)*(n-y+1) - 1LL*(B-y)*(x-A)<<"\n";
        }
    }

    return 0;
}
