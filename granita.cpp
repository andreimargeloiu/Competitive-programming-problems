# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,maxx,VV;
struct elem
{
    int x,y;
}a[20000];
bool cmp (elem x, elem y)
{
    if (x.x>y.x) return 0;
        else if (x.x==y.x && x.y<=y.y) return 0;
    else return 1;
}
int main ()
{
    freopen ("granita.in", "r", stdin);
    freopen ("granita.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d%d", &a[i].x, &a[i].y);
    sort (a+1, a+n+1, cmp);

    maxx=a[1].y;
    for (i=2; i<=n; ++i)
    {
        if (a[i].y<maxx) ++VV;
        else maxx=max(maxx, a[i].y);
    }
    printf ("%d", VV);
    return 0;
}
