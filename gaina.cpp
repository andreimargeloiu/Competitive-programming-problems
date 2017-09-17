# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,VV,minn,var;
int h[10005],ok[10005];
int main ()
{
    freopen ("gaina.in", "r", stdin);
    freopen ("gaina.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &h[i]);
        ok[i]=1;
    }
    h[n+1]=-1;
    for (i=n; i>=1; --i)
    {
        if (h[i]<h[i+1])
        {
            h[i]=h[i+1];
            ok[i]=0;
        }
    }
    for (i=1; i<n; ++i)
    {
        //daca sunt egale initial
        if (h[i]==h[i+1] && ok[i] && ok[i+1]) continue;
        //daca trb sa sar
        ++i;
        if (!ok[i])
        {
            --VV; minn=min(VV,minn); ++VV;
            VV=VV+h[i-1]-h[i];
            while (!ok[i])
            {
                --VV;
                ++i;
            }
            --i;
            minn=min(VV,minn);
        }
        else
        {
            --VV;
            minn=min(VV,minn);
            VV=VV+h[i-1]-h[i];
        }
    }
    printf ("%d\n", -minn);
    return 0;
}
