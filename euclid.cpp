# include <bits/stdc++.h>
# define LB(p) ((p)&(-p))
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,j,n,m,a,b;
int euclid (int a, int b) {
    if (b==0) return a;
    else return euclid (b, a%b);
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>a>>b;
        g<<euclid(a, b)<<"\n";
    }
    return 0;
}
