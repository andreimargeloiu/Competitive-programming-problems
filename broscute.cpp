# include <cstdio>
using namespace std;
int i,j,n,k,x,y,VV,p,s;
int P[2500],S[2500];
bool a[1005][1005];
int princ (int x, int y)
{
    return x+y-1 ;
}
int sec (int x, int y)
{
    return (n-x)+y;
}
int main ()
{
    freopen ("broscute.in", "r", stdin);
    freopen ("broscute.out", "w", stdout);

    scanf ("%d%d", &n, &k);
    for (i=1; i<=k; ++i)
    {
        scanf ("%d%d", &x, &y);
        p=princ (x,y); s=sec (x,y);
        ++P[p]; ++S[s];
        a[x][y]=1;
    }
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            p=princ (i,j); s=sec (i,j);
            if (a[i][j]==1)
            {
                if (P[p]>1 || S[s]>1)
                {
                    ++VV;

                }
            }
            else {
                     if (P[p]!=0 && S[s]!=0)
                     {
                         ++VV;

                     }
                 }
        }
    }
    /*for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
            printf ("%d ", a[i][j]);
        printf ("\n");
    }*/
    printf ("%d\n", VV);
    return 0;
}
