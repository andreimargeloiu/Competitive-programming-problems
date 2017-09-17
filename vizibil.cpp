# include <fstream>
# include <algorithm>
# define NR 105
# define MOD 997
using namespace std;
ifstream f("vizibil.in");
ofstream g("vizibil.out");
int i,j,n,m,x,y,st,dr,SOL;
int c[NR][NR], S[NR][NR];

void combinari ()
{
    c[1][0]=1; c[1][1]=1;
    for (int i=2; i<=n; ++i) {
        c[i][0]=1; c[i][i]=1;
        for (int j=1; j<i; ++j) {
            c[i][j]=c[i-1][j-1] + c[i-1][j];
            c[i][j]%=MOD;
        }
    }
}
void dinamica ()
{
    S[1][1]=1; S[0][0]=1;
    for (int i=2; i<=n; ++i) {
        for (int j=1; j<=i; ++j) {
            S[i][j]=S[i-1][j-1] + S[i-1][j]*(i-1);
            S[i][j]%=MOD;
        }
    }
}
int main ()
{
    f>>n>>st>>dr; --st; --dr;

    combinari ();
    dinamica ();

    for (i=1; i<=n; ++i) {
        if (st<=i-1 && dr<=n-i) {
            SOL=SOL + S[i-1][st]*c[n-1][i-1]*S[n-i][dr];
        }
        SOL%=MOD;
    }

    g<<SOL<<"\n";

    return 0;
}
