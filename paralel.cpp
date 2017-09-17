# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("paralel.in");
ofstream g("paralel.out");
struct elem
{
    short x,y;
}a[1000];
int cmp (elem x, elem y)
{
    if (x.x==y.x) return x.y<y.y;
    else return x.x<y.x;
}
int i,j,n,VV,nrsol,nr;
int mij[250005];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i].x>>a[i].y;
    sort (a+1, a+n+1, cmp);

    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
        {
            mij[++VV]=(a[i].x+a[j].x)*1001+a[i].y+a[j].y;
        }
    sort (mij+1, mij+VV+1);
    i=1;
    for (i=1; i<=VV+1; ++i)
    {
        if (mij[i]==mij[i-1]) ++nr;
        else
        {
            nrsol+=nr*(nr-1)/2;
            nr=1;
        }
    }
    g<<nrsol<<"\n";
    return 0;
}
