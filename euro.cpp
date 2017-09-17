# include <bits/stdc++.h>
# define NR 40005
using namespace std;
ifstream f("euro.in");
ofstream g("euro.out");
int i,j,n,m,VV,IND[NR],T,x,L,R,deq[NR];
long long suma[NR], S, dp[NR], aux;

double G(int a, int b) {
    return (double)(dp[a] - dp[b]) / (suma[a] - suma[b]);
}
int main ()
{
    f>>n>>T;
    for (i=1; i<=n; ++i) {
        f>>x;  S+=x;

        if (S<0) {
            IND[++VV]=i;
            suma[VV]=suma[VV-1] + S;
            S=0;
        }
    }
    if (IND[VV]!=n) {IND[++VV]=n; suma[VV]=suma[VV-1] + S;}

    for (i=1; i<=VV; ++i) {
        while (L < R && G(deq[L], deq[L+1]) < (double)(IND[i]))
            ++L;

        dp[i]=suma[i] * IND[i] - T;
        aux=dp[deq[L]] + (suma[i] - suma[deq[L]]) * IND[i] - T;

        dp[i]=max(dp[i], aux);

        while (L < R && G(deq[R], i) < G(deq[R-1], deq[R]))
            --R;
        deq[++R]=i;
    }
    g<<dp[VV]<<"\n";

    return 0;
}
