# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 200005
# define MOD 1000000007
using namespace std;
ifstream f("produse.in");
ofstream g("produse.out");
int i,j,n,m,x,y,o,D,nrsol,maxx,I;
int ap[NR], sol[NR], F;
int main ()
{
    f>>n>>D;
    for (i=1; i<=n; ++i) {
        f>>x;
        ++ap[x];
    }

    //fac pentru 1
    for (i=1; i<=n; ++i)
        if (ap[i]) {
            x=i;
            for (j=1; j<=ap[i]; ++j) {
                if (j>1) x=x*i%MOD;
                if (x>D) break;
                I=j;
            }
            for (j=2; j<=I; ++j)
                x=x*i;

            //factorialul initial
            if (I!=ap[i]) {
                F=ap[i];
                for (j=ap[i]-1; j>I; --j)
                    F=1ll*F*j%MOD;
            }
            else F=1;

            for (j=I; j>=1; --j) {
                F=1ll*F*j%MOD;
                maxx=(D/x) * x;
                for (o=maxx; o>=1; o-=x) {
                    sol[o]+=(1LL * sol[o/x] * F%MOD);
                    if (sol[o] >= MOD) sol[o]-=MOD;
                }
            }
        }
    for (i=2; i<=n; ++i)
        nrsol=(nrsol + sol[i])%MOD;
    g<<nrsol<<"\n";

    return 0;
}
