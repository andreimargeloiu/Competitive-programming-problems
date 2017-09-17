# include <fstream>
# include <algorithm>
# include <cstring>
# include <queue>
# include <vector>
# define NR 1000005
using namespace std;
ifstream f("elmaj.in");
ofstream g("elmaj.out");
int i,j,n,nr,X,ap;
int a[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        if (nr==0) X=a[i], nr=1;
        else {
                 if (a[i]==X) ++nr;
                         else --nr;
             }
    }
    for (i=1; i<=n; ++i)
        if (a[i]==X) ++ap;

    if (ap>=n/2+1) g<<X<<" "<<ap<<"\n";
              else g<<"-1\n";

    return 0;
}
