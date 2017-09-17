# include <cstdio>
# include <algorithm>
# define NR 50005
using namespace std;
struct elem
{
    double a, b, k, p, v;
}a[NR];
bool cmp (elem x, elem y)
{
    if (x.v>=y.v) return 0;
    else return 1;
}
int i,j,n,VV;
double L, C, ant, sol[NR], Sa, Sb, Sk, Sp;
int main ()
{
    freopen ("xmoto.in", "r", stdin);
    freopen ("xmoto.out", "w", stdout);
    scanf ("%d%lf", &n, &L);
    for (i=1; i<=n; ++i)
        scanf ("%lf %lf %lf %lf %lf", &a[i].a, &a[i].b, &a[i].k, &a[i].p, &a[i].v);

    sort (a+1, a+n+1, cmp);

    for (i=n; i>=1; --i)
        Sa+=a[i].a, Sk+=a[i].k;

    a[n+1].v=999999999;
    for (i=1; i<=n+1; ++i)
    {
        //incepem sa calculam
        C=(L-Sk-Sp);
        C=C / (Sa+Sb);
        if (a[i-1].v<C && C<=a[i].v && C<=10000)
        {
            sol[++VV]=C;
        }
        Sb+=a[i].b; Sp+=a[i].p;
        Sa-=a[i].a; Sa=Sa; Sk-=a[i].k;
    }
    printf ("%d\n", VV);
    for (i=1; i<=VV; ++i)
        printf ("%0.6lf\n", sol[i]);

    return 0;
}
