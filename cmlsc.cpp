# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,n,m,x,y,I,J,VV;
int a[NR], b[NR], maxx[NR][NR], sol[NR];
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i) f>>a[i];
    for (i=1; i<=m; ++i) f>>b[i];

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j]) maxx[i][j]=maxx[i-1][j-1] + 1;
                       else maxx[i][j]=max(maxx[i-1][j], maxx[i][j-1]);

    I=n; J=m;
    while (J!=0 && I!=0) {
        if (a[I]==b[J]) {
            sol[++VV]=a[I];
            --I; --J;
        } else {
            if (maxx[I-1][J] > maxx[I][J-1]) --I;
                                        else --J;
        }
    }
    g<<VV<<"\n";
    for (i=VV; i>=1; --i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
