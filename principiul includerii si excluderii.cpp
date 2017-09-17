# include <bits/stdc++.h>
# define NR 1000005
using namespace std;
ifstream f("pinex.in");
ofstream g("pinex.out");
struct elem {
    long long p;
    int nrb, mask;
}E;
queue <elem> Q;
bitset <NR> ap;

int i,j,I,VV,NP,m;
int prim[200005];
long long st[100], A, B;

void ciur () {
    prim[++NP]=2;
    for (int i=3; i<=NR-5; ++i)
        if (! ap[i]) {
            prim[++NP]=i;
            for (int j=3; i*j<=NR-5; j+=2)
                ap[i*j]=1;
        }
}
void descompune (long long B) {
    int M=sqrt((double)(B));
    VV=0; I=1;
    while (prim[I]<=M) {
        if (B % prim[I]==0) {
            st[++VV]=prim[I];
            while (B % prim[I]==0)
                B=B/prim[I];
        }
        if (B==1) break;
        ++I;
    }
    if (B!=1) st[++VV]=B;
}
void solve () {
    long long sol=0, P;
    int nrb;

    for (int i=1; i<(1<<VV); ++i) {
        nrb=0; P=1;
        for (j=0; j<VV; ++j)
            if ((1<<j) & i) {
                ++nrb;
                P=P * st[j+1];
            }
        if (nrb%2==1) sol=sol + A/P;
                 else sol=sol - A/P;

    }
    g<<A - sol<<"\n";
}
int main ()
{
    f>>m; ciur ();
    for (i=1; i<=m; ++i) {
        f>>A>>B;
        descompune (B);
        solve ();
    }

    return 0;
}
