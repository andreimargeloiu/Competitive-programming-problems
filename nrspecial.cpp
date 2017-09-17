# include <algorithm>
# include <fstream>
# define NR 60005
using namespace std;
ifstream f("nspecial.in");
ofstream g("nspecial.out");
int i,j,n,m;
int a[NR];
int main ()
{
    f>>n;
    for (i=2; i<=n+1; ++i) {
        ++a[i];
        for (j=2; i*j<=n+1; ++j)
            a[i*j]+=a[i];
    }

    g<<a[n+1]<<"\n";



    return 0;
}
