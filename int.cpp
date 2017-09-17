# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("int.in");
ofstream g("int.out");
int i,j,n,m,x,y,maxx,VV;
struct elem
{
    int x,y;
}v[50005];
bool cmp (elem x, elem y)
{
    if (x.y>y.y) return 0;
        else if (x.y==y.y && x.x>=y.x) return 0;
            else return 1;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>v[i].x>>v[i].y;

    sort (v+1, v+n+1, cmp);

    maxx=-999999999; VV=0;
    for (i=1; i<=n; ++i)
    {
        if (v[i].x>=maxx) maxx=v[i].y, ++VV;
    }
    g<<VV<<"\n";
    return 0;

}
