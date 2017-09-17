# include <cstdio>
# include <algorithm>
# define NR 1005
# define inf -999999999
using namespace std;
int i,j,n,m,x,X,X2,maxim,k,VV,act,nou;
int A[3][NR], B[3][NR], C[3][NR], S[NR][NR];
bool verifica (int y, int y2)
{
    if (1<=y && y<=m && 1<=y2 && y2<=m) return 1;
                                   else return 0;
}
int main ()
{
    freopen ("left.in", "r", stdin);
    freopen ("left.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            scanf ("%d", &x);
            S[i][j]=S[i][j-1] + x;
        }
    for (j=1; j<=m; ++j) {
        A[act][j]=S[1][j];
        B[act][j]=S[1][j];
        C[act][j]=S[1][j];
    }

    maxim=inf;
    for (i=2; i<=n; ++i) {
        nou=1-act; A[nou][1]=C[nou][m]=inf;
        for (j=1; j<=m; ++j){
            if (j!=1) A[nou][j]=S[i][j] + max (B[act][j-1], C[act][j-1]);
            if (i==n && j!=1) maxim=max(maxim, A[nou][j]);

            B[nou][j]=S[i][j] + max(A[act][j], C[act][j]);
            if (i==n) maxim=max(maxim, B[nou][j]);

            if (j!=m) C[nou][j]=S[i][j] + max(A[act][j+1], B[act][j+1]);
            if (i==n && j!=m) maxim=max(maxim, C[nou][j]);
        }
        act=nou;
    }

    printf ("%d\n", maxim);

    return 0;
}
