# include <fstream>
# include <algorithm>
# define NR 3000005
using namespace std;
ifstream f("sdo.in");
ofstream g("sdo.out");
int i,j,n,k;
int a[NR];
int main ()
{
    f>>n>>k;
    for (i=1; i<=n; ++i)
        f>>a[i];

    nth_element (a+1, a+k, a+n+1);
    g<<a[k]<<"\n";


    return 0;
}
