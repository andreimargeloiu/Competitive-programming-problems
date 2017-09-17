# include <fstream>
# include <algorithm>
# define NR 5005
using namespace std;
ifstream f("centre.in");
ofstream g("centre.out");
int i,j,n,m,cx,cy,S;
struct elem
{
    int x, y, dif, cere;
}a[NR];
bool cmp (elem x, elem y)
{
    if (x.dif>=y.dif) return 0;
                 else return 1;
}
int main ()
{
    f>>n>>cx>>cy;

    for (i=1; i<=n; ++i) f>>a[i].cere;
    for (i=1; i<=n; ++i) f>>a[i].x;
    for (i=1; i<=n; ++i) f>>a[i].y;

    for (i=1; i<=n; ++i)
        a[i].dif=a[i].x-a[i].y;

    sort (a+1, a+n+1, cmp);

    for (i=1; i<=n; ++i)
    {
        if (cx)
        {
            if (cx>=a[i].cere) S+=a[i].cere * a[i].x, cx-=a[i].cere;
            else {
                      S+=cx * a[i].x;
                      S+=(a[i].cere - cx) * a[i].y;

                      cy-=(a[i].cere - cx); cx=0;
                 }
        }
        else S+=a[i].cere * a[i].y, cy-=a[i].cere;
    }
    g<<S<<"\n";

    return 0;
}
