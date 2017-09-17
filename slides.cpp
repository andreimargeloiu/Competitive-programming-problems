# include <fstream>
# include <algorithm>
# define NR 55
using namespace std;
ifstream f("slides.in");
ofstream g("slides.out");
int i,j,n,m,T;
int SOL[NR][NR];
unsigned long long drum[NR], unu=1, nr;
void make_drumuri () {
    drum[1]=1;
    for (int i=2; i<=50; ++i)
        drum[i]=(unu<<(i-2));
}
int main ()
{
    f>>T; make_drumuri ();
    int cnt=0;
    while (T--) {
        f>>n>>nr;
        ++cnt;
        g<<"Case #"<<cnt<<": ";

        if (drum[n] < nr) {
            g<<"IMPOSSIBLE\n";
            continue;
        }

        // fac drumuri de la toate la tore - n
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j) {
                SOL[i][j]=0;
                if (j!=n && j>i) SOL[i][j]=1;
            }

        for (int i=n-1; i>=1; --i)
            if (nr>=drum[i]) {
                SOL[i][n]=1;
                nr-=drum[i];
            }

        g<<"POSSIBLE\n";
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j)
                g<<SOL[i][j];
            g<<"\n";
        }
    }

    return 0;
}
