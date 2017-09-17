# include <fstream>
# include <algorithm>
# include <cstring>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("dominouri.in");
ofstream g("dominouri.out");
vector <int> v[NR];
int i,j,n,m,VV,x;
int C[NR], cost[NR], nv[NR], var[NR];
void DFS (int k) {
    int COST=0; if (nv[k]==0) COST=1;
    for (int i=0; i<v[k].size(); ++i)
        DFS (v[k][i]);

    VV=0;
    for (int i=0; i<v[k].size(); ++i)
        var[++VV]=C[v[k][i]];
    sort (var+1, var+VV+1);
    for (int i=1; i<=cost[k]; ++i)
        COST+=var[i];

    C[k]=COST;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>nv[i];
        for (j=1; j<=nv[i]; ++j) {
            f>>x;
            v[i].push_back(x);
        }
    }
    for (i=1; i<=n; ++i)
        f>>cost[i];

    DFS(1);
    g<<C[1]<<"\n";

    return 0;
}
