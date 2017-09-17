# include <fstream>
# include <algorithm>
# define NR 30
using namespace std;
ifstream f("grazing.in");
ofstream g("grazing.out");
int i,j,n,m;
unsigned  long long P[NR], dp[NR], var;
void permutari () {
    P[0]=1;
    for (int i=1; i<=n; ++i)
        P[i]=P[i-1] * (i);
}
unsigned long long A (int n, int k) {
    return P[n] / P[n-k];
}
int main ()
{
    f>>n; permutari ();
    dp[0]=1;
    for (i=1; i<=n; ++i) {
        dp[i]=dp[i-1]; // nod izolat

        var=0;
        for (j=2; j<=i; ++j) // lanturi
            var=var + j * A(i-1, j-1) * dp[i-j];

        for (j=3; j<=i; ++j) // cicluri
            if (j%3!=0) var=var + A(i-1, j-1) * dp[i-j];

        dp[i]=dp[i] + var/2;
        g<<i<<": "<<dp[i]<<"\n";
    }
    //g<<dp[n]<<"\n";

    return 0;
}
