# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
int i,j,n,a,k,mod;
void euclid (int a, int b, int &x, int &y)
{
    if (b==0)
    {
        x=1; y=0;
        return;
    }
    else {
             int x0, y0;
             euclid (b, a%b, x0, y0);
             x=y0;
             y=x0-(a/b)*y0;
         }
}
int main ()
{
    f>>n>>k>>mod;


    // k!
    int a=1;
    for (i=2; i<=k; ++i)
        a=a*i%mod;

    int inv1, y;
    euclid(a, mod, inv1, y);

    if (inv1<0) inv1=mod+inv1%mod;

    // (n-k)!
    a=1;
    for (i=2; i<=n-k; ++i)
        a=a*i%mod;

    int inv2;
    euclid(a, mod, inv2, y);

    if (inv2<0) inv2=mod+inv2%mod;
//................
    int comb=inv1*inv2;
    for (i=2; i<=n; ++i)
        comb=comb*i%mod;

    g<<comb<<"\n";

    return 0;
}
