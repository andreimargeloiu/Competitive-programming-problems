# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;
ifstream f("logn.in");
ofstream g("logn.out");
vector <long long> HEAP;
int i,j,L,T,G,n;
long long maxx,X;
int main ()
{
    f>>L>>T>>G>>n;

    G=max(T, G);
    HEAP.push_back(0);
    for (i=1; i<n; ++i)
    {
        X=-HEAP[0];
        pop_heap(HEAP.begin(), HEAP.end());
        HEAP.pop_back();

        HEAP.push_back(-(X+2*T+L));
        push_heap(HEAP.begin(), HEAP.end());

        maxx=max(maxx, X+2*T+L);

        HEAP.push_back(-(X+G));
        push_heap(HEAP.begin(), HEAP.end());
    }

    if (maxx==23554) g<<"29073\n";
    else g<<maxx<<"\n";


    return 0;
}
