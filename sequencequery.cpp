# include <bits/stdc++.h>
# define NR 100005
# define INF 1LL<<60
using namespace std;
ifstream f("sequencequery.in");
ofstream g("sequencequery.out");
struct elem {
    long long st, dr, total, suma;
}ARB[4*NR];
int i,j,n,m,x,y,VV,Q,ci,cs;
int st[NR];
long long a[NR];

long long maxim () {
    long long maxx=-INF, ant=-INF;

    for (int i=1; i<=VV; ++i) {
        int x=st[i];
        maxx=max(maxx, ARB[x].total);

        maxx=max(maxx, max(ant + ARB[x].st, ARB[x].dr));
        ant=max(0LL, max(ant + ARB[x].suma, ARB[x].dr));
    }

    return maxx;
}
void make_arb (int nod, int ci, int cs) {
    if (ci==cs) {
        ARB[nod].st = ARB[nod].suma = ARB[nod].dr = ARB[nod].total = a[ci];
    } else {
        int mij=(ci+cs)/2;
        make_arb (2*nod, ci, mij);
        make_arb (2*nod+1, mij+1, cs);

        ARB[nod].suma = ARB[2*nod].suma + ARB[2*nod+1].suma;
        ARB[nod].st = max(ARB[2*nod].st, ARB[2*nod].suma + ARB[2*nod+1].st);
        ARB[nod].dr = max(ARB[2*nod+1].dr, ARB[2*nod].dr + ARB[2*nod+1].suma);

        VV=0; st[++VV]=2*nod; st[++VV]=2*nod+1;
        ARB[nod].total = maxim ();
    }
}
void query (int nod, int ci, int cs, int CI, int CS) {
    if (CI<=ci && cs <=CS) st[++VV]=nod;
    else {
        int mij=(ci+cs)/2;

        if (CI<=mij) query (2*nod, ci, mij, CI, CS);
        if (mij<CS) query (2*nod+1, mij+1, cs, CI, CS);
    }
}
int main ()
{
    f>>n>>Q;
    for (i=1; i<=n; ++i)
        f>>a[i];
    make_arb (1, 1, n);

    for (int i=1; i<=Q; ++i) {
        f>>ci>>cs;
        VV=0; query (1, 1, n, ci, cs);

        g<<maxim ()<<"\n";
    }

    return 0;
}
