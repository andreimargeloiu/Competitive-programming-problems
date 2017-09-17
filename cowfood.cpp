/* 98p :((
# include <bits/stdc++.h>
# define MOD 3210121
# define NN 25
# define KK 35
# define NR 10305
using namespace std;
ifstream f("cowfood.in");
ofstream g("cowfood.out");
int i,j,n,m,AUX,total,S,K,sol;
int current[KK], aux[NN][KK], v[NN][KK], dp[KK][NR];
void BACK (int niv, int nr) {
    if (niv==n+1) {
        if (nr==0) return;

        int sum=0;
        for (int i=1; i<=K; ++i)
            sum+=current[i];
        if (sum > S) return;

        if (nr%2==1) AUX=(AUX + dp[K][S-sum] + MOD) % MOD;
                else AUX=(AUX - dp[K][S-sum] + MOD) % MOD;

    } else {
        BACK (niv+1, nr); // nu mai adaug nimic

        //il adaug pe niv
        for (int i=1; i<=K; ++i) {
            aux[niv][i]=current[i];
            current[i]=max(current[i], v[niv][i]);
        }
        BACK (niv+1, nr+1);
        for (int i=1; i<=K; ++i)
            current[i]=aux[niv][i];
    }
}
int main ()
{
    f>>K>>S>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=K; ++j)
            f>>v[i][j];

    //dp[i][j] - in cate moduri pot pune cel mult j bile in in i cutii

    for (j=0; j<=S+1; ++j)
        dp[0][j]=1;

    for (i=0; i<=K+1; ++i) { // cutii
        for (j=0; j<=S+1; ++j) { // bile
            if (i==0 || j==0) dp[i][j]=1;
                         else dp[i][j]=(dp[i][j-1] + dp[i-1][j])%MOD;
        }
    }
    BACK (1, 0);
    sol=(dp[K][S] - AUX + MOD)%MOD;
    sol=(sol - S*K%MOD - 1) % MOD;
    g<<sol<<"\n";

    return 0;
}*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxN 22
#define maxS 10002
#define maxK 32
#define mod 3210121
using namespace std;
int n, s, k, j, dp[maxS][maxK], nb1;
int a[maxN][maxK], b[maxN][maxK], sol;
void read()
{
    int i;
    freopen("cowfood.in", "r", stdin);
    scanf("%d %d %d", &k, &s, &n);
    for (i = 0; i < n; ++ i)
        for (j = 1; j <= k; ++ j)
            scanf("%d", &a[i][j]);
}
void DP()
{
    int i;
    for (i = 0; i <= k + 1; ++ i)
        dp[0][i] = 1;
    for (j = 1; j <= s; ++ j)
    {
        for (i = 1; i <= k + 1; ++ i)
        {
            dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
            if (dp[j][i] > mod)
                dp[j][i] -= mod;
        }
    }
    sol = dp[s][k + 1] - 1 - k * s;
    if (sol < 0)
        sol += mod;
}
void back(int x)
{
    int i, sum = 0;
    if (x == n)
    {
        sum = b[x][0];
        if (sum <= s && nb1)
        {
            if (nb1 % 2)
                sol -= dp[s - sum][k + 1];
            else
                sol += dp[s - sum][k + 1];
            if (sol > mod)
                sol -= mod;
            if (sol < 0)
                sol += mod;
        }
        return ;
    }
    for (i = 1; i <= k; ++ i)
        b[x + 1][i] = b[x][i];
    b[x + 1][0] = b[x][0];
    back(x + 1);
    b[x + 1][0] = 0;
    for (i = 1; i <= k; ++i)
    {
        b[x + 1][i] = max(b[x][i], a[x][i]);
        b[x + 1][0] += b[x + 1][i];
    }
    ++ nb1;
    back(x + 1);
    -- nb1;
}

void solve()
{
    DP();
    back(0);
}
void write()
{
    freopen("cowfood.out", "w", stdout);
    printf("%d", sol);
}
int main()
{
    read();
    solve();
    write();
    return 0;
}
