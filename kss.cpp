# include <bits/stdc++.h>
# define NR 1005
# define sigma 26
using namespace std;
ifstream f("kss.in");
ofstream g("kss.out");
int I,n,Q;
int NEXT[NR][sigma];
unsigned long long dp[NR], maxx=1e18, K, S;
char s[NR];
void dinamica () {
    unsigned long long AUX=0;
    for (int i=0; i<sigma; ++i)
        NEXT[n+1][i]=0;

    for (int i=n; i>=1; --i) {
        dp[i]=1 + AUX;
        for (int j=0; j<sigma; ++j)
            NEXT[i][j]=NEXT[i+1][j];

        AUX=AUX - dp[NEXT[i+1][s[i]-'a']] + dp[i];
        if (AUX>maxx) AUX=maxx;

        NEXT[i][s[i]-'a']=i;
    }
}
int main ()
{
    f>>Q;
    while (Q--) {
        f>>n>>K; f.get();
        f.getline(s+1, NR);

        dinamica ();

        S=0;
        for (int i=0; i<sigma && S<K; ++i)
            S+=dp[NEXT[1][i]];

        if (K>S) {
            g<<"-1\n";
            continue;
        }

        I=0;
        while (1) {
            ++I;
            for (int i=0; i<sigma; ++i) {
                if (K <= dp[NEXT[I][i]]) {
                    I=NEXT[I][i]; g<<s[I]; --K;
                    break;
                } else {
                    K-=dp[NEXT[I][i]];
                }
            }
            if (K==0) break;
        }
        g<<"\n";
    }


    return 0;
}
