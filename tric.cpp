# include <cstdio>
# include <vector>
# include <algorithm>
# define NR 100005
using namespace std;
vector <pair <int, int> > HEAP;
vector <int> v[NR];
int i,j,n,m,x,y,suma,I,maxx;
int ap[NR], S[NR];
int main ()
{
    freopen ("tric.in", "r", stdin);
    freopen ("tric.out", "w", stdout);

    scanf ("%d%d", &n, &m);

    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }


    for (int o=0; o<n; ++o)
    {
        if (ap[o]) continue;
        ap[o]=1;
        for (i=0; i<v[o].size(); ++i)
        {
            ++S[v[o][i]];
            HEAP.push_back (make_pair (S[v[o][i]], v[o][i]));
            push_heap (HEAP.begin(), HEAP.end());
        }

        while (HEAP.size())
        {
            while (HEAP.size() && ap[HEAP[0].second])
            {
                pop_heap(HEAP.begin(), HEAP.end());
                HEAP.pop_back();
            }
            if (HEAP.size())
            {
                suma=HEAP[0].first; I=HEAP[0].second;
                pop_heap(HEAP.begin(), HEAP.end());
                HEAP.pop_back();

                ap[I]=1; maxx=maxx + suma*(suma-1)/2;

                for (i=0; i<v[I].size(); ++i)
                {
                    if (! ap[v[I][i]])
                    {
                        ++S[v[I][i]];
                        HEAP.push_back (make_pair (S[v[I][i]], v[I][i]));
                        push_heap (HEAP.begin(), HEAP.end());
                    }
                }
            }
        }
    }
    printf ("%d\n", maxx);

    return 0;
}
