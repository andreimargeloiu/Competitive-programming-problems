# include <cstdio>
# include <algorithm>
# define NR 250005
# define Z 1000
using namespace std;
struct elem
{
    int x, y;
}E, a[NR];
bool cmp (elem x, elem y)
{
    if (x.x>y.x) return 0;
        else if (x.x==y.x && x.y>=y.y) return 0;
            else return 1;
}
int i,j,n,m,maxx,VV,x,y,yes,nr1,nr2,nr3,nr4,marcate;
int apx[2005], apy[2005], ap[NR];
void avansare ()
{
    while (ap[VV]==1)
    {
        ++VV;
        if (VV==n+1) VV=1;
    }
}
void adaos ()
{
    ++VV;
    if (VV==n+1) VV=1;
}
int main ()
{
    freopen ("puncte6.in", "r", stdin);
    freopen ("puncte6.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d%d", &a[i].x, &a[i].y);
        ++apx[Z+a[i].x]; ++apy[Z+a[i].y];
    }
    //1
    for (i=1; i<=2*Z; ++i)
    {
        maxx=max(maxx, apx[i]);
        maxx=max(maxx, apy[i]);
    }
    printf ("%d\n", maxx);

    //2
    for (i=1; i<=n; ++i)
    {
        x=a[i].x; y=a[i].y;
        if (x==0 && y==0) {yes=1; continue;} //avem punctul 0 0
        //cadranul 1
        if (x==y && x>0) ++nr1;
        //cadranul 2
        if (x==-y && x>0) ++nr2;
        //cadranul 3
        if (x==y && x<0) ++nr3;
        //cadranul 4
        if (x==-y && x<0) ++nr4;
    }
    //numarare din cadranele 4 si 2
    long long rez=0;

    if (nr4>1 || nr2>1 || (nr4 && (yes || nr2)) || (nr2 && yes))++rez; //diag princ
    if (nr1>1 || nr3>1 || (nr1 && (yes || nr3)) || (nr3 && yes)) ++rez; //diag secundara
    rez=rez+1LL*nr4*(nr1+nr3)+1LL*nr2*(nr1+nr3);
    printf ("%lld\n", rez);

    //3
    sort (a+1, a+n+1, cmp);
    ap[1]=1; VV=2; marcate=1;
    while (marcate!=n-1)
    {
        avansare(); adaos();
        avansare(); adaos();
        avansare(); ap[VV]=1; ++marcate; adaos();
    }
    for (i=1; i<=n; ++i)
        if (ap[i]==0)
        {
            printf ("%d\n", a[i].x);
            return 0;
        }
    return 0;
}
