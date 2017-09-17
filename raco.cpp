# include <bits/stdc++.h>
# define modulo 1000003
# define NR 305
# define mil 1000005
using namespace std;
ifstream f("raco.in");
ofstream g("raco.out");
int i,j,n,m,x,y,act,nou,MOD,k,R,maxx;
int ap[NR], aux[NR][NR], F[mil], inv[mil], rest[2*NR+5];
long long sol[2][NR];
void euclid (int a, int b, int &x, int &y){
    if (b==0) {
        x=1; y=0;
        return;
    }
    int x0, y0;
    euclid (b, a%b, x0, y0);
    x=y0;
    y=x0 - (a/b)*y0;
}
int invers (int X) {
    int x, y;

    euclid (X, modulo, x, y);
    if (x<0) x=modulo + x%modulo;
        else x%=modulo;

    return x;
}
void factorial () {
    F[0]=1;
    for (int i=1; i<=maxx; ++i)
        F[i]=1LL * F[i-1] * i % modulo;

    inv[maxx]=invers(F[maxx]);
    for (int i=maxx-1; i>=0; --i) {
        inv[i]=(1LL*inv[i+1]*(i+1))%modulo;
    }
}
int Comb (int n, int k) {
    int X1=inv[n-k], X2=inv[k];
    int sol=(1LL * F[n] * X1 % modulo * X2)%modulo;
    return sol;
}
void resturi () {
    for (int i=0; i<=2*MOD; ++i)
        rest[i]=i%MOD;
}
int main ()
{
    f>>n>>MOD;
    for (i=1; i<=n; ++i) {
        f>>x;
        ++ap[x % MOD];
    }
    for (i=0; i<MOD; ++i)
        maxx=max(maxx, ap[i]);
    factorial (); resturi ();
    // aux[i][rest] - numarul de moduri de a face sume cu restul rest folosind numarul i
    for (i=0; i<MOD; ++i)  // fiecare numar
        for (j=1; j<=ap[i]; ++j) {
            R=(i*j)%MOD;
            aux[i][R] = (aux[i][R] + Comb(ap[i], j))%modulo;
        }

    for (i=0; i<MOD; ++i) { // ce numar adaug acum
        nou=1-act;
        for (j=0; j<MOD; ++j)
            sol[nou][j]=sol[act][j];

        for (k=0; k<MOD; ++k) {//fiecare rest pe care il pot adauga cu echipe din nr i
            sol[nou][k]+=aux[i][k];
            for (j=0; j<MOD; ++j) {//fiecare rest anterior
                R=rest[j+k];
                sol[nou][R]=sol[nou][R] + sol[act][j] * aux[i][k];
                sol[nou][R]=sol[nou][R] - sol[nou][R]/modulo*modulo;
            }
        }
        act=nou;
    }
    g<<sol[act][0]%modulo<<"\n";

    return 0;
}
