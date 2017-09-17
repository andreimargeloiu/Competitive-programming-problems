# include <fstream>
# include <algorithm>
# define NR 105
using namespace std;
ifstream f("joctv.in");
ofstream g("joctv.out");
int i,j,n,m,ant,maxx,k,x;
int S[NR][NR];
int main ()
{
    f>>n; maxx=-999999999;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
        {
            f>>x;
            S[i][j]=x + S[i-1][j];
        }
    for (i=1; i<=n; ++i)
    {
        for (j=i; j<=n; ++j)
        {
            ant=S[j][1] - S[i-1][1];
            maxx=max(maxx, ant);
            for (k=2; k<=n; ++k)
            {
                x=S[j][k] - S[i-1][k];

                if (ant+x>x) ant+=x;
                        else ant=x;
                maxx=max(maxx, ant);
            }
        }
    }
    g<<maxx<<"\n";

    return 0;
}
