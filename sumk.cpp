# include <fstream>
# include <cstring>
# include <algorithm>
# define mod 578537
# define NR 505
using namespace std;
ifstream f("sumk.in");
ofstream g("sumk.out");
int i,j,n,m,k,K,ant,NEW,sol;
int sum[2][NR][NR], a[2][NR][NR];
int main ()
{
    f>>n>>K;
    for (i=0; i<=K; ++i) //1 1 K
    {
        a[0][1][i]=1;
        sum[0][1][i]=i+1;
    }
    ant=1;
    for (i=1; i<=n; ++i)
    {
        NEW=1-ant;
        for (j=1; j<=n; ++j)
        {
            if (i==1 && j==1) continue;
            //facem sumele
            for (k=0; k<=K; ++k)
            {
                if (k==K)
                {
                    a[NEW][j][k]=(sum[NEW][j-1][k-1] + a[ant][j][K])%mod;
                    sum[NEW][j][k]=(sum[NEW][j][k-1] + a[NEW][j][k])%mod;
                }
                else
                {
                    a[NEW][j][k]=  (sum[NEW][j-1][k] + a[ant][j][K])%mod;
                    sum[NEW][j][k]=(sum[NEW][j][k-1] + a[NEW][j][k])%mod;
                }
            }
        }

        memset (sum, 0, sizeof(sum));

        ant=NEW;
    }

    for (i=0; i<=n; ++i)
        sol=(sol + a[NEW][i][K])%mod;

    g<<sol<<"\n";

    return 0;
}
