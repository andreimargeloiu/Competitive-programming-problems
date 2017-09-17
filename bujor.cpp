# include <fstream>
# include <algorithm>
# include <iomanip>
# define NR 205
using namespace std;
ifstream f("bujor.in");
ofstream g("bujor.out");
int i,j,n,m,o,t;
int a[NR][NR];
double p[NR][NR];
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n;
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j)
            {
                f>>a[i][j];
                p[i][j]=0;
            }
        for (i=1; i<=n; ++i)
        {
            for (j=1; j<=n; ++j)
            {
                if (a[i][j])//daca joaca la masinuta j
                {
                    p[j][i]=((double)1)/((double)a[i][j]);
                    break;
                }
            }
        }
        for (i=1; i<=n; ++i)
        {
            for (j=1; j<=n; ++j)
                g<<fixed<<setprecision(9)<<p[i][j]<<" ";
            g<<"\n";
        }
    }

    return 0;
}
