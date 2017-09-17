# include <bits/stdc++.h>
# define NR 2000005
# define P 73
# define MOD1 100007
# define MOD2 100021
using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
int i,j,n,m,la,lb,VV,k,nrsol,hash1,hash2,hashA1,hashA2,P1,P2;
int sol[1005];
char a[NR], b[NR];
int main ()
{
    f.getline (a+1, NR); la=strlen (a+1);
    f.getline (b+1, NR); lb=strlen (b+1);

    P1=1; P2=1;
    for (i=1; i<=la; ++i) {
        hashA1=(hashA1*P + a[i])%MOD1;
        hashA2=(hashA2*P + a[i])%MOD2;

        if (i!=1) {
            P1 = (P1 * P) % MOD1,
            P2 = (P2 * P) % MOD2;
        }
    }

    for (i=1; i<=lb; ++i) {
        hash1=(hash1 * P + b[i]) % MOD1;
        hash2=(hash2 * P + b[i]) % MOD2;

        if (i>=la) {
            if (hash1==hashA1 && hash2==hashA2) {
                ++nrsol;
                if (VV<1000) sol[++VV]=i-la;
            }
            hash1=(hash1 - (b[i-la+1]*P1)%MOD1 + MOD1)%MOD1;
            hash2=(hash2 - (b[i-la+1]*P2)%MOD2 + MOD2)%MOD2;
        }
    }

    g<<nrsol<<"\n";
    for (i=1; i<=min(VV, 1000); ++i)
        g<<sol[i]<<" ";
    return 0;
}
