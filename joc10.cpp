# include <cstdio>
using namespace std;
int i,j,n,m,o,VV,x,y;
int st[1005];
int mat[105][105];
int main ()
{
    freopen ("coment.in", "r", stdin);
    freopen ("coment.out", "w", stdout);
    scanf ("%d", &n);
    int nr=n*(n-1)/2;
    for (i=1; i<=nr; ++i)
    {
        scanf ("%d%d", &x, &y);
        mat[x][y]=1;
    }
    st[++VV]=1;
    for (i=2; i<=n; ++i)
    {
        if (mat[st[VV]][i]) st[++VV]=i;
        else if (mat[i][st[1]])
        {
            for (j=VV+1; j>=2; --j)
                st[j]=st[j-1];
            st[1]=i; ++VV;
        }
        else {
                 for (j=1; j<=VV; ++j)
                 {
                     if (mat[st[j]][i] && mat[i][st[j+1]])
                     {
                         for (o=VV+1; o>=j+1; --o)
                              st[o]=st[o-1];
                         st[j+1]=i; ++VV;
                         break;
                     }
                 }
             }
    }
    for (i=1; i<=n; ++i)
        printf ("%d ", st[i]);

    printf ("\n");
    return 0;
}
