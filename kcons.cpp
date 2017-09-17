# include <cstdio>
# include <algorithm>
# define NR 2005
# define MOD 30013
using namespace std;
int i,j,n,m,K,solutie;
int a[NR][NR], s[NR][NR], B[NR][NR];
int main ()
{
    freopen ("kcons.in", "r", stdin);
    freopen ("kcons.out", "w", stdout);
    scanf ("%d%d", &n, &K);

    // B[i][j] - numarul de moduri de a face permutari din j numere
    //           astfel incat sa avem j grupuri cu 2 elemente consecutive
    B[1][0]=1;
    for (i=2; i<=n; ++i) {
        for (j=0; j<=i; ++j) {
            if (j>0) B[i][j]=B[i-1][j-1];
            B[i][j]+=B[i-1][j]*(i-j-1) + B[i-1][j+1]*(j+1);
            B[i][j]%=MOD;
        }
    }

    // a[i][j] - numarul de moduri de a imparti primele i elemente
    //           in j subsecvente de cel mult K elem
//@@@@@@@@@@@@@@@@@@@@@@@@
    a[1][1]=1; s[1][1]=1;
    for (i=2; i<=n; ++i) {
        if (i<=K) a[i][1]=1;

        s[i][1]=s[i-1][1] + a[i][1];

        for (j=2; j<=i; ++j) {
            if (i<=K) {
                a[i][j]=MOD + s[i-1][j-1];
            }
            else {
                a[i][j]=MOD + s[i-1][j-1] - s[i-K-1][j-1];
            }

            a[i][j]%=MOD;
            s[i][j]=(s[i-1][j] + a[i][j])%MOD;
        }
    }

    for (i=1; i<=n; ++i) {
        solutie=(solutie + a[n][i] * B[i][0])%MOD;
    }
    printf ("%d\n", solutie);


    return 0;
}
