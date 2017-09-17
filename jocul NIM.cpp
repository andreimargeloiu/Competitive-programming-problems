# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int i,j,n,X,x,m;
int main ()
{
    f>>m;
    for (j=1; j<=m; ++j)
    {
        f>>n; X=0;
        for (i=1; i<=n; ++i)
        {
            f>>x;
            X=X^x;
        }
        if (X==0) g<<"NU\n";
             else g<<"DA\n";
    }

    return 0;
}
