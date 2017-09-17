# include <fstream>
# include <algorithm>
# include <vector>
# define mod 666013
# define NR 3005
using namespace std;
ifstream f("bete2.in");
ofstream g("bete2.out");
vector <int> HASH[mod];
int i,j,n,m,x,y,S,k,VV;
int a[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i]; k=a[i]%mod;
        HASH[k].push_back(a[i]);
    }
    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
        {
            S=a[i]+a[j]; k=S%mod;
            if (find(HASH[k].begin(), HASH[k].end(), S) != HASH[k].end()) ++VV;
        }
    g<<VV<<"\n";

    return 0;
}
