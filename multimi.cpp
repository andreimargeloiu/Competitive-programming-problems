# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("multimi.in");
ofstream g("multimi.out");
int i,n,ci,cs,x,y;
int main ()
{
    f>>n; ci=-1; cs=100000;
    for (i=1; i<=n; ++i)
    {
        if (ci>cs) {
                        g<<"multimea vida\n";
                        return 0;
                   }
        f>>x>>y;
        ci=max(x,ci);
        cs=min(cs,y);
    }
    for (i=ci; i<=cs; ++i)
        g<<i<<" ";
    return 0;
}
