# include <fstream>
# include <algorithm>
# define mod 1000000007
using namespace std;
ifstream f("pba.in");
ofstream g("pba.out");
int a[50005];
int sol,i,n;
long long solutie;
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];
    sort (a+1,a+n+1);
    sol=1ll*a[n]%mod*a[n-1]%mod*a[n-2]%mod;
    g<<sol<<"\n";
    return 0;
}
