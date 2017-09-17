# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,x,y,D,k,r,o;
short unu[500][500],doi[500][500],u[500],d[500];//unu[scanduri][desene]
void adunare(int k)
{
    int i,t=0;
    //adun unu[k] si doi[k-1]
    d[k]=max(u[k],d[k-1]);
    for (i=1; i<=d[k]; ++i)
    {
        t=unu[k][i]+doi[k-1][i]+t;
        doi[k][i]=t%10;
        t=t/10;
    }
    while (t) doi[k][++d[k]]=t%10, t=t/10;
}
int main ()
{
    freopen ("expozitie.in", "r", stdin);
    freopen ("expozitie.out", "w", stdout);
    scanf ("%d%d%d", &n, &D, &k);
    r=n-D*k;
    if (r<0) {printf ("0\n"); return 0;}
    if (r==0) {printf ("1\n"); return 0;}
    for (i=1; i<=D; ++i)//avem o scandura
        unu[i][++u[i]]=i;
    for (i=2; i<=r; ++i)//scandura
    {
        doi[1][++d[1]]=1;//avem doar un desen pe i scaduri
        for (j=2; j<=D; ++j)//desene
        {
            //a[i][j]=a[i-1][j]+a[i][j-1]
            adunare(j);
        }
        //copiez
        for (j=1; j<=D; ++j)
        {
            for (o=1; o<=d[j]; ++o)
            {
                unu[j][o]=doi[j][o];
                          doi[j][o]=0;
            }
            u[j]=d[j]; d[j]=0;
        }
    }
    //afisare
    for (i=u[D]; i>=1; --i)
        printf ("%d", unu[D][i]);
    printf ("\n");

    return 0;
}
