# include <fstream>
# include <algorithm>
# include <deque>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("caluti.in");
ofstream g("caluti.out");
deque <int> d;
int i,j,n,m,x,y,K,T;
long long start[NR], a[NR], timp;
int main ()
{
    f>>T;

    // a[i] - timpul minim pentru a duce toti calutii inclusiv i

    for (int t=1; t<=T; ++t) {
        f>>n>>K>>timp; d.clear();
        d.push_back(0); memset (a, 0, sizeof(a));

        for (i=1; i<=n; ++i) {
            f>>start[i];
            a[i]=max(a[d.front()], start[i]) + timp;

            while (!d.empty() && a[i]<=a[d.back()])
                d.pop_back();
            d.push_back(i);

            if (d.front()==i-K) d.pop_front();
        }
        g<<a[n]<<"\n";
    }

    return 0;
}
