# include <cstdio>
# include <algorithm>
# define mod 100003
# define NR 2005
using namespace std;
int i,j,n,m,tip,nr,S;
int a[NR][NR];
int main ()
{
    freopen ("fractii2.in", "r", stdin);
    freopen ("fractii2.out", "w", stdout);
    scanf ("%d%d", &tip, &n);
    if (tip==1)
    {
        for (i=1; i<n; ++i)
            printf ("%d ", i);
        printf ("%d\n", n-1);
    }
    else
    {
        // a[i][j] - numarul de moduri de a scrie 1 din i fractii
        //           astfel incat 2*j dintre ele au numitor maxim

        // putem imparti acele 2*j fractii cu numitor maxim in 2 bucati fiecare

        a[2][1]=1;
        for (i=3; i<=n; ++i)
        {
            m=i/2;
            for (j=1; j<=i/2; ++j)
                a[i][j]+=a[i-j][j/2];
        }
        for (i=1; i<=n; ++i)
            S+=a[n][i];
        printf ("%d\n", S);

    }


    return 0;
}
