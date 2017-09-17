# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# include <deque>
# define LB(p) ((-p)&p)
# define NR 5000005
# define mod 1999999973
using namespace std;
deque <int> d;
ifstream f("deque.in");
ofstream g("deque.out");
int i,j,n,m,k;
int a[NR];
long long S;
int main ()
{
    f>>n>>k;

    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        while (! d.empty() && a[i]<=a[d.back()])
            d.pop_back();
        d.push_back(i);

        if (d.front()<=i-k) d.pop_front();
        if (i>=k) S+=a[d.front()];
    }
    g<<S<<"\n";

    return 0;
}
