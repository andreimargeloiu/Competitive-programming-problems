# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,maxx,var,n,d,VV,ci,cs,mij,ok,poz,dif,nr;
int a[200005],v[200005];
int main ()
{
    freopen ("obstacole.in", "r", stdin);
    freopen ("obstacole.out", "w", stdout);
    scanf ("%d%d", &n, &d);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);
    a[0]=1;
    for (i=1; i<=n+1; ++i)
    {
        if (a[i]!=a[i-1])
        {
            v[++VV]=var;
            var=1;
        }
        else ++var;
    }
    ci=1; cs=n;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        ok=1; poz=0; dif=0; nr=0;
        for (i=1; i<=VV && ok; ++i)
        {
            nr+=v[i];
            if (i%2==1)//ocupat
            {
                dif+=v[i];
            }
            else//liber
            {
                if (v[i]<mij) dif+=v[i];
                else poz=nr,dif=0;
            }
            if (dif>d) ok=0;
        }
        if (ok) maxx=mij,ci=mij+1;
        else cs=mij-1;
    }

    printf ("%d\n", maxx);
    return 0;
}
