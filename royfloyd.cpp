# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 105
using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int R,i,j,n,m,VV,k;
int a[NR][NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            f>>a[i][j];

    for (k=1; k<=n; ++k)
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j)
                if (i!=j && a[i][k] && a[k][j] && (! a[i][j] || a[i][k] + a[k][j] < a[i][j]))
                    a[i][j]=a[i][k] + a[k][j];

    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j)
            g<<a[i][j]<<" ";
        g<<"\n";
    }

    return 0;
}
