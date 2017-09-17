# include <fstream>
# include <algorithm>
# include <vector>
# include <bitset>
# define NR 1000005
# define mld 1000000000
using namespace std;
ifstream f("bleach.in");
ofstream g("bleach.out");
vector <pair<int, int> > HEAP;
int i,j,n,m,minn,castigat,nr,K,x,maxx;
bitset <NR> ap;
int main ()
{
    f>>n>>K; K+=2000;
    for (i=1; i<=n; ++i)
    {
        f>>x;
        HEAP.push_back(make_pair(-x, i));
        push_heap(HEAP.begin(), HEAP.end());

        if (HEAP.size()>K) HEAP.pop_back();
    }
    for (i=0; i<HEAP.size(); ++i)
        ap[HEAP[i].second]=1;

    f.close();
    ifstream f("bleach.in");
    f>>n>>K; K+=2000;

    castigat=0; minn=1;
    for (i=1; i<=n && castigat<mld; ++i)
    {
        f>>x;
        if (! ap[i])
        {
            HEAP.push_back(make_pair(-x, i));
            push_heap(HEAP.begin(), HEAP.end());
        }
        nr=-HEAP[0].first;
        if (minn + castigat<nr) minn=nr-castigat;
        castigat+=nr;

        pop_heap(HEAP.begin(), HEAP.end());
        HEAP.pop_back();
    }

    g<<minn<<"\n";

    return 0;
}
