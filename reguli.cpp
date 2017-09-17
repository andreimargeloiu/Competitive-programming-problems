# include <fstream>
# include <algorithm>
# define NR 500005
using namespace std;
ifstream f("reguli.in");
ofstream g("reguli.out");
long long i,j,n,ant,x,VV,q;
long long a[NR],pi[NR];
int main ()
{
    int i,VV=0;
    f>>n; f>>ant;
    for (i=2; i<=n; ++i)
    {
        f>>x;
        a[++VV]=x-ant;
        ant=x;
    }

    for (i=2; i<=VV; ++i)
    {
        while (q && a[i]!=a[q+1])
            q=pi[q];

        if (a[i]==a[q+1]) ++q;
        pi[i]=q;
    }
    g<<VV-pi[VV]<<"\n";
    for (i=1; i<=VV-pi[VV]; ++i)
        g<<a[i]<<"\n";


    return 0;
}
