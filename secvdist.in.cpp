# include <fstream>
# include <algorithm>
# include <vector>
# include <deque>
# define NR 1000005
using namespace std;
ifstream f("secvdist.in");
ofstream g("secvdist.out");
deque <int> dmin, dmax;
int i,j,n,m,xi,ci,K,L;
int a[NR];
int main ()
{
    f>>n>>K;
    ci=1;
    for (i=1; i<=n; ++i) {
        f>>a[i];

        //punem in dmin
        while (! dmin.empty() && a[dmin.front()] >= a[i])
            dmin.pop_back();
        dmin.push_back(i);

        //punem in dmax
        while (! dmax.empty() && a[dmax.front()] <= a[i])
            dmax.pop_back();
        dmax.push_back(i);

        while (! dmin.empty() && ! dmax.empty() && (a[dmax.front()] - a[dmin.front()])>K) {
            if (dmin.front()==ci) dmin.pop_front();
            if (dmax.front()==ci) dmax.pop_front();
            ++ci;
        }
        L=max(L, i-ci+1);
    }
    g<<L<<"\n";


    return 0;
}
