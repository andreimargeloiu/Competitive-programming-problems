# include <fstream>
# include <algorithm>
# define NR 200005
using namespace std;
ifstream f("heavymetal.in");
ofstream g("heavymetal.out");
struct elem
{
    int x, y;
}E, a[NR];
bool cmp (elem x, elem y)
{
    if (x.y>=y.y) return 0;
        else if (x.y==y.y && x.x>=y.x) return 0;
            else return 1;
}
int i,j,n,m,poz,sol[NR];
int cb (int x, int ci, int cs)
{
    int mij,maxx=0;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (a[mij].y<=x) ci=mij+1, maxx=mij;
                   else  cs=mij-1;
    }
    return maxx;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i].x>>a[i].y;

    sort (a+1, a+n+1, cmp);

    for (i=1; i<=n; ++i)
    {
        poz=cb (a[i].x, 1, i-1);

        sol[i]=sol[i-1];
        sol[i]=max(sol[i], sol[poz] + a[i].y-a[i].x);
    }
    g<<sol[n]<<"\n";

    return 0;
}
