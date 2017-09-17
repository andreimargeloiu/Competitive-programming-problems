# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <bitset>
# define INF 999999999
# define DD 66000
# define NR 1005
# define F 20
using namespace std;
ifstream f("bigbrother.in");
ofstream g("bigbrother.out");
vector <int> v[F][NR];
int i,j,n,m,x,y,C,k,minn,stop;
int cost[F], COST[DD];
bitset <NR> DP[DD];
bitset <NR> biti;
void DFS (int k, int K) {
    DP[1<<K][k]=1;
    for (int i=0; i<v[K][k].size(); ++i)
        if (DP[1<<K][v[K][k][i]]==0)
            DFS (v[K][k][i], K);
}
void dinamica () {
    int i,k,ok; minn=INF;
    for (i=1; i<=stop; ++i) {
        ok=0;
        for (k=0; k<C; ++k)
            if (i & (1<<k)) { // vin din starea anterioara
                if (! ok) {ok=1; DP[i]=DP[(1<<k)] | DP[i-(1<<k)];}
                if (COST[i] > cost[k] + COST[i - (1<<k)]) {
                    COST[i] = cost[k] + COST[i - (1<<k)];
                }
            }
        if ((DP[i] & biti)==biti) {
           // g<<i<<" "<<COST[i]<<"\n";
           // g<<DP[i]<<"\n";
            minn=min(minn, COST[i]);
        }
    }
}
int main ()
{
    f>>n>>m>>C;
    for (i=0; i<C; ++i)
        f>>cost[i];

    for (i=1; i<=m; ++i) {
        f>>x>>y>>k; --k; --x; --y;
        v[k][x].push_back(y);
        v[k][y].push_back(x);
    }

    stop=(1<<(C+1))-1;
    for (i=0; i<=stop; ++i)
        COST[i]=INF;

    for (k=0; k<C; ++k) {
        //g<<k<<"\n"<<DP[(1<<k)]<<"\n";

        for (i=0; i<n; ++i)
            if (DP[(1<<k)][i]==0 && v[k][i].size())
            {
                DFS (i, k);
            }
       // g<<DP[(1<<k)]<<"\n";

        COST[(1<<k)]=cost[k];
    }
    for (i=0; i<n; ++i)
        biti[i]=1;
    //g<<biti<<"\n";
    dinamica ();

    g<<minn<<"\n";

    return 0;
}
