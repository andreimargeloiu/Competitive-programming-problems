# include <cstdio>
# include <bitset>
using namespace std;
bitset <2005> ap[2005];
int i,j,n,m,K,x,I,J,o;
int nr[10000];
int main ()
{
    freopen ("intersectii.in", "r", stdin);
    freopen ("intersectii.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &K);
    for (i=1; i<n; ++i)
        for (j=1; j<m; ++j)
        {
            if (! ap[i][j])
            {
                I=0; J=0;
                for (o=1; o<=2000 && I+i<n && J+j<m; ++o)
                {
                    I+=i; J+=j;
                    ++nr[o*(i+j-1)];
                    ap[I][J]=1;
                }
            }
        }
    for (i=1; i<=K; ++i)
    {
        scanf ("%d", &x);
        printf ("%d\n", 4*nr[x]);
    }

    return 0;
}
