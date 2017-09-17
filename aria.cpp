# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("aria.in");
ofstream g("aria.out");
int i,j,n,m;
double x[NR], y[NR], arie;
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>x[i]>>y[i];
    }
    y[n+1]=y[1]; x[n+1]=x[1];

    for (i=1; i<=n; ++i) {
        arie=arie + (x[i] * y[i+1] - x[i+1] * y[i]);
    }

    g<<fixed<<setprecision(6)<<arie/2<<"\n";

    return 0;
}
