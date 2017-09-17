# include <fstream>
# include <algorithm>
# define NR 1000005
# define MOD 666013
# define Q 26
using namespace std;
ifstream f("cntper.in");
ofstream g("cntper.out");
int i,j,n,x,I;
int sol[NR];
long long Minus[NR];
void procesare ()
{
    I=1;
    for (i=1; i<=NR-5; ++i) {
        I=(I*Q)%MOD;
        sol[i]=(MOD + I - Minus[i]%MOD)%MOD;

        for (j=2; i*j<=NR-5; ++j) {
            Minus[i*j]+=sol[i];
        }
    }
}
int main ()
{
    procesare ();

    f>>n;
    for (i=1; i<=n; ++i) {
        f>>x;
        g<<sol[x]<<"\n";
    }

    return 0;
}
