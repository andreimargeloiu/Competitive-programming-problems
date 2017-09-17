# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 52
# define N 100
using namespace std;
ifstream f("gard2.in");
ofstream g("gard2.out");
int i,j,n,m,K,p;
int C[NR][NR][N], a[NR][NR][N], var[N], zero[N], SOL[N];
void aduna (int a[], int b[], int c[]) {
    a[0]=max(a[0], max(b[0], c[0]));
    int t=0;
    for (int i=1; i<=a[0]; ++i) {
        t=t + a[i] + b[i] + c[i];
        a[i]=t%10;
        t=t/10;
    }
    while (t) a[++a[0]]=t%10, t=t/10;
}
void combinari () {
    for (int i=1; i<=n; ++i) {
        C[i][0][0]=C[i][0][1]=1;
        C[i][i][0]=C[i][i][1]=1;
        for (int j=1; j<i; ++j)
            aduna (C[i][j], C[i-1][j], C[i-1][j-1]);
    }
}
void inmultire (int sol[], int a[], int b[]) {
    int t=0;
    sol[0]=a[0] + b[0] - 1;
    for (int i=1; i<=a[0]; ++i)
        for (int j=1; j<=b[0]; ++j)
            sol[i+j-1]+=a[i]*b[j];

    for (int i=1; i<=sol[0]; ++i) {
        t=t + sol[i];
        sol[i]=t%10;
        t=t/10;
    }
    while (t) sol[++sol[0]]=t%10, t=t/10;
}
int main ()
{
    f>>n>>K;
    combinari ();

    //a[i][j]- numarul de moduri de a pune j oameni in i ture

    for (j=1; j<=K; ++j)
        aduna (a[1][j], C[n][j], zero);
    for (i=2; i<=n; ++i) {
        for (j=i; j<=min (n, i*K); ++j) {
            for (p=1; p<=K; ++p) {
                if (j-p <= 0) break;

                memset (var, 0, sizeof(var));
                inmultire (var, a[i-1][j-p], C[n-j+p][p]);

                aduna (a[i][j], var, zero);
            }
        }
    }

    for (i=1; i<=n; ++i)
        aduna (SOL, a[i][n], zero);

    for (i=SOL[0]; i>=1; --i)
        g<<SOL[i];
    g<<"\n";

    return 0;
}
