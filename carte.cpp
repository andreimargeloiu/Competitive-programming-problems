# include <fstream>
# include <cstring>
# include <algorithm>
# include <bitset>
# define NR 3005
using namespace std;
ifstream f("carte.in");
ofstream g("carte.out");
int i,j,n,m,l,c,k,T;
short DP[NR], pi[NR], L[NR];
char s[NR], cuv[NR];
bitset <1005> ap[NR];
int main ()
{
    f>>T; f.get();
    for (int t=1; t<=T; ++t) {
        f.getline (s+1, NR); l=strlen(s+1);
        f>>n; f.get();
        for (i=1; i<=n; ++i) {
            f.getline (cuv+1, NR); c=strlen(cuv+1); L[i]=c;

            memset (pi, 0, sizeof(pi)); k=0;
            for (j=2; j<=c; ++j) {
                while (k>0 && cuv[k+1]!=cuv[j])
                    k=pi[k];
                if (cuv[k+1]==cuv[j]) ++k;
                pi[j]=k;
            }
            k=0;
            for (j=1; j<=l; ++j) {
                ap[j][i]=0;
                while (k>0 && cuv[k+1]!=s[j])
                    k=pi[k];
                if (cuv[k+1]==s[j]) ++k;
                if (k==c) {
                    k=pi[k];
                    ap[j][i]=1;
                }
            }
        }

        // verific
        for (i=1; i<=l; ++i) {
            DP[i]=1+DP[i-1];
            for (j=1; j<=n; ++j)
                if (ap[i][j]) DP[i]=min(DP[i], DP[i-L[j]]);
        }
        g<<DP[l]<<"\n";
    }



    return 0;
}
