# include <bits/stdc++.h>
# define NR 1000005
using namespace std;
ifstream f("hideandseek.in");
ofstream g("hideandseek.out");
int i,j,N,VV;
int pi1[NR], pi2[NR], sol[NR], st[NR], inv[NR], ap[NR];
long long X, Y,m,n;

void euclid (long long a, long long b, long long &x, long long &y) {
    if (b==0) {
        x=1; y=0;
        return;
    }
    long long x0, y0;
    euclid (b, a%b, x0, y0);
    x=y0;
    y=x0 - (a/b)*y0;
}
void inversa (int pi[]) {
    for (int i=1; i<=N; ++i)
        inv[pi[i]]=i;
    for (int i=1; i<=N; ++i)
        pi[i]=inv[i];
}
void inmultire (int pi[], long long putere) {
    memset (ap, 0, sizeof(ap));
    int I=0;
    long long Paux=putere;
    for (int i=1; i<=N; ++i) {
        if (! ap[i]) {
            if (i==pi[i]) continue;
            VV=0; st[++VV]=i; ap[i]=1;
            while (! ap[pi[st[VV]]]) {
                ap[pi[st[VV]]]=1;
                st[VV+1]=pi[st[VV]]; ++VV;
            }

            // punem ciclul la puterea respectiva
            Paux=putere%VV;

            I=Paux+1;
            for (int j=1; j<=VV; ++j) {
                pi[st[j]]=st[I];
                ++I; if (I==VV+1) I=1;
            }
        }
    }
}
int main()
{
    f>>N>>X>>Y;
    for (i=1; i<=N; ++i)
        f>>pi1[i];

    for (i=1; i<=N; ++i)
        f>>pi2[i];

    euclid (X, Y, m, n);

    if (m<0) inversa (pi1); m=abs(m);
    if (n<0) inversa (pi2); n=abs(n);

    //incepem sa facem inmultirile
    inmultire (pi1, m);
    inmultire (pi2, n);

    for (i=1; i<=N; ++i)
        sol[i]=pi1[pi2[i]];
    for (i=1; i<=N; ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
