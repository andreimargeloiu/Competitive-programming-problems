# include <fstream>
# include <algorithm>
# include <cstring>
# include <bitset>
# define NR 6005
# define N_Max 35005
using namespace std;
ifstream f("per.in");
ofstream g("per.out");
bitset <N_Max+5> ap;
int i,j,n,m,P,lmax,l,K,nou,act,nrsol;
int prim[NR], DP[NR], cod1[3][NR], cod2[3][NR];
char s[NR];
void prime () {
    for (i=2; i<=N_Max; ++i) {
        if (! ap[i]) {
            prim[++P]=i;
            for (j=2; i*j<=N_Max; ++j)
                ap[i*j]=1;
        }
    }
}
bool verificare (int ci, int cs, int l) {
    for (int i=0; i<l; ++i)
        if (s[ci-i] != s[cs-i]) return 0;

    return 1;
}
int main ()
{
    prime ();

    f>>n>>K; f.get();
    f.getline (s+1, NR);

    lmax=n/K;

    for (l=1; l<=lmax; ++l) {
        // fac codurile de hash
        nou=1-act;

        memset (DP, 0, sizeof(DP));
        for (i=l; i<=n; ++i) {
            cod1[nou][i]=cod1[act][i-1] + (s[i]-'a'+1)*prim[l];
            cod2[nou][i]=cod2[act][i-1] + (s[i]-'a'+1)*(1<<(l-1));
        }

        for (i=l; i<=n; ++i) {
            DP[i]=1;
            if (cod1[nou][i]==cod1[nou][i-l] && cod2[nou][i]==cod2[nou][i-l]) {
                //if (verificare (i-l, i, l))
                DP[i]+=DP[i-l];
            }
            if (DP[i]>=K) ++nrsol;
        }

        act=nou;
    }
    g<<nrsol<<"\n";


    return 0;
}
