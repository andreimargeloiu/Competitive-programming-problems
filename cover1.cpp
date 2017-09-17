# include <fstream>
# define MOD 10003
# define maxx 600000000
using namespace std;
ifstream f("cover1.in");
ofstream g("cover1.out");
int n,p,a;
int main ()
{
    f>>n; p=1; a=3; --n;
    while (n)
    {
        if (n%2==1) p=(p*a)%MOD,--n;
        else a=(a*a)%MOD,n=n/2;
    }

    g<<(2*p)%MOD;

    return 0;
}
