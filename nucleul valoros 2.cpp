# include <bits/stdc++.h>
# define NR 3005
using namespace std;
ifstream f("nucleulvaloros2.in");
ofstream g("nucleulvaloros2.out");
int i,j,n,l,ci,cs,mijST,mijDR;
int mij[NR][NR];
long long dp[NR][NR], S[NR], a[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>a[i];
        S[i]=S[i-1] + a[i];
        dp[i][i]=a[i];
    }
    for (l=2; l<=n; ++l) { // lungimea
        for (i=1; i<=n-l+1; ++i) { //capataul din stanga
            ci=i; cs=i + l - 1;
            if (ci==cs-1) { //daca e de lungime 2
                dp[ci][cs]=2*(a[ci] + a[cs]);
                mij[ci][cs]=ci;
            } else {
                mijST=mij[ci][cs-1];
                mijDR=mij[ci+1][cs];

                dp[ci][cs]=dp[ci][mijST] + dp[mijST+1][cs];
                mij[ci][cs]=mijST;

                for (j=mijST; j<=mijDR; ++j)
                    if (dp[ci][j] + dp[j+1][cs] < dp[ci][cs]) {
                        dp[ci][cs] =dp[ci][j] + dp[j+1][cs];
                        mij[ci][cs]=j;
                    }

                dp[ci][cs]+=(S[cs] - S[ci-1]);
            }
        }
    }
    /*for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j)
            g<<dp[i][j]<<" ";
        g<<"\n";
    }
    g<<"\n";
    for (i=1; i<=n; ++i)
        g<<S[i]<<" ";
    g<<"\n";*/
    g<<dp[1][n]<<"\n";

    return 0;
}
