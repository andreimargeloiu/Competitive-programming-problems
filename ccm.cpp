# include <bits/stdc++.h>
# define NR 16
# define MOD 9901
using namespace std;
ifstream f("ccm.in");
ofstream g("ccm.out");
vector <int> v[NR];
int i,j,n,m,mask,maxx,maxBiti,L,R,x,y,act,nou;
int dp[3][1<<NR];
int biti (int K) {
    int sol=0;
    while (K) {
        K=K - (K&(-K));
        ++sol;
    }
    return sol;
}
int main ()
{
    f>>L>>R>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y; --x; --y;
        v[x].push_back(y);
    }
    dp[0][0]=1; act=0; nou=1;
    for (i=0; i<L; ++i) {
        memset (dp[nou], 0, sizeof(dp[nou]));
        for (auto &x: v[i]) { //pentru fiecare muchei pe care o pot pune
                              //vreau sa o adaug in starile in care nu e luat corespondentul
            for (mask=1; mask<=(1<<R)-1; ++mask) {
                if ((1<<x) & mask) dp[nou][mask]=(dp[nou][mask] + dp[act][mask - (1<<x)])%MOD;
            }
        }
        for (int mask=0; mask<=(1<<R)-1; ++mask)
            dp[nou][mask]=(dp[nou][mask] + dp[act][mask])%MOD;
        swap(act, nou);
    }
    for (mask=1; mask<=(1<<R)-1; ++mask) {
        if (! dp[act][mask]) continue;
        if (biti(mask) > maxBiti) maxBiti=biti(mask), maxx=dp[act][mask];
        else if (biti(mask)==maxBiti) maxx=(maxx + dp[act][mask])%MOD;

    }
    g<<maxBiti<<" "<<maxx<<"\n";

    return 0;
}
