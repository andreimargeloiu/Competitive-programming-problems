# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# include <set>
# define NR 200005
# define mod 1999999973
using namespace std;
ifstream f("heapuri.in");
ofstream g("heapuri.out");
int i,j,n,m,tip,VV,x;
int a[NR];
int main ()
{
    f>>n;
    multiset <int> H;
    for (i=1; i<=n; ++i)
    {
        f>>tip;
        if (tip==1)
        {
            f>>a[++VV];
            H.insert(a[VV]);
        }
        else if (tip==2)
        {
            f>>x;
            H.erase (H.find(a[x]));
        }
        else {
                 g<<*H.begin()<<"\n";
             }
    }
    return 0;
}
