# include <fstream>
# include <algorithm>
# define inf 999999999
# define NR 10005
using namespace std;
ifstream f("timbre.in");
ofstream g("timbre.out");
int i,j,n,m,x,y, I, minn, sol, K;
int cs[NR], ap[NR], cost[NR];
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<=m; ++i)
        f>>cs[i]>>cost[i];

    for (i=n; i>=1; i-=K)
    {
        minn=inf;
        for (j=1; j<=m; ++j)
            if (! ap[j] && cs[j]>=i && cost[j]<minn) minn=cost[j], I=j;

        sol+=minn; ap[I]=1;
    }

    g<<sol<<"\n";

    return 0;
}
