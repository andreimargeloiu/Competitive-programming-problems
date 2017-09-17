# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 100005
# define inf 999999999
using namespace std;
struct elem
{
    int x, y;
}a[NR], st[NR];
bool cmp (elem x, elem y)
{
    if (x.x>=y.x) return 0;
             else return 1;
}
int i,j,n,m,minn,ci,cs,mij,sol,VV;
bool verificare (int G)
{
     int i, ci=1, cs=1, maxx=-inf, minn=inf, ok=0;
     st[1]=a[1];
     for (i=2; i<=n; ++i)
     {
         st[++cs]=a[i];
         while (i>1 && st[ci].x+G<=a[i].x && ci<cs)
         {
             minn=min(minn, st[ci].y);
             maxx=max(maxx, st[ci].y);
             ++ci; ok=1;
         }
         if (ok)
         {
            if (abs(minn-a[i].y)>=G || abs(maxx-a[i].y)>=G) return 1;
         }
     }
     return 0;
}
int main ()
{
    freopen ("dist2.in", "r", stdin);
    freopen ("dist2.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d%d", &a[i].x, &a[i].y);

    sort (a+1, a+n+1, cmp);

    ci=0; cs=abs(a[1].x-a[2].y);

    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (verificare (mij)) ci=mij+1, sol=mij;//daca exista distante si mai mari sau egale
                         else cs=mij-1;
    }

    printf ("%d\n", sol);

    return 0;
}
