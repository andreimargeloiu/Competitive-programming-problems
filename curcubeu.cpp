# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("curcubeu.in");
ofstream g("curcubeu.out");
int i,n,x,y;
int ccc[1000005], a[1000005], b[1000005], c[1000005], urm[1000005];
void color (int minn, int maxx, int col)
{
    for (int i=minn; i<=maxx; ++i)
    {
        if (urm[i]) i=urm[i],--i;
        else {
                 ccc[i]=col;
                 urm[i]=maxx+1;
             }
    }
}
int main ()
{
    f>>n>>a[1]>>b[1]>>c[1];
    for (i=2; i<n; ++i)
    {
        a[i]=(1ll*i*a[i-1])%n;
        b[i]=(1ll*i*b[i-1])%n;
        c[i]=(1ll*i*c[i-1])%n;
    }
    for (i=n-1; i>=1; --i)
    {
        x=min(a[i],b[i]);
        y=max(a[i],b[i]);
        color (x, y, c[i]);
    }
    for (i=1; i<n; ++i)
        g<<ccc[i]<<"\n";
    return 0;
}
