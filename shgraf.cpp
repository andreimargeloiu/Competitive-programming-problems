# include <cstdio>
# include <algorithm>
# define MOD 30011
using namespace std;
int i,j,n,k,o;
int moduri[251]; //nr de moduri cu suma [i]
int S[251];
int main ()
{
    freopen ("shgraf.in", "r", stdin);
    freopen ("shgraf.out", "w", stdout);
    scanf ("%d%d", &n, &k);

    for (i=k; i<=n; ++i)//fiecare ciclu nou adaugat
    {
        for (j=i; j<=n; j+=i)//de cate ori il adaug
            for (o=n-j; o>=k; --o)//fiecare suma anterioara posibila
                S[o+j]+=moduri[o];

        for (j=k; j<=n; ++j)
        {
            if (j%i==0) ++S[j];
            moduri[j]=(moduri[j]+S[j])%MOD;
            S[j]=0;
        }
    }
    printf ("%d\n", moduri[n]);
    return 0;
}
