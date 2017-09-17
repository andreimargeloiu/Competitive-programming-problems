# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("calatorie.in");
ofstream g("calatorie.out");
int a[200][200],b[200][200]
int main ()
{
    f>>x>>k;
    f>>n;
    for (i=1; i<=n; ++i)
        f>>v[i];
    sort (v+1,v+n+1); VV=1;
    a[1][1]=1; b[1][1]=1;
    J=1;
    for (i=2; i<=x; ++i)
    {
        ++J;
        for (j=max(1,i-k); j<=i+k; ++j)
        {
            if (v[VV]==i && j==J) ++VV;
            {
                for (q=1; q<=k; ++q) b[i]
            }
            b[i][j]
        }
    }



    return 0;
}
