# include <fstream>
# include <deque>
# include <algorithm>
# define NR 100005
using namespace std;
ifstream f("branza.in");
ofstream g("branza.out");
deque <int> d;
int i,j,n,m,S,T;
int c[NR], p[NR];
long long cost;
int main ()
{
    f>>n>>S>>T;

    for (i=1; i<=n; ++i)
    {
        f>>c[i]>>p[i];//costul si productia
        while (! d.empty() && 1LL*c[i]<=1LL*c[d.back()]+1LL*S*(i-d.back()))
             d.pop_back();

        d.push_back(i);
        if (d.front()==i-T-1) d.pop_front();
        cost+=(1LL*p[i]*c[d.front()]+1LL*S*p[i]*(i-d.front()));
    }
    g<<cost<<"\n";
    return 0;
}
