# include <fstream>
# include <algorithm>
# define inf 2000000000
using namespace std;
ifstream f("optim.in");
ofstream g("optim.out");
int i,j,n,k,minn,maxx,p,t;
int a[100], m[100][100], M[100][100];
int main ()
{
    f>>n>>k;
    for (i=1; i<=n; ++i)
        f>>a[i];
    for (i=1; i<=n; ++i)
    {
        m[i][0]=m[i-1][0]+a[i];
        M[i][0]=M[i-1][0]+a[i];
        for (j=1; j<i && j<=k; ++j)
        {
            if (j<i-1)
             {
                 minn = m[i-1][j] + a[i];
                 maxx = M[i-1][j] + a[i];
             }
             else
             {
                 minn = inf;
                 maxx = -inf;
             }
            p=a[i];
            for (t=1; t<=j; ++t)
            {
                p*=a[i-t];
                if (i-1 > j || (i-t-1 == 0))
                {
                    minn=min(minn, m[i-t-1][j-t]+p);
                    maxx=max(maxx, M[i-t-1][j-t]+p);
                }
            }
            m[i][j]=minn;
            M[i][j]=maxx;
        }
    }
    g<<m[n][k]<<" "<<M[n][k]<<"\n";

    return 0;
}
