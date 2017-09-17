# include <bits/stdc++.h>
# define NR 1000005
using namespace std;
ifstream f("elmaj.in");
ofstream g("elmaj.out");
int i,j,n,m,x,X,ap, a[NR];
int main ()
{
    f>>n; ap=0;
    for (i=1; i<=n; ++i) {
        f>>x; a[i]=x;
        if (ap==0) ap=1, X=x;
        else {
            if (X==x) ++ap;
                 else --ap;
        }
    }

    f>>n; ap=0;
    for (i=1; i<=n; ++i) {
        if (X==a[i]) ++ap;
    }
    if (ap>=n/2+1) g<<X<<" "<<ap<<"\n";
              else g<<"-1\n";

    return 0;
}
