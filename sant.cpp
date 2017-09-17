# include <cstdio>
# include <algorithm>
# define inf 999999999
using namespace std;
struct elem
{
    int sapa, pret;
}E, C[105];
int i,j,n,m,l,s,p,c,o,VV,J,nrsol;
int a[105][55], ant[105][55], sol[200];
int main ()
{
    freopen ("sant.in", "r", stdin);
    freopen ("sant.out", "w", stdout);
    scanf ("%d%d%d", &s, &n, &c);
    for (i=1; i<=c; ++i)
        scanf ("%d%d", &C[i].sapa, &C[i].pret);

    //initializare
    for (i=0; i<=s; ++i)
        for (j=0; j<=n; ++j)
            a[i][j]=inf;

    //  a[i][j]=nr de moduri de a face lungimea i folosind j oameni

    for (i=1; i<=c; ++i)
    {
        l=C[i].sapa; p=C[i].pret;
        if (! ant[l][1])
        {
            a[l][1]=p; ant[l][1]=i;
        }
    }
    for (j=2; j<=n; ++j)//fiecare numar de oameni
    {
        for (o=1; o<=c; ++o)//fiecare om nou
        {
            l=C[o].sapa; p=C[o].pret;
            for (i=C[o].sapa; i<=s; ++i)//fiecare lungime
            {
                if (a[i-l][j-1]+p<a[i][j]) a[i][j]=a[i-l][j-1]+p, ant[i][j]=o;
            }
        }
    }
    VV=s; J=n;
    while (ant[VV][J]!=0)
    {
        sol[++nrsol]=ant[VV][J];
        VV-=C[ant[VV][J]].sapa; --J;
    }
    if (a[s][n]==inf)
    {
        printf ("0\n");
        return 0;
    }
    printf ("%d\n", a[s][n]);
    sort (sol+1, sol+nrsol+1);
    for (i=1; i<=nrsol; ++i)
        printf ("%d ", sol[i]);

    return 0;
}
