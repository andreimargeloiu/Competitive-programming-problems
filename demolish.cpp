# include <bits/stdc++.h>
# define NR 500005
# define ff 50005
using namespace std;
ifstream f("demolish.in");
ofstream g("demolish.out");
struct elem {
    int x, x2, y, y2, cost;
}a[ff], a2[ff];
bool cmpx (elem x, elem y) {
    return x.x < y.x;
}
bool cmpx2 (elem x, elem y) {
    return x.x2 < y.x2;
}
int i,j,n,m,CS,DX,DY,VV,VV2,F,N,M,X,Y,minn;
int ARB[4*NR], lazy[4*NR], poz[4*NR];
//ARB[nod] - minimul pe intervalul respectiv
//lazy[nod]
//poz[nod]
void init (int nod, int ci, int cs) {
    poz[nod]=ci;
    if (ci!=cs) {
        int mij=(ci+cs)/2;
        init (2*nod, ci, mij);
        init (2*nod+1, mij+1, cs);
    }
}
void update (int nod, int ci, int cs, int CI, int CS, int cost) {
    if (CI<=ci && cs<=CS) {
        lazy[nod]+=cost;
        if (ci==cs) ARB[nod]=lazy[nod];
        else {
            if (ARB[2*nod]<=ARB[2*nod+1]) ARB[nod]=ARB[2*nod], poz[nod]=poz[2*nod];
                                     else ARB[nod]=ARB[2*nod+1], poz[nod]=poz[2*nod+1];

            ARB[nod]+=lazy[nod];
        }
    } else {
        int mij=(ci+cs)/2;
        if (CI<=mij) update (2*nod, ci, mij, CI, CS, cost);
        if (mij<CS) update (2*nod+1, mij+1, cs, CI, CS, cost);

        if (ARB[2*nod]<=ARB[2*nod+1]) ARB[nod]=ARB[2*nod], poz[nod]=poz[2*nod];
                                 else ARB[nod]=ARB[2*nod+1], poz[nod]=poz[2*nod+1];

        ARB[nod]+=lazy[nod];
    }
}
int main ()
{
    f>>M>>N>>F>>DX>>DY;
    for (i=1; i<=F; ++i) {
        f>>a[i].x>>a[i].y>>a[i].x2>>a[i].y2>>a[i].cost;
        a2[i]=a[i];
    }
    sort (a+1, a+F+1, cmpx);
    sort (a2+1, a2+F+1, cmpx2);
    CS=N - DY;
    init (1, 0, CS);

    VV=0; VV2=0; minn=1LL<<30;
    for (i=DX; i<M; ++i) { //dreapta de baleie din dreapta
        while (a[VV+1].x<i && VV<F) { //bagam
            ++VV;
            update (1, 0, CS, max(0, a[VV].y-DY+1), min(CS, a[VV].y2-1), a[VV].cost);
        }
        while (a2[VV2+1].x2==i-DX && VV2<F) { //scoatem
            ++VV2;
            update (1, 0, CS, max(0, a2[VV2].y-DY+1), min(CS, a2[VV2].y2-1), -a2[VV2].cost);
        }
        if (ARB[1] < minn) {
            minn=ARB[1];
            X=i-DX;
            Y=poz[1];
        }
    }
    g<<minn<<"\n"<<X<<" "<<Y<<" "<<X+DX<<" "<<Y+DY<<"\n";

    return 0;
}
