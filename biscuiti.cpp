# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("biscuiti.in");
ofstream g("biscuiti.out");
struct elem {
    long long minn, adaos;
    int nr;
}ARB[3*NR];

int i,j,n,m,x,y,I,a[NR];
long long sol, stanga;

void minim (int nod) {
    if ((ARB[2*nod].nr && ARB[2*nod].minn < ARB[2*nod+1].minn) || ARB[2*nod+1].nr==0)
         ARB[nod].minn=ARB[2*nod].minn;
    else ARB[nod].minn=ARB[2*nod+1].minn;

    ARB[nod].minn+=ARB[nod].adaos;
}
void make_arb (int nod, int ci, int cs) {
    if (ci==cs) {
        ARB[nod].minn=a[ci];
        ARB[nod].nr=1;
    } else {
        int mij=(ci + cs)/2;
        make_arb (2*nod, ci, mij);
        make_arb (2*nod+1, mij+1, cs);

        ARB[nod].nr=ARB[2*nod].nr + ARB[2*nod+1].nr;
        minim (nod);
    }
}
void query (int nod, int ci, int cs) { //caut minimul
    if (ci==cs) {
        I=ci;
        ARB[nod].nr=0;
    } else {
        int mij=(ci + cs)/2;
        if ((ARB[2*nod].nr && ARB[2*nod].minn <= ARB[2*nod+1].minn) || ! ARB[2*nod+1].nr)
             query (2*nod, ci, mij);
        else {
            stanga+=ARB[2*nod].nr;
            query (2*nod+1, mij+1, cs);
        }
        //nr
        ARB[nod].nr=ARB[2*nod].nr + ARB[2*nod+1].nr;

        minim (nod);
    }
}
void update (int nod, int ci, int cs, int CI, int CS, int val) {
    if (CI<=ci && cs<=CS) {
        if (ci==cs) { // un singur element
            ARB[nod].minn+=val;
        } else {
            ARB[nod].adaos+=val;

            minim (nod);
        }
    }
    else {
        int mij=(ci+cs)/2;
        if (CI<=mij) update (2*nod, ci, mij, CI, CS, val);
        if (mij<CS) update (2*nod+1, mij+1, cs, CI, CS, val);

        minim (nod);
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];

    make_arb (1, 1, n);

    for (i=1; i<=n; ++i) {
        stanga=0; query (1, 1, n);

        sol=sol + stanga*i;
        update (1, 1, n, 1, I, i);
    }
    g<<sol<<"\n";

    return 0;
}
