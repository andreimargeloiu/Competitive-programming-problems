# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("turneu.in");
ofstream g("turneu.out");
int i,j,n,m,y,T,ok;
long double S, Sreal, x;
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t) {
        f>>n; ok=1; Sreal=0;

        for (i=1; i<=n; ++i) {
            f>>x; Sreal+=x;
            if (x > n-1) ok=0;
            if (1LL*(i-1)*(i)/2 > Sreal) ok=0;
        }
        if (Sreal != 1LL*1.0*(n)*(n-1)/2) ok=0;
        if (n==1) ok=0;

        if (ok) g<<"YES\n";
           else g<<"NO\n";
    }

    return 0;
}
