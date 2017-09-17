# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1000
using namespace std;
ifstream f("ivv.in");
ofstream g("ivv.out");
int i,j,n,m,x,y,sol;
int a[NR], var[NR], V[NR];
bool verifica ()
{
    int i,j,o, ok=1, ci=n+1;

    for (i=1; i<=n; ++i)
        V[i]=a[i];

    for (i=n; i>=1 && ok; --i)
    {
        if (var[i]!=V[i]) {
            ok=0;

            for (j=min(ci-1, i); j>=1; --j) {
                if (V[j]==var[i]) {
                    for (o=j; o<=i; ++o)
                    V[o]=var[i];
                    ci=j; ok=1;
                    break;
                }
            }
        }
    }
    if (ok)
    {
        for (i=1; i<=n; ++i)
            g<<var[i]<<" ";
        g<<"\n";
    }
    return ok;
}
void back (int k) {
    if (k==n+1) {
        if (verifica ()) ++sol;
    }
    else {
        var[k]=1;
        back(k+1);

        var[k]=0;
        back(k+1);
    }

}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];

    back (1);

    g<<sol<<"\n";

    return 0;
}
