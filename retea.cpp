# include <fstream>
# include <algorithm>
# include <vector>
# include <iomanip>
# define NR 1005
# define inf 999999999
using namespace std;
ifstream f("retea.in");
ofstream g("retea.out");
vector <pair <double, pair<int, int> > > HEAP; //cost, nod, K
struct elem
{
    int y, cost;
}E;
vector <elem> v[NR];
bool cmp (elem x, elem y)
{
    if (x.cost>=y.cost) return 0;
                  else  return 1;
}

int i,j,n,m,x,y,K,ap[NR][15];
double cost[NR][12], unu=1;

void init ()
{
    for (int i=1; i<=n; ++i)
        for (int j=0; j<=K; ++j)
            cost[i][j]=inf;
    cost[1][0]=0;
}
void djikstra ()
{
    int i,j,k,kuz;
    double C;
    init ();
    HEAP.push_back(make_pair(0, make_pair(1, 0)));
    push_heap(HEAP.begin(), HEAP.end());

    while (HEAP.size())
    {
        C=-HEAP[0].first;
        k=HEAP[0].second.first;
        kuz=HEAP[0].second.second;

        if (ap[k][kuz])
        {
            pop_heap(HEAP.begin(), HEAP.end());
            HEAP.pop_back();
            continue;
        }
        if (k==n && kuz==K) break;
        ap[k][kuz]=1;

        pop_heap(HEAP.begin(), HEAP.end());
        HEAP.pop_back();

        for (i=0; i<v[k].size(); ++i)
            for (j=0; j<=K-kuz; ++j)
            if (C + unu*v[k][i].cost/(1<<j) < cost[v[k][i].y][kuz+j])
            {
                cost[v[k][i].y][kuz+j]=C + unu*v[k][i].cost/(1<<j);

                HEAP.push_back(make_pair(-cost[v[k][i].y][kuz+j], make_pair(v[k][i].y, kuz+j)));
                push_heap(HEAP.begin(), HEAP.end());
            }
    }
}
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>E.cost;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    for (i=1; i<=n; ++i)
        sort (v[i].begin(), v[i].end(), cmp);

    djikstra ();

    g<<fixed<<setprecision(4)<<cost[n][K]<<"\n";

    return 0;
}
