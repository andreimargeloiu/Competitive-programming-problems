# include <fstream>
# include <algorithm>
# define MOD 666013
# define NR 12005
using namespace std;
ifstream f("rec.in");
ofstream g("rec.out");
int i,j,n,m,S,F,nou,act;
long long a[3][NR];
int main ()
{
    f>>S>>n>>F;

    S=S-n*F;

    // a[i][j] - numarul de moduri de a forma suma j din i numere
    act=0;
    for (i=1; i<=n; ++i) {
        nou=1-act;
        a[nou][0]=1;
        for (j=1; j<=S; ++j) {
            a[nou][j]=a[act][j];
            if (j>=i) a[nou][j]+=a[nou][j-i];

        }
        act=nou;
    }
    g<<a[nou][S]<<"\n";

    return 0;
}
