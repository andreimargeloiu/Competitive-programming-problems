# include <fstream>
using namespace std;
ifstream f("t.in");
ofstream g("t.out");
int n,m,i;
int main ()
{
    f>>n>>m;
    g<<n<<" "<<m<<" "<<"\n";
    for (i=1; i<=n; ++i)
        g<<i<<" ";
    g<<"\n";

    for (i=1; i<=m; ++i)
        g<<i<<" ";
    g<<"\n";


    return 0;
}
