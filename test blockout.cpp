# include <fstream>
# include <algorithm>
# define NR 15005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,n,m,a[NR], b[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];
    for (i=1; i<=n; ++i)
    {
        f>>b[i];
        if (a[i]!=b[i]) g<<i<<" "<<a[i]<<" "<<b[i]<<"\n";
    }
    return 0;
}
