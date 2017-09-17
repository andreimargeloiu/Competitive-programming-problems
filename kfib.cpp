# include <bits/stdc++.h>
# define MOD 666013
# define N 5
using namespace std;
ifstream f("kfib.in");
ofstream g("kfib.out");
int i,j,n,m;
int a[N][N], b[N][N], c[N][N], F[N][N];
void inmultire (int a[][5], int b[][5], int la, int ca, int lb, int cb) {
    int lc=la, cc=cb;
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j) {
            c[i][j]=0;
            for (int k=1; k<=cc; ++k)
                c[i][j]=(1LL*c[i][j] + 1LL*a[i][k]*b[k][j])%MOD;
        }
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j)
            a[i][j]=c[i][j];
}
void ridicare (int K) {
    while (K) {
        if (K%2==1) {
            inmultire (F, a, 1, 2, 2, 2);
            --K;
        } else {
            inmultire (a, a, 2, 2, 2, 2);
            K=K/2;
        }
    }
}
int main ()
{
    f>>n;
    F[1][1]=1; F[1][2]=1;

               a[1][2]=1;
    a[2][1]=1; a[2][2]=1;

    ridicare (n-2);
    g<<F[1][2]<<"\n";

    return 0;
}
