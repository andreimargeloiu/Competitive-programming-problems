# include <cstdio>
# define elem 1005
using namespace std;
int aux[elem][elem],a[elem][elem];
bool ap[elem][elem];
int i,j,n,m,q,Q,K,t,l1,c1,l2,c2,k,VV,ACT,maxx;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void fill (short l, short c)
{
    short i,lv,cv;
    ap[l][c]=1; ++ACT;
    for (i=0; i<4; ++i)
    {
        lv=l+dx[i]; cv=c+dy[i];
        if (!ap[lv][cv] && a[lv][cv]>=Q) fill(lv,cv);
    }
}
int main ()
{
    freopen ("sahara.in", "r", stdin);
    freopen ("sahara.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &m, &Q, &K);
    scanf ("%d", &t);
    //smenul lui Mars
    for (i=1; i<=t; ++i)
    {
        scanf ("%d%d%d%d%d%d", &l1, &c1, &l2, &c2, &q, &k);
        aux[l1][c1]+=q; aux[l1][c2+1]-=q;
        aux[l2+1][c1]-=q; aux[l2+1][c2+1]+=q;
    }
    //procesam matricea
    for (i=1; i<=n; ++i)
    {
        VV=0;
        for (j=1; j<=m; ++j)
        {
            aux[i][j]+=aux[i-1][j];
            VV+=aux[i][j];
            a[i][j]=VV;
        }
    }
    //facem fill-ul
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i][j]>=Q && !ap[i][j])
            {
                ACT=0;
                fill(i,j);
                if (ACT>maxx) maxx=ACT;
            }
    /*for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            printf ("%d ", a[i][j]);
        printf ("\n");
    }*/

    printf ("%d\n", maxx);

    return 0;
}
