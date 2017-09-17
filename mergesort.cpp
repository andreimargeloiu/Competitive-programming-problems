# include <bits/stdc++.h>
# define NR 1000005
# define MOD 1000003
using namespace std;
ifstream f("mergesort.in");
ofstream g("mergesort.out");
int i,j,n,m;
long long sol;
int INV[NR], F[NR], cnt[NR];
void factoriale () {
    F[0]=1;
    for (int i=1; i<=n; ++i)
        F[i]=(1LL*F[i-1]*i)%MOD;
}
void invers (int a, int b, int &x, int &y) {
    if (b==0) {
        x=1; y=0;
        return;
    }
    int x0, y0;
    invers (b, a%b, x0, y0);
    x=y0;
    y=x0 - (a/b)*y0;
}
int inv (int k) {
    if (! INV[k]) {
        int x, y;
        invers (k, MOD, x, y);
        if (x<0) x+=MOD;

        INV[k]=x;
    }
    return INV[k];
}
int Comb (int n, int k) {
    int sol=1;
    sol=(1LL * F[n] * inv(F[n-k]) %MOD * inv(F[k]))%MOD;

    if (sol<0) {
        sol+=0;
    }

    return sol;
}
void divide (int ci, int cs) {
    if (ci==cs) return;

    int L=cs-ci+1;
    if (! cnt[L]) cnt[L]=(1LL * 2 * Comb(n, L) * (F[L] - 1) % MOD * F[n-L])%MOD;

    sol=(sol + cnt[L])%MOD;

    int mij=(ci+cs)/2;
    divide (ci, mij);
    divide (mij+1, cs);
}
int main ()
{
    f>>n; factoriale();
    divide (1, n);

    g<<(sol + F[n])%MOD<<"\n";

    return 0;
}
