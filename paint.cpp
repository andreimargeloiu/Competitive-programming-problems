# include <fstream>
# include <algorithm>
# define NR 200005
using namespace std;
ifstream f("paint.in");
ofstream g("paint.out");
int i,j,n,m,K,l,d,nrsol,S;
int a[NR];
int main ()
{
    f>>n>>K>>m;

    for (i=1; i<=m; ++i)
    {
        f>>d>>l;
        ++a[1+d];
        --a[d+l+1];
    }
    for (i=1; i<=n; ++i)
    {
        S=S+a[i];
        if (S<K) ++nrsol;
    }
    g<<nrsol<<"\n";

    return 0;
}
