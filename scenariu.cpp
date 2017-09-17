# include <fstream>
# include <algorithm>
# define MOD 666013
using namespace std;
ifstream f("scenariu.in");
ofstream g("scenariu.out");
int i,j,n,sol,S,X,x;
void euclid (int a, int b, int &x, int &y)
{
    if (b==0) {
        x=1; y=0;
        return;
    }
    int x0, y0;
    euclid (b, a%b, x0, y0);
    x=y0;
    y=x0-(a/b)*y0;
}
int main ()
{
    f>>X>>n;
    for (i=1; i<=n; ++i) {
        f>>x; S+=x;
    }

    //C[X-1][S-1]
    --X; --S;

    int sol=1;
    for (i=1; i<=X; ++i)
        sol=1LL*sol*i%MOD;

    int a=1, x, y;
    for (i=1; i<=S; ++i)
        a=1LL*a*i%MOD;
    euclid (a, MOD, x, y);
    if (x<0) x=MOD + x%MOD;
    sol=1LL*sol*x%MOD;

    a=1;
    for (i=1; i<=X-S; ++i)
        a=1LL*a*i%MOD;
    euclid (a, MOD, x, y);
    if (x<0) x=MOD + x%MOD;
    sol=1LL*sol*x%MOD;

    g<<sol<<"\n";

    return 0;
}
