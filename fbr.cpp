# include <cstdio>
# include <algorithm>
# define NR 20000
using namespace std;
struct elem
{
    int D, maxx, pr;
}a[1005];
bool cmp (elem x, elem y)
{
    if (x.maxx>=y.maxx) return 0;
                   else return 1;
}
int i,j,n,m,act,nou,maxx;
int P[NR];
int main ()
{
    freopen ("fbr.in", "r", stdin);
    freopen ("fbr.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d%d%d", &a[i].D, &a[i].maxx, &a[i].pr);

    sort (a+1, a+n+1, cmp);
    P[0]=1;
    for (i=1; i<=n; ++i){
        for (j=a[i].maxx-a[i].D; j>=0; --j)
            if (P[j] && P[j]+a[i].pr > P[j+a[i].D])
                P[j+a[i].D]=P[j]+a[i].pr;
    }

    maxx=0;
    for (i=1; i<=NR-5; ++i)
        maxx=max(maxx, P[i]);
    printf ("%d\n", maxx-1);

    return 0;
}
