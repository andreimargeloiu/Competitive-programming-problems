# include <fstream>
# include <algorithm>
# include <vector>
# define inf 999999999
# define NR 50005
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
vector <pair <int, int> > v[NR], var;
int i,j,n,m,x,y,cost;
int C[NR];
void djikstra ()
{
    int i, k, cact, urm, cost;
    while (var.size())
    {
        cact=-var[0].first;
        k=var[0].second;

        pop_heap(var.begin(), var.end());
        var.pop_back();

        if (cact>C[k]) continue; //daca nu e cel mai optim

        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i].first; cost=v[k][i].second;
            if (C[k]+cost<C[urm])
            {
                C[urm]=C[k]+cost;
                var.push_back(make_pair(-C[urm], urm));
            }
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>cost;
        v[x].push_back(make_pair(y, cost));
    }
    for (i=2; i<=n; ++i)
        C[i]=inf;

    var.push_back(make_pair(0, 1));
    push_heap(var.begin(), var.end());

    djikstra ();

    for (i=2; i<=n; ++i)
        if (C[i]==inf) g<<"0 ";
        else g<<C[i]<<" ";
    g<<"\n";

    return 0;
}
