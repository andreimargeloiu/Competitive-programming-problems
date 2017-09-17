# include <fstream>
# include <queue>
# include <algorithm>
# include <vector>
# define NR 500005
using namespace std;
ifstream f("markon.in");
ofstream g("markon.out");
vector <int> v[NR], sol;
queue <int> q;
int i,j,n,m,x,y,X,VV;
int val[NR], vz[NR], grad[NR], C[NR];
void BFS ()
{
    int i,j,k,urm;
    // vz[i] - daca sunt solutie
    // C[i]  - daca respecta conditia
    while (! q.empty())
    {
        k=q.front(); q.pop();
        sol.push_back(k);

        for (int i=0; i<v[k].size(); ++i)
            --grad[v[k][i]];

        if (val[k] > grad[k]) {
            for (i=0; i<v[k].size(); ++i)
                if (! vz[v[k][i]]) {
                    vz[v[k][i]]=1;
                    q.push(v[k][i]);
                }
        }

        for (i=0; i<v[k].size(); ++i) {
            urm=v[k][i];
            if (vz[urm] && ! C[urm] && val[urm] > grad[urm]) {
                C[urm]=1;
                for (j=0; j<v[urm].size(); ++j)
                    if (! vz[v[urm][j]]) {
                        vz[v[urm][j]]=1;
                        q.push(v[urm][j]);
                    }
            }
        }
    }
}
int main ()
{
    f>>n>>m>>X;
    for (i=1; i<=n; ++i)
        f>>val[i];

    for (i=1; i<=m; ++i) {
        f>>x>>y; ++grad[x]; ++grad[y];
        v[x].push_back(y);
        v[y].push_back(x);
    }

    //X
    val[X]=1000000;

    vz[X]=1; q.push(X);

    BFS();

    g<<sol.size()<<"\n";
    for (i=0; i<sol.size(); ++i)
        g<<sol[i]<<"\n";


    return 0;
}
