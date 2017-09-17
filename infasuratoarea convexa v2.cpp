# include <fstream>
# include <algorithm>
# include <iomanip>
# define NR 120005
using namespace std;
ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");
struct elem
{
    double x, y;
}E, a[NR];
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
double det (elem a, elem b, elem c)
{
    return (a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y -  b.x*a.y);
}

int i,j,n,m,x,y,VV,poz;
int st[NR];

void infasuratoare ()
{
    st[1]=1; st[2]=2; VV=2;
    for (i=3; i<=n; ++i)
    {
        while (VV>=2 && det (a[st[VV-1]], a[st[VV]], a[i])<0)
            --VV;
        st[++VV]=i;
    }
}
int main ()
{
    f>>n; poz=1;
    for (i=1; i<=n; ++i)
    {
        f>>a[i].x>>a[i].y;
        if (a[i].x<a[poz].x) poz=i;
        else if (a[i].x==a[poz].x && a[i].y<a[poz].y) poz=i;
    }
    swap (a[1], a[poz]);
    sort (a+2, a+n+1, cmp);

    infasuratoare ();

    g<<VV<<"\n";
    for (i=1; i<=VV; ++i)
        g<<fixed<<setprecision(6)<<a[st[i]].x<<" "<<a[st[i]].y<<"\n";


    return 0;
}
