# include <fstream>
# include <algorithm>
# define inf 999999999
# define NR 100005
using namespace std;
ifstream f("ecluze.in");
ofstream g("ecluze.out");
int i,j,n,m;
int minn[NR], last[NR], urm[NR], a[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        minn[i]=inf;
    }

    for (i=n; i>=1; --i)
        if (last[a[i]]==0) last[a[i]]=i;
                      else urm[i]=last[a[i]], last[a[i]]=i;

    minn[1]=0;
    for (i=1; i<=n; ++i)
    {
        if (i>1) minn[i]=min(minn[i], minn[i-1]+1);
        if (urm[i]) minn[urm[i]]=min(minn[urm[i]], minn[i] + (urm[i]-i-1));
    }
    g<<minn[n]<<"\n";

    return 0;
}
