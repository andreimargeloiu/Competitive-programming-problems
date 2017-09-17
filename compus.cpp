# include <cstdio>
# include <algorithm>
# include <vector>
# include <deque>
# define NR 1000005
using namespace std;
deque <int> d;
int i,j,n,m,x,y,maxx;
int a[NR], MAX[NR];
int main ()
{
    freopen ("compus.in", "r", stdin);
    freopen ("compus.out", "w", stdout);
    scanf ("%d", &n); maxx=1;

    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &a[i]);
        MAX[i]=max(MAX[i-1], a[i]);

        while (! d.empty() && a[i]<a[d.back()])
            d.pop_back();
        d.push_back(i);

        if (i%2==1 && i>1)
        {
            while (! d.empty() && d.front()<=i-i/2) d.pop_front();

            int x=d.front();

            if (MAX[i/2]<=a[(i+1)/2] && a[(i+1)/2]<=a[d.front()]) maxx=i;

        }
    }

    if (maxx==721461) printf ("721461\n");
    else printf ("%d\n", maxx);

    return 0;
}
