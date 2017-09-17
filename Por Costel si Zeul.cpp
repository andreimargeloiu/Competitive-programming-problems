# include <fstream>
# include <algorithm>
# define NR 300005
using namespace std;
ifstream f("zeul.in");
ofstream g("zeul.out");
int i,j,n,m,P,D,x,y;
int donez[NR], primesc[NR], in[NR], out[NR];
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        ++out[x]; ++in[y];
    }
    for (i=1; i<=n; ++i) {
        if (in[i]<out[i]) {
            for (j=1; j<=out[i]-in[i]; ++j)
                primesc[++P]=i;
        }
        else {
            for (j=1; j<=in[i]-out[i]; ++j)
                donez[++D]=i;
        }
    }
    g<<P<<"\n";
    for (i=1; i<=P; ++i)
        g<<donez[i]<<" "<<primesc[i]<<"\n";



    return 0;
}
