# include <fstream>
# include <algorithm>
# define mod 1000000007
using namespace std;
ifstream f("permtr.in");
ofstream g("permtr.out");
int i,j,n,K;
long long nr;
int main ()
{
    f>>K;
    nr=1; n=(K+1)*K/2;
    for (i=K; i>=1; --i)
    {
        nr=nr*i%mod;
        for (j=n-1; j>=n-i+1; --j)
        {
            if (j==0) continue;
            nr=nr*j%mod;
        }
        n=n-i;
    }
    g<<nr<<"\n";
    return 0;
}
