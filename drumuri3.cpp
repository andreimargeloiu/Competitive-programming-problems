# include <fstream>
# include <cstring>
# include <algorithm>
# define MOD 10007
# define NR 105
using namespace std;
ifstream f("drumuri3.in");
ofstream g("drumuri3.out");
int i,j,n,m,x,y,K,Q,N;
int A[NR][NR], B[NR][NR], aux[NR][NR], var[NR][NR], c[NR][NR], AUX[NR][NR];
void inmultire (int a[NR][NR], int b[NR][NR]) {
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            c[i][j]=0;
            for (int k=1; k<=n; ++k) {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=MOD;
            }
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            a[i][j]=c[i][j];
}
void adunare (int aux[NR][NR], int a[NR][NR]) {
    int i,j;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j) {
            if (i==j) aux[i][j]=a[i][j] + 1;
                 else aux[i][j]=a[i][j];

            aux[i][j]%=MOD;
        }
}
void aduna (int a[NR][NR], int b[NR][NR]) {
     for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            a[i][j]+=b[i][j];

            a[i][j]%=MOD;
        }
}
void multiply (int K) {
    if (K<=1) return;

    if (K%2==1) {
        multiply ((K-1)/2);

        adunare (aux, A); // A + I
        inmultire (B, aux);

        inmultire (A, A);
        inmultire (A, var);
        aduna (B, A);
    }
    else {
            multiply (K/2);
            adunare (aux, A); // A + I
            inmultire (B, aux);
            inmultire (A, A);
         }
}
int main ()
{
    f>>n>>m>>K>>Q;
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        A[x][y]=1; B[x][y]=1;
        A[y][x]=1; B[y][x]=1;

        var[x][y]=1;
        var[y][x]=1;
    }
    --K;
    multiply (K);

    for (i=1; i<=Q; ++i) {
        f>>x>>y;
        g<<B[x][y]<<"\n";
    }
    //g<<"george";
    return 0;
}
