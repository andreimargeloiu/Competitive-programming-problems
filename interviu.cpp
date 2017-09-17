# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("interviu.in");
ofstream g("interviu.out");
int i,j,maxx,x,n;
int main ()
{
    f>>n;
    for (i=1; i<=3; ++i)
    {f>>x; maxx=max(maxx, x);}

    for (i=4; i<=n; ++i)
    {
        f>>x;
        if (x>maxx) {g<<i<<"\n"; return 0;}
    }
    g<<n<<"\n";
    return 0;
}
