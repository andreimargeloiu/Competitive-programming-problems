# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
int i,j,n,m,k,l,minn,VV,I,cifre;
char s[1000010];
int main ()
{
    freopen ("taie.in", "r", stdin);
    freopen ("taie.out", "w", stdout);
    scanf ("%d %d %d\n", &n, &k, &l);
    scanf ("%s", s+1);
    //incerc sa construiec cifra cu cifra
    VV=1; cifre=n-k*l;
    for (j=1; j<=cifre; ++j)
    {
        minn=s[VV]; I=VV;
        for (i=VV+l; i<=n-(cifre-j); i+=l)
        {
            if (s[i]<minn) minn=s[i], I=i;
            if (minn=='1') break;
        }
        VV=I+1;
        printf ("%d", (int)(minn-'0'));
    }
    return 0;
}
