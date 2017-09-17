# include  <cstdio>
# include <algorithm>
# define NR 10005
using namespace std;
int i,j,n,rafturi,x,y;
int maxx[NR], minn[NR];
int main ()
{
    freopen ("rafturi.in", "r", stdin);
    freopen ("rafturi.out", "w", stdout);
    scanf ("%d%d", &rafturi, &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d%d", &x, &y);
        maxx[x]=max(maxx[x], y);
    }
    for (i=1; i<=rafturi; ++i)
    {
        minn[i]=minn[i-1]+maxx[i];
        if (i>=2) minn[i]=min(minn[i], minn[i-2]+max(maxx[i], maxx[i-1]));
        if (i>=3) minn[i]=min(minn[i], minn[i-3]+max(maxx[i], max(maxx[i-1], maxx[i-2])));
    }
    printf ("%d\n", minn[rafturi]);

    return 0;
}
