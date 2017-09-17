# include <cstdio>
# include <algorithm>
# define M 5005
# define N 25
# define inf 999999999
using namespace std;
struct elem
{
    int nr,poz;
}E,var[M],mat[N][M],act1,act2,ant1,ant2;
bool cmp (elem x, elem y)
{
    if (x.nr>=y.nr) return 0;
        else return 1;
}
int i,j,n,m,k,Q,VV,poz,poz2,suma,t,nrant,ant,o,q,New;
int a[N][M], din[N][M];

int cb(int x, int I)
{
    int ci,cs,mij;
    ci=1; cs=m;
    while(ci<=cs)
    {
        mij=(ci+cs)/2;
        if (x < mat[I][mij].nr) cs=mij-1;
                 else ci=mij+1;
    }
    return cs+1;
}
void procesare (elem &act)
{
     if (nrant>=1) act.nr=min(act.nr, ant1.nr+abs(ant1.poz-act.poz));
     if (nrant==2) act.nr=min(act.nr, ant2.nr+abs(ant2.poz-act.poz));
}
int main ()
{
    freopen ("mijloc.in", "r", stdin);
    freopen ("mijloc.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &Q);
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
        {
            scanf ("%d", &a[i][j]);
            E.nr=a[i][j]; E.poz=j;
            var[j]=E;
        }
        sort (var+1, var+m+1, cmp);
        for (j=1; j<=m; ++j)
            mat[i][j]=var[j];
    }
    for (o=1; o<=Q; ++o)
    {
        scanf ("%d", &q);
        ant1.nr=0; ant1.poz=(m+1)/2; nrant=1;
        for (i=1; i<=n; ++i)//pentru fiecare rand
        {
            poz=cb(q,i);//locul unde poate fi inserat
            if (mat[i][poz].nr!=q) --poz;//mergem la anteriorul

            if (poz==0 || mat[i][poz].nr!=q)//la mijloc
            {
                act1.nr=inf; act1.poz=(m+1)/2;

                procesare (act1);

                nrant=1; ant1=act1;
            }
            else {   //gasit acest numar
                     if (mat[i][poz].nr==q)//prima data
                     {
                         act1.nr=inf; act1.poz=mat[i][poz].poz;

                         procesare (act1);

                         New=1;
                     }
                     --poz;
                     if (mat[i][poz].nr==q)//a doua oara
                     {
                         act2.nr=inf; act2.poz=mat[i][poz].poz;

                         procesare (act2);

                         New=2; ant2=act2;
                     }
                     nrant=New; ant1=act1;
                 }
        }
        act1.nr=inf; act1.poz=(m+1)/2;
        procesare (act1);

        printf ("%d\n", act1.nr);
    }

    return 0;
}
