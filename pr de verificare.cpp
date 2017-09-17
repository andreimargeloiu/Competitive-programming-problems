# include <fstream>
# define NR 1000005
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int i,j,n,m;
long long a[NR], b[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) f>>a[i];
    for (i=1; i<=n; ++i) f>>b[i];

    for (i=1; i<=n; ++i) {
        if (a[i]!=b[i]) g<<i<<" "<<a[i]<<" "<<b[i]<<"\n";
    }

    g<<"A\n";

    return 0;
}
