# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
vector <int> HEAP;
int i,j,n,m,x,y,X,Y;
int ap[NR], a[NR];
int main ()
{
    freopen ("lista.in", "r", stdin);
    freopen ("lista.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &a[i]); ++ap[a[i]];
    }

    for (i=1; i<=n; ++i)
        if (! ap[i])
        {
            HEAP.push_back(-i);
            push_heap(HEAP.begin(), HEAP.end());
        }
    for (i=1; i<n; ++i)
    {
        X=-HEAP[0];

        pop_heap(HEAP.begin(), HEAP.end());
        HEAP.pop_back();

        Y=a[i]; --ap[Y];

        if (! ap[Y])
        {
            HEAP.push_back(-Y);
            push_heap(HEAP.begin(), HEAP.end());
        }

        printf ("%d %d\n", X, Y);
    }


    return 0;
}
