# include <fstream>
# include <algorithm>
# include <vector>
# define MOD 9901
# define NR 600
using namespace std;
ifstream f("culori.in");
ofstream g("culori.out");
int i,j,n,m,len,dist,k;
int a[NR], dp[NR][NR];
int main ()
{
    f>>n; len=2*n-1;
    for (i=1; i<=2*n-1; ++i)
        f>>a[i];

    for (i=1; i<=len; ++i) dp[i][i]=1;

    for (dist=1; dist<len; ++dist) {
        for (i=1; i<=len-dist; ++i) {
            j=i+dist;

            if ((j-i)%2==1 || a[i]!=a[j]) continue;

            for (k=i+1; k<=j; ++k) {
                if (dp[i+1][k] && dp[k+1][j])
                    dp[i][j]=(dp[i][j]+(dp[i+1][k]*dp[k+1][j]))%9901;
            }
        }
    }
    g<<dp[1][len]<<"\n";

    return 0;
}
