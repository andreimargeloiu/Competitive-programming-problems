# include <cstdio>
# include <algorithm>
# define NR 10005
using namespace std;
struct elem
{
    double x, y;
}a[NR];
bool cmp (elem A, elem B)
{
    double dx1, dx2, dy1, dy2;
    dx1=A.x-a[1].x;
    dy1=A.y-a[1].y;

    dx2=B.x-a[1].x;
    dy2=B.y-a[1].y;

    if (dy1*dx2>=dy2*dx1) return 0;
                    else  return 1;
}
double det (elem A, elem B, elem C)
{
    return (A.x*B.y + B.x*C.y + C.x*A.y - A.x*C.y - C.x*B.y - B.x*A.y);
}
int i,j,n,m,x,y,VV,poz;
int st[NR];
void infasuratoare ()
{
    st[1]=1; st[2]=2; VV=2;
    for (int i=3; i<=n; ++i)
    {
        while (VV>1 && det (a[st[VV-1]], a[st[VV]], a[i])<=0)
            --VV;
        st[++VV]=i;
    }
}
int main ()
{
    freopen ("cetati.in", "r", stdin);
    freopen ("cetati.out", "w", stdout);
    scanf ("%d", &n); poz=1;
    for (i=1; i<=n; ++i)
    {
        scanf ("%lf%lf", &a[i].x, &a[i].y);
        if (a[i].x<a[poz].x) poz=i;
        else if (a[i].x==a[poz].x && a[i].y<=a[poz].y) poz=i;
    }
    if (poz!=1) swap (a[1], a[poz]);
    sort (a+2, a+n+1, cmp);

    infasuratoare ();

    printf ("%d\n", n-VV);

    return 0;
}
