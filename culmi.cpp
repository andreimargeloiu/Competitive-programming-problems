# include <cstdio>
using namespace std;
int i,j,n,m,x,VV;
int st[10005];
int main ()
{
    freopen ("culmi.in", "r", stdin);
    freopen ("culmi.out", "w", stdout);

    scanf ("%d", &n);
    st[0]=999999999;
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &x);
        if (x<=st[VV]) {st[++VV]=x; continue;}
        for (j=VV; j>=1; --j)
            if (x<=st[j-1])
            {
                st[j]=x;
                break;
            }
    }
    printf ("%d\n", VV);

    return 0;
}
