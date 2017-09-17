# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define mp make_pair
# define NR 1050
using namespace std;
ifstream f("pitici.in");
ofstream g("pitici.out");
vector <int> v[NR];
vector <pair <int, pair<int, int> > > HEAP; //valoare, I, L[i]
int i,j,n,m,x,y,w,K,cost,k,nr,ant,l;
int ord[NR], ap[NR], L[NR], a[NR][NR];
short C[NR][NR];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);

    ord[++w]=k;
}
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>cost; C[y][x]=cost;

        v[y].push_back(x);
    }
    DFS (n); L[1]=1; a[1][1]=0;

    for (i=2; i<=w; ++i)
    {
        k=ord[i]; HEAP.clear();
        for (j=0; j<v[k].size(); ++j)
        {
            int ant=v[k][j];

            HEAP.push_back(mp(-(a[ant][1] + C[k][ant]), mp (ant, 1)));
            push_heap(HEAP.begin(), HEAP.end());
        }

        while (HEAP.size() && L[k]<K)
        {
            nr=-HEAP[0].first;
            ant=HEAP[0].second.first;
            l=HEAP[0].second.second;

            pop_heap(HEAP.begin(), HEAP.end());
            HEAP.pop_back();

            a[k][++L[k]]=nr;
            if (l<L[ant])
            {
                ++l;
                HEAP.push_back(mp(-(a[ant][l] + C[k][ant]), mp (ant, l)));
                push_heap(HEAP.begin(), HEAP.end());
            }
        }
    }


    for (i=1; i<=K; ++i)
        g<<a[n][i]<<" ";
    g<<"\n";

    return 0;
}
