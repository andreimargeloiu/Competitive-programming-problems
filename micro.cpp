# include <cstdio>
# include <algorithm>
# include <set>
# define NR 100005
using namespace std;
struct elem {
    long long cost;
    int capacitate;
}E, a[NR], var[NR];
struct comp {
    bool operator () (const elem &x, const elem &y) {
        if (x.cost>=y.cost) return 0;
                       else return 1;
    }
};
int i,j,n,m,x,y,Bucati,X,V,OP;
int P[NR], CostP[NR], cerere[NR], D[NR], CostD[NR];
long long COST;
int main ()
{
    freopen ("micro.in", "r", stdin);
    freopen ("micro.out", "w", stdout);

    scanf ("%d", &n);
    for (i=1; i<=n; ++i) scanf ("%d%d%d", &P[i], &CostP[i], &cerere[i]);
    for (i=1; i<n; ++i) scanf ("%d%d", &D[i], &CostD[i]);

    multiset <elem, comp> M;

    for (i=1; i<=n; ++i) {
        E.cost=CostP[i]; E.capacitate=P[i]; M.insert (E); //punem produsele noi

        std::multiset <elem, comp> :: iterator it;

        V=0; Bucati=0;
        for (it=M.begin(); it!=M.end(); ++it) {
            E=*it;
            // satisfacem cererea
            if (cerere[i]) {
                if (cerere[i] >= E.capacitate) {
                    COST=COST + 1LL*E.capacitate*E.cost;
                    cerere[i]-=E.capacitate;

                    continue;
                }
                else if (cerere[i] < E.capacitate) {
                    COST=COST + 1LL*cerere[i]*E.cost;
                    E.capacitate-=cerere[i];
                    cerere[i]=0;

                }
            }
            if (! cerere[i]) {
                E.cost+=CostD[i];

                var[++V]=E; Bucati+=E.capacitate;

                if (Bucati>D[i]) {
                    var[V].capacitate=var[V].capacitate - (Bucati-D[i]);
                    Bucati=D[i];
                    break;
                }
                if (Bucati==D[i]) break;
            }
        }
        M.clear();
        for (j=1; j<=V; ++j)
            M.insert(var[j]);



        if (cerere[i]) {
            printf ("-1\n");
            return 0;
        }
    }

    printf ("%lld\n", COST);

    return 0;
}
