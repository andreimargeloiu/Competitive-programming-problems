# include <bits/stdc++.h>
# include <algorithm>
# define INF 999999999
# define NR 13
using namespace std;
ifstream f("cast.in");
ofstream g("cast.out");
int i,j,n,m,S,S1,T;
int DP[NR][1<<NR], cost[NR][NR];
int main ()
{
    f>>T;
    while (T--) {
        f>>n;
        for (i=0; i<n; ++i)
            for (j=0; j<n; ++j)
                f>>cost[i][j];

        for (i=0; i<n; ++i) {
            for (j=0; j<(1<<n); ++j)
                DP[i][j]=INF;
            DP[i][1<<i]=0;
        }

        for (S=1; S<(1<<n); ++S) // starea
            for (i=0; i<n; ++i)  //radacina
                if ((1<<i) & S)
                    for (S1=S-(1<<i); S1!=0; S1=(S1-1) & (S-(1<<i)))  //alta stare
                        for (j=0; j<n; ++j)
                            if ((1<<j) & S1)
                                DP[i][S]=min(DP[i][S], cost[i][j] + max(DP[i][S - S1], DP[j][S1]));

        g<<DP[0][(1<<n)-1]<<"\n";
    }

    return 0;
}
