# include <cstdio>
using namespace std;
int i,j,n,m,t,apmaj,maj,x,VV;
int V[20];
int main ()
{
    freopen ("avarcolaci.in", "r", stdin);
    freopen ("avarcolaci.out", "w", stdout);
    scanf ("%d", &t);
    for (i=1; i<=t; ++i)
    {
        scanf ("%d", &n);
        maj=0; apmaj=0;
        for (j=1; j<=2*n; ++j)
        {
            scanf ("%d", &x);
            if (x==maj) ++apmaj;
            else {
                     if (apmaj==0) apmaj=1, maj=x;
                     else --apmaj;
                 }
            V[i]=maj;
        }
    }
    fclose(stdin);
    freopen ("avarcolaci.in", "r", stdin);
    scanf ("%d", &t);
    for (i=1; i<=t; ++i)
    {
        scanf ("%d", &n); VV=0;
        for (j=1; j<=2*n; ++j)
        {
            scanf ("%d", &x);
            if (x==V[i]) ++VV;
        }
        if (VV>=n+1) printf ("%d\n", V[i]);
            else printf ("Mozart\n");
    }
    return 0;
}
