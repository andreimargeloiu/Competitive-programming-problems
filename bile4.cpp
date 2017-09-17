# include <cstdio>
# include <algorithm>
using namespace std;
int st[100],n,K;
void back (int k)
{
    int i;
    if (k==K+1)
    {
        for (i=1; i<=K; ++i)
            printf ("%d ", st[i]);
        printf ("\n");
    }
    else {
             for (i=st[k-1]+1; i<=n; ++i)
             {
                 st[k]=i;
                 back(k+1);
                 st[k]=0;
             }
         }
}
int main ()
{
    freopen ("bile4.in", "r", stdin);
    freopen ("bile4.out", "w", stdout);

    scanf ("%d%d", &n, &K);

    back (1);


    return 0;
}
