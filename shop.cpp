# include <fstream>
# include <algorithm>
# include <iomanip>
# define NR 1005
using namespace std;
ifstream f("shop.in");
ofstream g("shop.out");
int i,j,n;
double minn[NR],var[5],a[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];

    for (i=1; i<=n; ++i)
    {
        //s
        minn[i]=minn[i-1]+a[i];
        //d
        if (i>=2) minn[i]=min(minn[i], minn[i-2]+max(a[i], a[i-1])+min(a[i], a[i-1])/2);
        //t
        if (i>=3)
        {
            var[1]=a[i-2]; var[2]=a[i-1]; var[3]=a[i];
            sort (var+1, var+3+1);
            minn[i]=min(minn[i], minn[i-3]+var[3]+var[2]);
        }
    }
    g<<fixed<<setprecision(1)<<minn[n]<<"\n";

    return 0;
}
