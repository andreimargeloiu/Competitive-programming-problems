# include <fstream>
# include <algorithm>
# include <bitset>
using namespace std;
ifstream f("spion.in");
ofstream g("spion.out");
bitset <50000005> ap;
int i,n,x,s,d,grupuri;
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>x>>s>>d;
        grupuri=grupuri+1-ap[s]-ap[d];
        ap[x]=1;
        g<<grupuri<<"\n";
    }



    return 0;
}
