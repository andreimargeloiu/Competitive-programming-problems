# include <algorithm>
# include <fstream>
# define NR 105
# define MOD 41143
using namespace std;
ifstream f("pkinv.in");
ofstream g("pkinv.out");
int i,j,n,m,K;
unsigned int M[NR][NR], F[NR][NR], C[NR][NR], DP[NR][NR];
void init () {
    for (int i=1; i<=K+1; ++i)
        for (int j=i; j<=K+1; ++j)
            M[i][j]=1;

    for (int i=1; i<=min(n, K+1); ++i)
        F[i][1]=DP[min(n, K+1)][K-i+1];
}
void inmultire (unsigned int a[][NR], unsigned int b[][NR], int la, int ca, int lb, int cb) {
    int i,j,k, lc=ca, cc=cb;
    for (i=1; i<=lc; ++i) {
        for (j=1; j<=cc; ++j) {
            C[i][j]=0;
            for (k=1; k<=ca; ++k) {
                C[i][j]=C[i][j] + a[i][k]*b[k][j]%MOD;
                C[i][j]%=MOD;
            }
        }
    }
    for (i=1; i<=lc; ++i)
        for (j=1; j<=cc; ++j)
            b[i][j]=C[i][j];

}
void putere (int N) {
    while (N) {
        if (N%2==1) {
            inmultire (M, F, K+1, K+1, K+1, 1);
            --N;
        }
        else {
            inmultire (M, M, K+1, K+1, K+1, K+1);
            N=N/2;
        }
    }
}
void dinamica () {
    DP[0][0]=1; DP[1][0]=1;
    for (int i=2; i<=min(n, K+1); ++i)
        for (int j=0; j<=K; ++j)
            for (int k=0; k<i && j-k>=0; ++k)
                DP[i][j]=(DP[i][j] + DP[i-1][j-k])%MOD;
}
int main ()
{
    f>>n>>K;

    dinamica ();
    init ();

    /*for (i=1; i<=min(n, K+1); ++i)
    {
        for (j=0; j<=K; ++j)
            g<<DP[i][j]<<" ";
        g<<"\n";
    }*/

    putere (n-K-1);

    g<<F[1][1]<<"\n";

    return 0;
}
