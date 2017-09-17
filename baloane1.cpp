# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("baloane.in");
ofstream g("baloane.out");
int i,j,n,m,VV;
int maxx,x,r;
struct elem
{
    int x,y;
}v[100005];
bool cmp (elem x, elem y)
{
    if (x.x>y.x) return 0;
    else if (x.x==y.x && x.y>=y.y) return 0;
    else return 1;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>x>>r;
        v[i].x=x-r; v[i].y=x+r;
    }
    sort (v+1, v+n+1, cmp);
    maxx=v[1].y; VV=1;
    for (i=2; i<=n; ++i)
    {
        if (v[i].x<maxx)
        {
            maxx=min(maxx,v[i].y);
        }
        else ++VV, maxx=v[i].y;
    }
    g<<VV<<"\n";

    return 0;
}
