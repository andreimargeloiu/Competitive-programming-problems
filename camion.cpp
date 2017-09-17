# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("camion.in");
ofstream g("camion.out");
int i,j,n,m,k,c,X;
int x[30005],y[30005],y2[30005],x2[30005];
int main ()
{
    f>>n>>m>>k>>c;
    for (i=1; i<=k; ++i)
        f>>x[i]>>y[i]>>x2[i]>>y2[i];

    for (i=1; i<=n; ++i)
    {
        X=c;
        for (j=k; j>=1; --j)
        {
            if (x[j]<=i && i<=x2[j])
            {
                if (X>=y[j]) X=X+y2[j]-y[j]+1;
            }
        }
        if (X>m) g<<"0\n";
            else g<<X<<"\n";
    }

    return 0;
}
