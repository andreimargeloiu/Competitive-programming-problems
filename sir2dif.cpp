# include <cstdio>
# include <algorithm>
# define NR 100005
using namespace std;
int i,j,n,m,maxx,minn;
int back[NR], front[NR], a[NR];
int main ()
{
    freopen ("sir2dif.in", "r", stdin);
    freopen ("sir2dif.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);

    //front-ul
    maxx=a[1];
    for (i=2; i<=n; ++i)
    {
        front[i]=maxx-a[i];
        maxx=max(maxx, a[i]);
    }
    for (i=3; i<=n; ++i)
        front[i]=max(front[i], front[i-1]);

    //back
    minn=a[n];
    for (i=n-1; i>=1; --i)
    {
        back[i]=a[i]-minn;
        minn=min(minn, a[i]);
    }
    for (i=n-2; i>=1; --i)
        back[i]=max(back[i], back[i+1]);

    maxx=-99999999;
    for (i=2; i<=n-2; ++i)
        maxx=max(maxx, front[i]+back[i+1]);
    printf ("%d\n", maxx);

    return 0;
}
