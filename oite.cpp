# include <fstream>
# include <vector>
# include <algorithm>
# define mod 666013
# define NR 1050
using namespace std;
ifstream f("oite.in");
ofstream g("oite.out");
struct elem
{
    int nr, ap;
}E;
vector <elem> HASH[mod+5];
int i,j,n,m,S,nrsol,code,ok,k,L,wanted;
int a[NR];
int main ()
{
    f>>n>>L;
    for (i=1; i<=n; ++i)
        f>>a[i];

    for (i=2; i<n; ++i)
    {
        for (j=i+1; j<=n; ++j)
        {
            S=a[i]+a[j];
            if (S>L) continue;

            wanted=L-S; code=wanted%mod;
            for (k=0; k<HASH[code].size(); ++k)
                if (HASH[code][k].nr==wanted)
                {
                    nrsol+=HASH[code][k].ap;
                    break;
                }
        }

        for (j=i-1; j>=1; --j)
        {
            S=a[i]+a[j]; code=S%mod;
            if (S>L) continue;

            ok=1;
            for (k=0; k<HASH[code].size(); ++k)
                if (HASH[code][k].nr==S)
                {
                    ++HASH[code][k].ap;
                    ok=0;
                    break;
                }
            if (ok)
            {
                E.nr=S; E.ap=1;
                HASH[code].push_back(E);
            }
        }
    }
    g<<nrsol<<"\n";

    return 0;
}
