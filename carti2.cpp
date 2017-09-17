# include <bits/stdc++.h>
# define N 13
# define INF 99999999
using namespace std;
ifstream f("carti2.in");
ofstream g("carti2.out");
vector <int> sol;
int i,j,n,m,x,y,maxx,L,G,H,T,BitiMax;
int biti[1<<N], dp[1<<N], A[1<<N], B[1<<N];
void make_biti () {
    for (int i=1; i<=(1<<N)-1; ++i) {
        int X=i;
        while (X) {
            int u=X%2; X=X/2;
            biti[i]+=u;
        }
    }
}
int Lexico (int A, int B) {
    int X= A ^ B;

    for (int i=0; i<n; ++i) {
        if (((1<<i) & X) && ((1<<i) & A)) return A;
        if (((1<<i) & X) && ((1<<i) & B)) return B;
    }
}
void DINAMICA () {
    //dp[i] - inaltimea minima pentru a pune bitii de i
    for (int i=1; i<(1<<n); ++i) {
        dp[i]=INF;
        if (i==89) {
            dp[i]=INF;
            dp[i]=INF;
        }
        for (int mask=i; mask!=0; mask=(mask-1) & i) { //un nou raft
            int MASK=mask, Haux=0, Laux=0, last;
            while (MASK) {
                last=MASK & (-MASK);

                Haux=max(Haux, A[last]);
                Laux=Laux + B[last];

                MASK=MASK - last;
            }

            if (Laux<=L) dp[i]=min(dp[i], G + Haux + dp[i - mask]);
        }
        if (dp[i]<=H) {
            if (biti[i] > biti[maxx]) maxx=i;
            else if (biti[i]==biti[maxx]) maxx=Lexico(maxx, i);
        }
    }
}
int main ()
{
    f>>T; make_biti ();
    while (T--) {
        f>>n>>H>>L>>G;
        for (i=0; i<n; ++i) {
            f>>x>>y;
            A[1<<i]=x; B[1<<i]=y;
        }

        maxx=0;
        DINAMICA();

        for (i=0; i<n; ++i)
            if ((1<<i) & maxx) sol.push_back(i);

        g<<sol.size()<<"\n";
        for (auto &x: sol)
            g<<1 + x<<" ";
        g<<"\n";

        sol.clear();
    }

    return 0;
}
