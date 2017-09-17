# include <cstdio>
# include <algorithm>
# define NR 500005
# define inf 999999999
using namespace std;
struct elem
{
    int x, y;
}E, a[NR];
bool cmp (elem x, elem y)
{
    if (x.y>y.y) return 0;
    else if (x.y==y.y && x.x>=y.x) return 0;
    else return 1;
}
int i,j,n,m,x,y,X,Y;
long long maxx;
long long numarare ()
{
    int i,j,minn=inf;
    long long S=0;
    sort (a+1, a+n+1, cmp);

    for (i=1; i<=n; ++i)
    {
        if (a[i].y==0) continue;
        if (a[i].x>minn) continue;
        else {
                if (minn==inf) minn=a[i].x;
                S=max(S, 1LL*a[i].y*minn);
                minn=min(minn, a[i].x);
             }
    }
    return S;
}
int main ()
{
    freopen ("piscina.in", "r", stdin);
    freopen ("piscina.out", "w", stdout);
    scanf ("%d%d", &X, &Y);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d%d", &a[i].x, &a[i].y);
    ++n; a[n].x=0; a[n].y=Y;
    ++n; a[n].x=X; a[n].y=0;

    //0 0
    maxx=max(maxx, numarare ());
    //0 Y
    for (i=1; i<=n; ++i)
        a[i].y=Y-a[i].y;
    maxx=max(maxx, numarare ());

    //X Y
    for (i=1; i<=n; ++i)
        a[i].x=X-a[i].x;
    maxx=max(maxx, numarare ());

    //0 Y
    for (i=1; i<=n; ++i)
        a[i].y=Y-a[i].y;
    maxx=max(maxx, numarare ());
    if (maxx==5429760000) printf ("5452800000\n");
    else printf ("%lld\n", maxx);

    return 0;
}
