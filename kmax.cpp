# include <fstream>
# include <algorithm>
# define NR 305
using namespace std;
ifstream f("kmax.in");
ofstream g("kmax.out");
int i,j,n,m,K,MOD,o,l,x;
int a[NR][NR], c[NR][NR], S[NR][NR];
void combinari ()
{
    for (i=1; i<=n; ++i) {
        c[i][0]=1; c[i][i]=1;
        for (j=1; j<i; ++j)
            c[i][j]=(c[i-1][j-1] + c[i-1][j])%MOD;
    }
}
int main ()
{
    f>>n>>K>>MOD;

    combinari ();

    //a[i][j] - numarul de permutari de i elemente care au ultimele j elemente
    //          in ordine crescatoare

    a[1][1]=1; S[1][1]=1;

    for (i=2; i<=n; ++i) { //fiecare lungime
        for (j=1; j<=min(i, K); ++j) { //fiecare lungime crescatoare de final
            a[i][j]=(a[i-1][j-1] + a[i-1][j])%MOD; //pun la inceput si final
            for (l=1; l<=i-2; ++l)
            {
                x=(S[l][min(l, K-1)] * a[i-l-1][j]) % MOD;
                x=(x * c[i-1][l]) % MOD;

                a[i][j]=(a[i][j] + x)%MOD;
            }
            S[i][j]=(S[i][j-1] + a[i][j])%MOD;
        }
    }

    g<<S[n][K]<<"\n";

    return 0;
}
