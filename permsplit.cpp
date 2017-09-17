# include <fstream>
# include <algorithm>
# define NR 1000005
using namespace std;
ifstream f("permsplit.in");
ofstream g("permsplit.out");
struct elem {
    int ci, cs, taie;
}x, st[NR];
int i,j,n,m,VV,nrsol,X;
int sol[NR];
elem make_interval (elem x, elem y)
{
    elem A;
    A.ci=min(x.ci, y.ci);
    A.cs=max(x.cs, y.cs);
    sol[++nrsol]=max(x.taie, y.taie);
    A.taie=min(x.taie, y.taie);

    return A;
}
bool PotCombina (elem x, elem y)
{
    if (x.cs+1==y.ci || y.cs+1==x.ci) return 1;
                                 else return 0;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>X;
        x.ci=X; x.cs=X; x.taie=i-1;

        while (VV>0 && PotCombina (x, st[VV])) {
            x=make_interval(x, st[VV]);
            --VV;
        }
        st[++VV]=x;
    }
    if (VV==1) {
        for (i=n-1; i>=1; --i)
            g<<sol[i]<<" ";
        g<<"\n";
    }
    else g<<"-1\n";


    return 0;
}
