# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("farfurii.in");
ofstream g("farfurii.out");
int i,j,n,k,t,T;
int timp[10005], a[10005], b[10005], reper[10005];
int main ()
{
    f>>n>>t;
    for (i=1; i<=n; ++i)
        f>>timp[i];
    for (k=1; k<=n; ++k)
    {
        for (i=1; i<=t; ++i)
        {
            if (i>=timp[k]+(k-1)) b[i]=max(a[i-1], a[i-timp[k]]+1);
                else b[i]=a[i-1];
            reper[i]=max(reper[i], b[i]);
        }

        for (i=1; i<=t; ++i)
        {
            a[i]=b[i];
            b[i]=0;
        }
    }
    for (i=1; i<=t; ++i)
        if (reper[i]==reper[t]) break;
    g<<reper[t]<<" "<<i<<"\n";

    return 0;
}
