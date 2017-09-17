# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 100005
# define mod 9001
using namespace std;
ifstream f("propozitie.in");
ofstream g("propozitie.out");
int i,j,n,m,K,poz,VV;
int P[NR], sum[NR], bit[NR], nr[NR];
char s[NR];
int main ()
{
    f>>n>>K; f.get();
    f.getline (s+1, NR);
    for (i=1; i<=n; ++i)
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') bit[i]=1;
            else bit[i]=0;

    nr[1]=1; sum[1]=1;
    if (bit[1]) P[++VV]=1;
    for (i=2; i<=n; ++i)
    {
        if (bit[i]) P[++VV]=i;

        if (VV<=K) nr[i]=sum[i-1]+1;
        else {
                 poz=P[VV-K];
                 nr[i]=(nr[i-1]   +   mod+sum[i-2]-sum[poz-1])%mod;
             }

        sum[i]=(sum[i-1]+nr[i])%mod;
    }

    g<<nr[n]<<"\n";


    return 0;
}
