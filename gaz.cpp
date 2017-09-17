# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,x,y,costL,suma,P,G,cap,minn,pret,SUPL,ant;
int g[2005],M[2005];
void citire ()
{
    scanf ("%d%d%d%d", &cap, &P, &pret, &costL);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &g[i]), G+=g[i];
}
int main ()
{
    freopen ("gaz.in", "r", stdin);
    freopen ("gaz.out", "w", stdout);

    citire ();

    for (i=1; i<=n; ++i)
    {
        minn=M[i-1]+P;
        suma=0; SUPL=0; ant=0;
        for (j=i-1; j>=1; --j)
        {
            suma+=g[j+1];//ce mai trebuie sa tinem peste noapte in plus fata de starea anteriorara

            SUPL=max(suma-cap,0)*costL+ant;
            if (M[j-1]+P+SUPL<=minn)
            {
                minn=M[j-1]+P+SUPL;
                continue;
            }
            else break;
            ant=SUPL;
        }
        M[i]=minn;
    }

    printf ("%lld\n", 1LL*M[n]+1LL*pret*G);

    return 0;
}
