# include <algorithm>
# include <fstream>
# define MOD 30103
# define NR 1050
using namespace std;
ifstream f("bsir.in");
ofstream g("bsir.out");
int i,j,n,m,ci,cs,SOL;
int v[NR], a[NR][NR];
int descompunere (int k)
{
    int nr=0;
    while (k)
    {
        int r=k%2;
        nr+=r;
        k=k/2;
    }

    return nr%2;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        v[i]=descompunere (i-1);

    for (i=1; i<=n; ++i)
        a[i][i]=1;

    for (i=2; i<=n; ++i) //fiecare lungime de palindrom
        for (j=1; j<=n-i+1; ++j) {
            ci=j; cs=j+i-1;
            if (v[ci]==v[cs]) {
                if (i==2) a[ci][cs]=1;
                else a[ci][cs]=a[ci+1][cs-1];

                SOL=(SOL+a[ci][cs])%MOD;
            }
        }



    g<<SOL<<"\n";

    return 0;
}
