# include <fstream>
# include <algorithm>
# define NR 250005
using namespace std;
ifstream f("zlego.in");
ofstream g("zlego.out");
int i,j,n,m,o,t;
int pi[NR], H[NR];
long long cost[NR];
void procesare ()
{
    int i,j,k=0;
    long long S=0;
    //prefix
    for (i=2; i<=n; ++i)
    {
        while (k>0 && H[k+1]!=H[i])
            k=pi[k];
        if (H[k+1]==H[i]) ++k;
        pi[i]=k;
    }
    for(i=n; i>=1; --i)
        cost[pi[i]]+=cost[i];
	for(i=1; i<=n; ++i)
        g<<cost[i]<<"\n";
}
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n;
        for (i=1; i<=n; ++i)
            f>>H[i];
        for (i=1; i<=n; ++i)
            f>>cost[i];

        procesare ();
    }

    return 0;
}
