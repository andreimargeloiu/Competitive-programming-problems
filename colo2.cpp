# include <fstream>
# include <algorithm>
# include <cmath>
# include <vector>
# include <queue>
# define mp make_pair
# define NR 1505
# define inf 999999999
# define MOD 104659
# define dif 1e-10
using namespace std;
ifstream f("dmin.in");
ofstream g("dmin.out");
vector <pair <int, double> > v[NR];
queue <int> q;
int i,j,n,m,x,y;
int drumuri[NR], ap[NR];
double dist[NR], cost;
void BF ()
{
    int i,j,k,urm;
    double cost;

    for (i=2; i<=n; ++i) dist[i]=inf;
    q.push(1); drumuri[1]=1;
    while (! q.empty()) {
        k=q.front(); q.pop(); ap[k]=0;

        for (i=0; i<v[k].size(); ++i) {
            urm=v[k][i].first;
            cost=v[k][i].second;


            if (fabs(dist[k] + cost - dist[urm]) < dif) { // alte drumuri
                drumuri[urm]+=drumuri[k];

                if (!ap[urm]) {ap[urm]=1; q.push(urm);}
            }
            else if (dist[k] + cost + dif <= dist[urm]) { // un drum mai mic
                dist[urm]=dist[k] + cost;
                drumuri[urm]=drumuri[k];

                if (!ap[urm]) {ap[urm]=1; q.push(urm);}
            }

            if (drumuri[urm]>=MOD) drumuri[urm]-=MOD;
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y>>cost; int Q=cost;
        cost=log(cost);

        v[x].push_back(mp(y, cost));
        v[y].push_back(mp(x, cost));
    }
    BF ();

    for (i=2; i<=n; ++i)
        g<<drumuri[i]<<" ";
    g<<"\n";

    return 0;
}
