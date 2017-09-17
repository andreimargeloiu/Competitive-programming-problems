# include <fstream>
using namespace std;
ifstream f("elmaj.in");
ofstream g("elmaj.out");
int i,j,n,m,VV,maj,apmaj;
int a[1000005];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        if (a[i]==maj) ++apmaj;
        else {
                 if (apmaj==0) apmaj=1, maj=a[i];
                 else --apmaj;
             }
    }
    for (i=1; i<=n; ++i)
        if (a[i]==maj) ++VV;

    if (VV>=(n+1)/2) g<<maj<<" "<<VV<<"\n";
        else g<<"-1\n";
    return 0;
}
