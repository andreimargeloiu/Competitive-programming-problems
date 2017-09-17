# include <bits/stdc++.h>
# define NR 100005
# define MOD 30211
using namespace std;
ifstream f("carry.in");
ofstream g("carry.out");

int dp[NR][105][2];
int n,i,j,K,X,aux,sol,t;
char s[NR];
int main()
{
    f>>n>>K; f.get();
    f.getline(s+1, NR);
    X=s[n]-'0';
    dp[n][0][0]=10-X; dp[n][1][1]=X;

    if (n==1) {
        X=s[n]-'0';
        if (K==0) g<<9-X<<"\n";
             else g<<"0\n";
        return 0;
    }
    aux=1;
    for(i=n-1; i>1; --i) {
        X=s[i]-'0'; ++aux;

        for (j=0; j<=K; ++j) {
            if (j>aux) break;
            dp[i][j][0]=(dp[i+1][j][0] * (10-X) + dp[i+1][j][1] * (9-X))%MOD;

            if (j>0)
            dp[i][j][1]=(dp[i+1][j-1][0] * X + dp[i+1][j-1][1] * (X+1))%MOD;
        }
    }
    X=s[1]-'0';

    if (X!=9) {
        dp[1][K][0]=dp[2][K][0]*(9-X) + dp[2][K][1]*(8-X);
        dp[1][K][1]=dp[2][K-1][0]*X + dp[2][K-1][1]*(X+1);
    }
    else {
        dp[1][K][1]=dp[2][K-1][0]*9 + dp[2][K-1][1]*9;
    }

    g<<(dp[1][K][0] + dp[1][K][1])%MOD<<"\n";
    return 0;
}
