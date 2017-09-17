# include <cstdio>
# include <algorithm>
using namespace std;
int cmp (int x, int y)
{
    if (x<=y) return 0;
        else return 1;
}
int i,n,pornire;
int a[5005],start[5005],stop[5005];
int main ()
{
    freopen ("grade.in", "r", stdin);
    freopen ("grade.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);
    sort (a+1,a+n+1, cmp);
    for (i=1; i<=n+1; ++i)
    {
        if (!start[a[i]]) start[a[i]]=i;
        if (a[i]<a[i-1]) stop[a[i-1]]=i-1;
    }
    for (i=1; i<=n && a[i]!=0; ++i)
    {
        if (start[a[i]]!=stop[a[i]]) pornire=i+1;
            else pornire=stop[a[i]];
        while (a[i])
        {
            --a[pornire];
            printf ("%d %d\n", i, pornire);
        }
    }

    return 0;
}
