# include <cstdio>
# include <algorithm>
# define NR 105
using namespace std;
int i,j,n,m,x,y,solutie,K,T;
int maxx[NR];
struct elem {
    int t,v,rang;
}a[NR];
bool cmp (elem x, elem y) {
    if (x.t>=y.t) return 0;
             else return 1;
}
int main ()
{
    freopen ("vedete.in", "r", stdin);
    freopen ("vedete.out", "w", stdout);
    scanf ("%d%d%d", &n, &K, &T);

    for (i=1; i<=n; ++i) scanf ("%d", &a[i].t);
    for (i=1; i<=n; ++i) scanf ("%d", &a[i].v);
    for (i=1; i<=n; ++i) scanf ("%d", &a[i].rang);

    sort (a+1, a+n+1, cmp);

    for (i=1; i<=n; ++i) { //fiecare vedeta
        if (a[i].t>T || a[i].rang>K)  continue;
        if (a[i].t>=a[i].rang) maxx[i]=a[i].v; // ea singura

        for (j=1; j<i; ++j)
            if (maxx[j] && abs(a[i].rang - a[j].rang) <= a[i].t - a[j].t)
                maxx[i]=max(maxx[i], maxx[j] + a[i].v);

        solutie=max(solutie, maxx[i]);
    }
    printf ("%d\n", solutie);


    return 0;
}
