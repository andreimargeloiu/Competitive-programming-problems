# include <bits/stdc++.h>
# define NR 100005
# define INF 999999999
using namespace std;
ifstream f("eq.in");
ofstream g("eq.out");
struct elem {
    int minn, maxx, x_max_min, x_max_max, x_min_min, x_min_max, ymax, zmin;
}ARB[4*NR], st[NR];
int i,j,n,m,Q,ci,cs,sol,VV;
int a[NR];
int maxim (int a, int b, int c, int d, int e) {
    int sol=max(a, b);
    sol=max(sol, c);
    sol=max(sol, d);
    sol=max(sol, e);
    return sol;
}
int minim (int a, int b, int c, int d, int e) {
    int sol=min(a, b);
    sol=min(sol, c);
    sol=min(sol, d);
    sol=min(sol, e);
    return sol;
}
void make_arb (int nod, int ci, int cs) {
    if (ci==cs) {
        ARB[nod].minn=a[ci];
        ARB[nod].maxx=a[ci];

        ARB[nod].x_max_max=2*a[ci];
        ARB[nod].x_max_min=0;

        ARB[nod].x_min_max=0;
        ARB[nod].x_min_min=2*a[ci];

        ARB[nod].ymax=a[ci];
        ARB[nod].zmin=a[ci];
    } else {
        int mij=(ci + cs)/2;
        make_arb(2*nod, ci, mij);
        make_arb(2*nod+1, mij+1, cs);

        //calzulez ymax
        int minn=INF, maxx=0, xMM=0, xMm=0, xmM=INF, xmm=INF;
        //incerc sa le compun din ambele bucati
        for (int i=mij; i>=ci; --i) {
            //ymax
            minn=min(minn, a[i]); maxx=max(maxx, a[i]);

            xMM=max(xMM, a[i] + maxx);
            xMm=max(xMm, a[i] - minn);

            xmM=min(xmM, a[i] - maxx);
            xmm=min(xmm, a[i] + minn);
        }
        ARB[nod].ymax=maxim (ARB[2*nod].ymax, ARB[2*nod+1].ymax,
                             xMm+ARB[2*nod+1].maxx, xMM-ARB[2*nod+1].minn,
                             maxx - ARB[2*nod+1].minn + ARB[2*nod+1].maxx);

        ARB[nod].zmin=minim (ARB[2*nod].zmin, ARB[2*nod+1].zmin,
                             xmM+ARB[2*nod+1].minn, xmm-ARB[2*nod+1].maxx,
                             minn - ARB[2*nod+1].maxx + ARB[2*nod+1].minn);

        //@@@@@@@@@@@@@@@@@
        minn=INF, maxx=0, xMM=0, xMm=0, xmM=INF, xmm=INF;
        for (int i=cs; i>=ci; --i) {
            //ymax
            minn=min(minn, a[i]); maxx=max(maxx, a[i]);

            xMM=max(xMM, a[i] + maxx);
            xMm=max(xMm, a[i] - minn);

            xmM=min(xmM, a[i] - maxx);
            xmm=min(xmm, a[i] + minn);
        }
        ARB[nod].x_max_max=xMM;
        ARB[nod].x_max_min=xMm;
        ARB[nod].x_min_max=xmM;
        ARB[nod].x_min_min=xmm;

        ARB[nod].maxx=maxx;
        ARB[nod].minn=minn;
    }
}
void intervals (int nod, int ci, int cs, int CI, int CS) {
    if (CI<=ci && cs<=CS) st[++VV]=ARB[nod];
    else {
        int mij=(ci+cs)/2;
        if (CI<=mij) intervals (2*nod, ci, mij, CI, CS);
        if (mij<CS) intervals (2*nod+1, mij+1, cs, CI, CS);
    }
}
int solution () {
    int Y=st[VV].ymax, Z=st[VV].zmin, minn, maxx;
    minn=st[VV].minn;
    maxx=st[VV].maxx;
    for (int i=VV-1; i>=1; --i) {
        Y=maxim (st[i].ymax, st[i].x_max_max - minn, st[i].x_max_min + maxx,
                 st[i].maxx + maxx - minn, Y);

        Z=minim (st[i].zmin, st[i].x_min_min - maxx, st[i].x_min_max + minn,
                 st[i].minn + minn - maxx, Z);
        minn=min(minn, st[i].minn);
        maxx=max(maxx, st[i].maxx);
    }
    return Y+Z;
}
int main ()
{
    f>>n>>Q;
    for (i=1; i<=n; ++i)
        f>>a[i];

    make_arb(1, 1, n);

    for (i=1; i<=Q; ++i) {
        f>>ci>>cs;
        VV=0;

        intervals (1, 1, n, ci, cs);
        sol=solution();
        g<<sol<<"\n";
    }

    return 0;
}
