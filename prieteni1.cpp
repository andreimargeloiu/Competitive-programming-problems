# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,K,v1,v2;
int main ()
{
    freopen ("prieteni1.in", "r", stdin);
    freopen ("prieteni1.out", "w", stdout);

    scanf ("%d%d", &n, &K);

    v1=n/2; v2=n-v1;

    if (K<=v1*v2) {
        printf ("1\n");
        for (i=1; i<=v1 && K; ++i)
            for (j=v1+1; j<=n && K; ++j) {
                printf ("%d %d\n", i, j);
                --K;
            }
    }
    else printf ("0\n");



    return 0;
}
