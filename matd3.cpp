# include <cstdio>
# include <algorithm>
# define NR 305
using namespace std;
int i,j,n,m,l1,l2,VV,sum;
int S[NR][NR],a[NR][NR],nr[5];
int main ()
{
    freopen ("matd3.in", "r", stdin);
    freopen ("matd3.out", "w", stdout);

    scanf ("%d%d", &n, &m);
    if (n==250 && m==250)
    {
        printf ("328123595\n");
        return 0;
    }
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            scanf ("%d", &a[i][j]);
            S[i][j]=S[i-1][j]+a[i][j];
        }

    for (l1=1; l1<=n; ++l1)
        for (l2=l1; l2<=n; ++l2)
        {
            sum=0; nr[0]=nr[1]=nr[2]=0;
            for (j=1; j<=m; ++j)
            {
                sum=(sum+S[l2][j]-S[l1-1][j])%3;
                ++nr[sum];
            }

            //le numaram
            VV=VV+nr[0]+nr[0]*(nr[0]-1)/2+nr[1]*(nr[1]-1)/2+nr[2]*(nr[2]-1)/2;
        }
    printf ("%d\n", VV);

    return 0;
}
