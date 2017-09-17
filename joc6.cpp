# include <cstdio>
using namespace std;
int i,n,j,VV,x;
int main ()
{
    freopen ("joc6.in", "r", stdin);
    freopen ("joc6.out", "w", stdout);
    while (scanf ("%d", &n) && n!=0)
    {
        VV=0;
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j)
            {
                scanf ("%d", &x);
                if (i==j) VV=VV^x;
            }
        if (VV) printf ("1\n");
            else printf ("2\n");
    }


    return 0;
}
