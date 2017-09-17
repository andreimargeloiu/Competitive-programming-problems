# include <algorithm>
# include <vector>
# include <fstream>
# define NR 80005

using namespace std;
ifstream f("sccm.in");
ofstream g("sccm.out");

int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i) {
        f>>x;
        ap[x].unu=i;
        ap[x].i=i;
    }
    for (i=1; i<=m; ++i) {
        f>>x; ap2[x]=i;
    }    g<<sol<<"\n";

    return 0;
}
