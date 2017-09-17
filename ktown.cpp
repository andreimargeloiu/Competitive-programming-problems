# include <fstream>
# include <algorithm>
# include <vector>
# include <cmath>
# define NR 3005
using namespace std;
ifstream f("ktown.in");
ofstream g("ktown.out");
int i,j,n,m,K;
long long a[NR], var[NR], DP[NR][NR], minn;
int main ()
{
    f>>n>>K;
    for (i=1; i<=n; ++i) {
        f>>a[i];
        if (i>1) a[i]=a[i] - (1LL*(i-1)*K);
        var[i]=a[i];
    }
    sort (a+1, a+n+1);
    for (i=1; i<=n; ++i) {
        minn=INFINITY;
        for (j=1; j<=n; ++j) {
            minn=min(minn, DP[i-1][j]);
            DP[i][j]=minn + abs(a[j] - var[i]);
        }
    }
    minn=INFINITY;
    for (i=1; i<=n; ++i)
        minn=min(minn, DP[n][i]);
    g<<minn<<"\n";

    return 0;
}
