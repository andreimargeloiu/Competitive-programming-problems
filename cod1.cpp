# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 500
# define sigma 26
# define MOD 9901
using namespace std;
ifstream f("cod1.in");
ofstream g("cod1.out");
int i,j,n,m,S,k,l,fact;
int ap[NR], a[NR][NR];
char s[NR];
int main ()
{
    f>>n; f.get();
    f.getline(s+1, NR); l=strlen(s+1);

    for (i=1; i<=l; ++i)
        ++ap[s[i]-'a'+1];

    //a[i][j] - numarul de coduri de lungime i
    //        - j=2 daca nu a fost folosita prezenta dubla

    for (k=1; k<=sigma; ++k) {
        if (ap[k]>=2) { //pun dubla
           for (i=n; i>=2; --i){
                a[i][2]+=a[i-2][1];
                a[i][2]%=MOD;

                a[i][1]+=a[i-1][1];
                a[i][2]+=a[i-1][2];

                a[i][1]%=MOD; a[i][2]%=MOD;
           }
           ++a[2][2]; a[2][2]%=MOD;
           ++a[1][1]; a[1][1]%=MOD;
        }

        if (ap[k]==1) { //il pun singur
            for (i=n; i>=2; --i) {
                a[i][1]+=a[i-1][1];
                a[i][2]+=a[i-1][2];

                a[i][1]%=MOD; a[i][2]%=MOD;
            }
            ++a[1][1]; a[1][1]%=MOD;
        }
    }
    //aplicam permutari
    fact=1;
    for (i=3; i<=n; ++i)
        fact=fact*i%MOD;
    fact*=2;

    S=(a[n][1]*fact + a[n][2]*fact/2)%MOD;
    g<<S<<"\n";

    return 0;
}
