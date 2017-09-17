# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 7
using namespace std;
ifstream f("numere4.in");
ofstream g("numere4.out");
int i,j,n,m,T,K,P;
int F[NR][NR], M[NR][NR], C[NR][NR];
void init () {
    for (int i=1; i<=K; ++i) {
        memset (M[i], 0, sizeof(M));
        if (i==1) for (int j=1; j<=K; ++j) M[i][j]=1;
        else M[i][i-1]=1;
    }
    for (int i=1; i<=K; ++i) F[i][1]=0;

    F[1][1]=F[2][1]=1;
}
void inmultire (int a[][NR], int b[][NR], int la, int ca, int lb, int cb)
{
    int lc=ca, cc=cb;
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j) {
            C[i][j]=0;
            for (int k=1; k<=ca; ++k) {
                C[i][j]+=a[i][k]*b[k][j];
                if (C[i][j]>=10) C[i][j]%=10;
            }
        }
     for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j)
            b[i][j]=C[i][j];
}
int putere (long long N)
{
    init ();
    while (N)
    {
        if (N%2==1) {
            inmultire (M, F, K, K, K, 1);
            --N;
        }
        else {
                 inmultire (M, M, K, K, K, K);
                 N=N/2;
             }
    }
    return F[1][1];
}
int main ()
{
    f>>T>>K;
    for (int t=1; t<=T; ++t) {
        init ();
        f>>P;

        putere (P-1);
        g<<F[1][1]<<" ";
    }
    g<<"\n";

    return 0;
}
