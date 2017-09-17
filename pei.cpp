# include <cstdio>
# include <algorithm>
# define NR 255
# define inf -999999999
using namespace std;
int i,j,n,m,i1,i2,maxx,nrsol,x,ant,nrant,S,VV;
int a[NR][NR], s[NR][NR];
int main ()
{
    freopen ("peri.in", "r", stdin);
    freopen ("peri.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            scanf ("%d", &x);
            if (x==0) a[i][j]=-1;
                 else a[i][j]=1;
        }
    for (j=1; j<=m; ++j) //sume partiale pe coloane
        for (i=1; i<=n; ++i)
            s[i][j]=s[i-1][j] + a[i][j];


    maxx=inf;
    for (i1=1; i1<=n; ++i1)
        for (i2=i1+1; i2<=n; ++i2)
        {
            S=s[i2][1] - s[i1-1][1]; ant=S; nrant=1;

            for (j=2; j<=m; ++j)
            {
                S=s[i2][j] - s[i1-1][j];

                int Sact=S+ant;

                if (Sact>maxx) maxx=Sact, nrsol=nrant;
                     else if (Sact==maxx) nrsol+=nrant;

                ant+=a[i1][j]; if (i2>i1) ant+=a[i2][j];

                if (S>ant) ant=S, nrant=1;
                else if (S==ant) ++nrant;
            }
        }
    printf ("%d %d\n", maxx, nrsol);

    return 0;
}
