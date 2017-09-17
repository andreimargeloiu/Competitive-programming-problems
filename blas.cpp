# include <fstream>
# include <algorithm>
# include <cstring>
# define MOD 10067
# define NR 12
using namespace std;
ifstream f("blas.in");
ofstream g("blas.out");
int i,j,n,m,N,T;
int a[NR][NR], F[NR][NR], c[NR][NR];
void init ()
{
    for (int i=1; i<=10; ++i)
        memset (a[i], 0 , sizeof(a[i]));
    a[1][2]=1;
    a[2][1]=1; a[2][3]=1;
    a[3][4]=1;
    a[4][5]=1;
    a[5][6]=1; a[5][7]=1;
    a[6][8]=1;
    a[7][3]=1; a[7][7]=1;
    a[8][9]=1;
    a[9][6]=1; a[9][10]=1;
    a[10][3]=1; a[10][10]=1;

    F[1][1]=1;
    F[2][1]=2;
    F[3][1]=2;
    F[4][1]=4;
    F[5][1]=5;
    F[6][1]=3;
    F[7][1]=3;
    F[8][1]=5;
    F[9][1]=6;
    F[10][1]=4;
}
void inmultire (int a[][12], int b[][12], int la, int ca, int lb, int cb)
{
    int lc=ca, cc=cb;
    for (int i=1; i<=ca; ++i)
        for (int j=1; j<=cb; ++j) {
            c[i][j]=0;
            for (int k=1; k<=ca; ++k) {
                    c[i][j]+=(a[i][k]*b[k][j]);
                    if (c[i][j] > MOD) c[i][j]%=MOD;
            }
        }
    for (int i=1; i<=ca; ++i)
        for (int j=1; j<=cb; ++j)
            b[i][j]=c[i][j];
}
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t) {
        init ();
        f>>n;

        N=n-1;
        while (N>0) {
            if (N%2==1) {
                inmultire (a, F, 10, 10, 10, 1);
                --N;
            }
            else {
                inmultire (a, a, 10, 10, 10, 10);
                N=N/2;
            }
        }
        g<<F[1][1]<<"\n";
    }


    return 0;
}
