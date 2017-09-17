# include <fstream>
# include <algorithm>
# define NR 100005
using namespace std;
ifstream f("grupuri.in");
ofstream g("grupuri.out");
int i,j,n,m;
int a[NR];
long long ci,cs,mij,S,sol,K;
bool verificare (long long G)
{
    long long c=1, l=0;
    for (int i=1; i<=n; ++i)
    {
        l+=min(1LL*a[i], G);
        if (l>G) ++c, l=l-G;
    }
    if (c==K && l==G || c>K) return 1;
                        else return 0;
}
int main ()
{
    f>>K>>n;
    for (i=1; i<=n; ++i)
        {f>>a[i]; S+=a[i];}

    ci=0; cs=S/K;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;

        if (verificare (mij)) sol=mij, ci=mij+1;
                         else cs=mij-1;
    }
    g<<sol<<"\n";

    return 0;
}
