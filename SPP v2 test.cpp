# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1000005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,n,m,MOD,T,K;
int b[NR], c[NR];
long long a[NR],S;
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t)
    {
        f>>K;  memset (a, 0, sizeof(a));
        for (i=1; i<=K; ++i) f>>a[i];
        for (i=1; i<=K; ++i) f>>c[i];

        f>>n>>m>>MOD;

        for (i=K+1; i<=m; ++i)
            for (j=1; j<=K; ++j) {
                a[i]+=1LL*a[i-j]*c[j];
                a[i]%=MOD;
            }
        S=0;
        for (int i=n; i<=m; ++i)
            {S+=a[i]; S%=MOD;}
        g<<S<<"\n";
    }



    return 0;
}
