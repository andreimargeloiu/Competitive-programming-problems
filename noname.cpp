# include <cstdio>
# include <algorithm>
# define NR 1005
using namespace std;
int i,j,n,m,CI,CS,x;
short a[NR][NR], L[NR], C[NR];
int main ()
{
    freopen ("noname.in", "r", stdin);
    freopen ("noname.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i) {
        scanf ("%d", &x);
        L[x]=i;
    }
    for (i=1; i<=n; ++i) {
        scanf ("%d", &x);
        C[x]=i;
    }


    for (i=1; i<=(n+1)/2; ++i) {

        CI=i; CS=n-i+1;

        //mai intai CS
        for (j=1; j<=n; ++j) {
            if (a[L[CS]][j]==0) a[L[CS]][j]=2;
            if (a[j][C[CS]]==0) a[j][C[CS]]=2;

            if (a[L[CI]][j]==0 && j!=C[CS]) a[L[CI]][j]=1;
            if (a[j][C[CI]]==0 && j!=L[CS]) a[j][C[CI]]=1;
        }
    }

    printf ("1\n");
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j)
            printf ("%d ", a[i][j]-1);
        printf ("\n");
    }


    return 0;
}
