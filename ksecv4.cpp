# include <bits/stdc++.h>
# define NR 1000005
using namespace std;
ifstream f("ksecv4.in");
ofstream g("ksecv4.out");
struct elem {
    long long minn, maxx;
}ARB[4*NR];
int i,j,n,m,x,y,LAST,K,I;
long long ci, cs, mij, minn, maxx, sol, ok, G;
long long A[4000], B[4000], V[NR];
void make_arb (int nod, int ci, int cs) {
    if (ci==cs) ARB[nod].minn = ARB[nod].maxx = V[ci];
    else {
        int mij=(ci+cs)/2;
        make_arb(2*nod, ci, mij);
        make_arb(2*nod+1, mij+1, cs);

        ARB[nod].minn=min(ARB[2*nod].minn, ARB[2*nod+1].minn);
        ARB[nod].maxx=max(ARB[2*nod].maxx, ARB[2*nod+1].maxx);
    }
}
void urmator (int nod, int ci, int cs, int I) {
   if (ci==I) ok=1;
   if (! ok) {
        int mij=(ci+cs)/2;
        if (I<=mij) urmator (2*nod, ci, mij, I);
               else urmator (2*nod+1, mij+1, cs, I);
   }

   if (ok) {
        long long minnNEW, maxxNEW;
        int mij=(ci+cs)/2;

        if (ci==cs) { //un singur nou
            minnNEW=min(minn, ARB[nod].minn);
            maxxNEW=max(maxx, ARB[nod].maxx);

            if ((maxxNEW - minnNEW + 1)/2 <= G) {
                minn=minnNEW;
                maxx=maxxNEW;
                LAST=ci;
            }
            return;
        }

        if (LAST==ci-1) { //prima bucata
            minnNEW=min(minn, ARB[2*nod].minn);
            maxxNEW=max(maxx, ARB[2*nod].maxx);

            if ((maxxNEW - minnNEW + 1)/2 <= G) {
                minn=minnNEW;
                maxx=maxxNEW;
                LAST=mij;
            } else urmator (2*nod, ci, mij, I);
        }
        if (LAST==mij) { // a doua bucata
            minnNEW=min(minn, ARB[2*nod+1].minn);
            maxxNEW=max(maxx, ARB[2*nod+1].maxx);

            if ((maxxNEW - minnNEW + 1)/2 <= G) {
                minn=minnNEW;
                maxx=maxxNEW;
                LAST=cs;
            } else urmator (2*nod+1, mij+1, cs, I);
        }
   }
}
bool verifica () {
    int I, pasi=0;
    for (I=0; I<n && pasi < K; I+=0) {
        LAST=I-1; ++pasi; ok=0;
        minn=V[I]; maxx=V[I];

        urmator (1, 0, n-1, I);

        I=LAST + 1;
    }
    if (I==n) return 1;
           else return 0;
}
int main ()
{
    f>>n>>K>>m;
    for (i=0; i<m; ++i) f>>A[i];
    for (i=0; i<m; ++i) f>>B[i];

    ci=1000000000000;
    for (i=0; i<n; ++i) {
        V[i]=(A[i - i/m*m] xor B[i/m]);
        if (V[i] > cs) cs=V[i];
        if (ci > V[i]) ci=V[i];
    }
    make_arb(1, 0, n-1);

    cs=(cs-ci+1)/2; ci=0;
    while (ci<=cs) {
        G=(ci+cs)/2;
        if (verifica ()) cs=G-1, sol=G;
                    else ci=G+1;
    }
    g<<sol<<"\n";

    return 0;
}
