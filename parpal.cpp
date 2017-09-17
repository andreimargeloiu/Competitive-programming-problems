# include <cstdio>
# include <cstring>
# define mil 1000005
# define X 13
# define MOD 8723609
using namespace std;
int i,j,n,l,VV,nr1,nr2,put,last;
short st[mil];
char s[mil];
int main ()
{
    freopen("parpal.in", "r", stdin);
    freopen("parpal.out", "w", stdout);
    scanf ("%d", &n); gets(s);
    int nr1,nr2,put,l;
    for (int j=1; j<=n; ++j)
    {
        gets(s+1);
        l=strlen(s+1);
        put=1; nr1=0; nr2=0; last=0;
        for (int i=1; i<=l; ++i)
        {
            nr1=nr1*X+s[i];
            if (nr1>=MOD) nr1%=MOD;

            nr2=nr2+(s[i])*put;
            if (nr2>=MOD) nr2%=MOD;

            put=put*X;
            if (put>=MOD) put%=MOD;

            if (i%2==0 && nr1==nr2)
            {
                nr1=nr2=0; put=1;
                last=i;
            }
        }
        if (l==0 || (l%2==0 && last==l)) printf ("DA\n");
            else printf ("NU\n");
    }

    return 0;
}
