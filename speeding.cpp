#include <cstdio>
# include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 1000
using namespace std;
ifstream f("speeding.in");
ofstream g("speeding.out");
int n,m,sum1,sum2,i,j,maxx,x,y,st1,st2;
int ap1[NMAX],ap2[NMAX];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        f>>x>>y;
        for (j=1; j<=x; ++j)
            ap1[++st1]=y;
    }
    for(int i = 1; i <= m; ++i)
    {
        f>>x>>y;
        for (j=1; j<=x; ++j)
            ap2[++st2]=y;
    }
    sort(ap1+1, ap1+100+1); sort(ap2+1, ap2+100+1);

    for(int i = 1; i <= 100; ++i)
        maxx=max(ap2[i]-ap1[i], maxx);

    g<<maxx<<"\n";
    return 0;
}
