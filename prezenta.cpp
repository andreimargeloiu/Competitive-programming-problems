# include <bits/stdc++.h>
# define NR 155
# define MOD 10007
using namespace std;
ifstream f("prezenta.in");
ofstream g("prezenta.out");
int i,j,n,m,K,T;
int a[NR][NR];
int main ()
{
    f>>T;
    // a[i][j] - numarul de permutari de lungime i cu j subsiruri crescatoare
    while (T--) {
        f>>n>>K;
        a[1][1]=1;
        for (i=2; i<=n; ++i) {
            memset (a[i], 0, sizeof(a[i]));
            for (j=1; j<=min(i, K+1); ++j) {
                a[i][j]=j*(a[i-1][j]) + (i-j+1)*(a[i-1][j-1]);
                a[i][j]%=MOD;
            }
        }
        g<<a[n][K+1]<<"\n";
    }


    return 0;
}
