# include <cstdio>
using namespace std;
long long i,n,m,ci,cs,mij;
long long s[50005],x,maxx;
int main ()
{
    freopen ("miere.in", "r", stdin);
    freopen ("miere.out", "w", stdout);
    scanf ("%lld", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%lld", &x);
        s[i]=s[i-1]+x;
    }
    scanf ("%lld", &m);
    for(i=1; i<=m; ++i)
    {
        scanf ("%lld", &x);
        ci=1; cs=n; maxx=0;
        while (ci<=cs)
        {
            mij=(ci+cs)/2;
            if (x<s[mij]+(long long)mij*(i-1)) cs=mij-1;
                else maxx=mij, ci=mij+1;
        }
        printf ("%lld\n", maxx);
    }


    return 0;
}
