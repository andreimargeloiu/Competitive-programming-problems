# include <fstream>
using namespace std;
ifstream f("color.in");
ofstream g("color.out");
int i,j,m,x,y,R[10000];
long long VV, var, n;
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        ++R[x]; ++R[y];
    }
    VV=n*(n-1)*(n-2)/6;
    for (i=1; i<=n; ++i)
        var=var+R[i]*(n-1-R[i]);
    g<<VV-var/2<<"\n";
    return 0;
}
