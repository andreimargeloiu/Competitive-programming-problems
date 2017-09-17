# include <cstdio>
# include <algorithm>
# include <vector>
# define inf 999999999
# define NR 100005
using namespace std;
struct elem
{
    int y, dist, cost;
}E;
vector <elem> v[NR];
int i,j,n,m,x,y,maxx;
int H[NR], C[NR];
long long COST;

void DFS (int k, int tata)
{
    if (v[k].size()==1) C[k]=inf;

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i].y!=tata)
        {
            DFS (v[k][i].y, k);
            H[k]=max(H[k], H[v[k][i].y] + v[k][i].dist);

            C[v[k][i].y]=min(C[v[k][i].y], v[k][i].cost);

            C[k]=C[k] + C[v[k][i].y];
        }
}
void calc (int k, int tata)
{
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i].y!=tata)
        {
            if (v[k][i].dist + H[v[k][i].y] < H[k]) // trebuie sa-l crestem
            {
                COST=COST + 1LL*C[v[k][i].y] * (H[k] - H[v[k][i].y] - v[k][i].dist);
            }
            calc (v[k][i].y, k);
        }
}
int main ()
{
    freopen ("arb2.in", "r", stdin);
    freopen ("arb2.out", "w", stdout);
    scanf ("%d", &n);

    for (i=1; i<n; ++i)
    {
        scanf ("%d%d%d%d", &x, &y, &E.dist, &E.cost);
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    // C[i] - costul minim ca sa ridicam tot subarborele
    //        lui i cu o unitate

    DFS (1, 0); //distante + costuri

    calc (1, 0);

    printf ("%lld\n", COST);


    return 0;
}
