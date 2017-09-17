# include <bits/stdc++.h>
# define NR 10005
# define MOD 10007
using namespace std;
ifstream f("desc2.in");
ofstream g("desc2.out");
vector <int> dp[NR];
int i,j,n,m,x,y,K;
int main ()
{
    f>>n>>K>>x;

    n=n - 1LL*K*(K-1)*x/2;

    // dp[i][j] - numarul de moduri de a face suma i din j numere
    // dp[i][j] = dp[i-1][j-1] + dp[i-j][j]
    // dp[i][1]=1;
    dp[0].resize(K+2);
    for (i=1; i<=n; ++i) {
        dp[i].resize(K+2);
        dp[i][1]=1;
        if (i<=K) dp[i][i]=1;
        for (j=2; j<=min(i, K); ++j)
            dp[i][j]=(dp[i-1][j-1] + dp[i-j][j])%MOD;
    }
    g<<dp[n][K]<<"\n";

    return 0;
}
