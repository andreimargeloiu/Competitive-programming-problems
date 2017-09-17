# include <cstdio>
using namespace std;
int k;
long long S,i,n;
int main ()
{
    freopen ("prieten.in", "r", stdin);
    freopen ("prieten.out", "w", stdout);
    scanf ("%d%d", &n, &k);
    scanf ("%lld", &S);
    for (i=1; i<=k; ++i)
        printf ("%lld ", (n+1)*i);
    printf ("\n");
    for (i=1; i<=500000; ++i)
    {
        if (2*S==i*(i-1)*(i+1))
        {
            printf ("%d\n", i);
            return 0;
        }
    }
    return 0;
}
