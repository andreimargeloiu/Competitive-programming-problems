# include <cstdio>
# include <vector>
# include <algorithm>
# define NR 100005
using namespace std;
int i,j,n,m,X,ci,cs,mij,M,sol;
int a[NR];
int main ()
{
    freopen ("uscat.in", "r", stdin);
    freopen ("uscat.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);
    scanf ("%d", &X);

    sort (a+1, a+n+1);

    if (X==1) {
        printf ("%d\n", a[n]);
        return 0;
    }

    ci=1; cs=1000000000;

    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        int M=mij;

        for (i=n; i>=1 && M>=0; --i) {
            if (a[i]<=mij) break;

            int rest=a[i]-mij;

            int cat=rest/(X-1);
            int R=rest%(X-1);

            if (R) ++cat;

            M-=cat;
        }
        if (M>=0) cs=mij-1, sol=mij;
             else ci=mij+1;
    }

    printf ("%d\n", sol);

    return 0;
}
