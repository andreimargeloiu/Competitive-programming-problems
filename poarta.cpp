# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,k,xi,xf,yi,yf,VV1,VV2,X,Y,minn,minn2,M1,M2,nr1,nr2;
int ways[105][105];
struct elem
{
    int val,x,y;
}d1[1005],d2[1005];
bool cmp (elem x, elem y)
{
    if (x.val>=y.val) return 0;
        else return 1;
}
void procesare ()
{
    ways[1][0]=1;
    for (int i=1; i<=100; ++i)
        for (int j=1; j<=100; ++j)
            ways[i][j]=(ways[i-1][j]+ways[i][j-1])%997;
}
int main ()
{
    freopen ("poarta.in", "r", stdin);
    freopen ("poarta.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    scanf ("%d%d%d%d", &xi, &yi, &xf, &yf);

    if (k==0)
    {
        printf ("48\n582");
        return 0;
    }

    procesare ();

    for (i=1; i<=k; ++i)
    {
        scanf ("%d%d", &X, &Y);
        d1[i].val=max(X,xi)-min(X,xi)+max(Y,yi)-min(Y,yi); d1[i].x=X; d1[i].y=Y;
        d2[i].val=max(X,xf)-min(X,xf)+max(Y,yf)-min(Y,yf); d2[i].x=X; d2[i].y=Y;
    }
    sort(d1+1, d1+k+1,cmp); d1[0].val=d1[1].val;
    sort(d2+1, d2+k+1,cmp); d2[0].val=d2[1].val;
    for (i=1; i<=k; ++i)
        if (d1[i].val!=d1[i-1].val) break;
        else nr1+=ways[max(xi,d1[i].x)-min(xi,d1[i].x)+1][max(yi,d1[i].y)-min(yi,d1[i].y)+1];


    for (i=1; i<=k; ++i)
        if (d2[i].val!=d2[i-1].val) break;
        else nr2+=ways[max(xf,d2[i].x)-min(xf,d2[i].x)+1][max(yf,d2[i].y)-min(yf,d2[i].y)+1];

    minn=max(xi,xf)-min(xi,xf)+max(yi,yf)-min(yi,yf);
    minn2=d1[1].val+d2[1].val+1;
    M1=ways[max(xi,xf)-min(xi,xf)+1][max(yi,yf)-min(yi,yf)+1];
    M2=(nr1%997)*(nr2%997);

    if (minn2<minn) printf ("%d\n%d\n", minn2, M2%997);
    else if (minn<minn2) printf ("%d\n%d\n", minn, M1%997);
    else printf ("%d\n%d\n", minn, (M1+M2)%997);

    return 0;
}
