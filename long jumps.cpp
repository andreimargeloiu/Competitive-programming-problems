# include <cstdio>
# include <map>
using namespace std;
map <int, int> ap;
int a[100005];
int i,j,n,m,ok1,ok2,l,VV,x,y;
void det (int k)
{
    if (k<0 || k>l) return;
    if (ap[k-y] || ap[k+y]) VV=k;
}
int main ()
{
    freopen ("lj.in", "r", stdin);
    freopen ("lj.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &l, &x, &y);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &a[i]);
        ap[a[i]]=1;
    }
    for (i=1; i<=n; ++i)
    {
        ok1=ok1 || (ap[a[i]+x] || ap[a[i]-x]);
        ok2=ok2 || (ap[a[i]+y] || ap[a[i]-y]);
    }
    if (ok1 && ok2)
    {
        printf ("0\n");
        return 0;
    }
    if (ok1 || ok2)
    {
        printf ("1\n");
        printf ("%d\n", ok1?y:x);
        return 0;
    }
    VV=-1;
    for (i=1; i<=n; ++i)
    {
        det(a[i]+x);
        det(a[i]-x);
    }
    if (VV==-1) printf ("2\n%d %d\n", x, y);
        else printf ("1\n%d\n", VV);
    return 0;
}
