# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("rf.in");
ofstream g("rf.out");
int i,j,n,k;
int a[300][300],nr[300][300];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
        {
            f>>a[i][j];
            if (i!=j) nr[i][j]=1;
        }

    for (k=1; k<=n; ++k)
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j)
                if (a[i][k] && a[k][j] && i!=j)
                {
                    if (!a[i][j] || a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j],nr[i][j]=nr[i][k]+nr[k][j];
                    if (a[i][j]==a[i][k]+a[k][j]) nr[i][j]=max(nr[i][j],nr[i][k]+nr[k][j]);
                }
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
            g<<a[i][j]<<" ";
        g<<"\n";
    }
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
            g<<nr[i][j]<<" ";
        g<<"\n";
    }

    return 0;
}
