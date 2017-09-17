# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 100005
# define mod 1999999973
using namespace std;
ifstream f("lgput.in");
ofstream g("lgput.out");
long long i,j,n,p,nr;
int main ()
{
    f>>n>>p;
    nr=1;
    while (p>0)
    {
        if (p%2==1) nr=nr*n%mod, --p;
        else {
                 n=n*n%mod;
                 p=p/2;
             }
    }
    g<<nr<<"\n";


    return 0;
}
